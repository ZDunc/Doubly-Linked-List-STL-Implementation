// Zach Duncan

#ifndef _LIST_HPP
#define _LIST_HPP

////////////////////CLASS List<T>::const_iterator DEFINITIONS/////////////////////

// default zero parameter constructor
template <typename T>
List<T>::const_iterator::const_iterator() : current{ nullptr }
{}

// operator*() to return element
template <typename T>
const T& List<T>::const_iterator::operator*() const
{ return retrieve(); }

// INCREMENT & DECREMENT OPERATORS
// Prefix increment
template <typename T>
typename List<T>::const_iterator& List<T>::const_iterator::operator++()
{
  current = current->next;
  return *this;
}

// Postfix increment
template <typename T>
typename List<T>::const_iterator List<T>::const_iterator::operator++(int)
{
  const_iterator old = *this;
  ++( *this );
  return old;
}

// Prefix decrement
template <typename T>
typename List<T>::const_iterator& List<T>::const_iterator::operator--()
{
  current = current->prev;
  return *this;
}

// Postfix decrement
template <typename T>
typename List<T>::const_iterator List<T>::const_iterator::operator--(int)
{
  const_iterator old = *this;
  --( *this );
  return old;
}

// comparison operators
template <typename T>
bool List<T>::const_iterator::operator==(const const_iterator &rhs) const
{ return current == rhs.current; }

template <typename T>
bool List<T>::const_iterator::operator!=(const const_iterator &rhs) const
{ return !( *this == rhs ); }

//PROTECTED FUNCTIONS//
template <typename T>
T& List<T>::const_iterator::retrieve() const       // retrieve the element refers to
{ return current->data; }

template <typename T>
List<T>::const_iterator::const_iterator(Node *p) : current{p}   // protected constructor
{}

////////////////////////CLASS List<T>::iterator DEFINITIONS///////////////////////

template <typename T>
List<T>::iterator::iterator() {}     //current = nullptr in parent class

template <typename T>
T& List<T>::iterator::operator*()
{ return const_iterator::retrieve( ); }  //override parent implementation

template <typename T>
const T& List<T>::iterator::operator*() const
{ return const_iterator::operator*( ); } //override parent implemenation

// INCREMENT & DECREMENT OPERATORS
// Prefix increment
template <typename T>
typename List<T>::iterator& List<T>::iterator::operator++()    //override parent
{
  this->current = this->current->next;
  return *this;
}

// Postix increment
template <typename T>
typename List<T>::iterator List<T>::iterator::operator++(int)  //override parent
{
  iterator old = *this;
  ++( *this );
  return old;
}

// Prefix decrement
template <typename T>
typename List<T>::iterator& List<T>::iterator::operator--()    //override parent
{
  this->current = this->current->prev;
  return *this;
}

// Postfix decrement
template <typename T>
typename List<T>::iterator List<T>::iterator::operator--(int)  //override parent
{
  iterator old = *this;
  --( *this );
  return old;
}

//PROTECTED FUNCTION//
template <typename T>
List<T>::iterator::iterator(Node *p) : const_iterator{ p }
{}

////////////////////////////CLASS List<T> DEFINITIONS////////////////////////////

// constructor, desctructor, copy constructor
template <typename T>
List<T>::List()                 // default zero parameter constructor
{ init(); }

template <typename T>
List<T>::List(const List &rhs)   // copy constructor
{
  init();
  for ( auto& x : rhs)
    push_back(x);
}

template <typename T>
List<T>::List(List && rhs) : theSize{rhs.theSize}, head{rhs.head}, tail{rhs.tail}
// move constructor
{
  rhs.theSize = 0;
  rhs.head = nullptr;
  rhs.tail = nullptr;
}

// num elements with value of val
template <typename T>
List<T>::List(int num, const T& val)
{
  init();
  for (int i = 0; i < num; i++)       //Insert num elements into back of list
    push_back(val);
}

// constructs with elements [start, end)
template <typename T>
List<T>::List(const_iterator start, const_iterator end)
{
  init();
  while (start != end)               //While we have not reached end itr
  {
    push_back(start.current->data);  //insert data element of start (current)
    start++;                         //Increment start (current)
  }
}

// constructs with a copy of each of the elements in the initalizer_list
template <typename T>
List<T>::List(std::initializer_list<T> iList)
{
  init();
  auto itr = iList.begin();          //Begin itr
  auto bitr = iList.end();           //End itr

  while (itr != bitr)                //While we have not reached end of list
  {
    push_back(*itr);                 //Insert data at itr to end of list
    itr++;                           //Increment iterator
  }
}

template <typename T>
List<T>::~List() // destructor
{
  clear();
  delete head;
  delete tail;
}

// copy assignment operator
template <typename T>
const List<T>& List<T>::operator=(const List &rhs)
{
  List copy = rhs;
  std::swap(*this, copy);
  return *this;
}

// move assignment operator
template <typename T>
List<T>& List<T>::operator=(List && rhs)
{
  std::swap( theSize, rhs.theSize );
  std::swap( head, rhs.head );
  std::swap( tail, rhs.tail );

  return *this;
}

// sets list to the elements of the initializer_list
template <typename T>
List<T>& List<T>::operator=(std::initializer_list<T> iList)
{
  clear();                    //Same code as initializer_list constructor,
  auto itr = iList.begin();   //BUT clear this list first
  auto bitr = iList.end();

  while (itr != bitr)
  {
    push_back(*itr);
    itr++;
  }
}

// member functions
template <typename T>
int List<T>::size() const       // number of elements
{ return theSize; }

template <typename T>
bool List<T>::empty() const     // check if list is empty
{ return size() == 0; }

template <typename T>
void List<T>::clear()          // delete all elements
{
  while (theSize > 0)        //Traverse through linked list
    pop_front();
}

template <typename T>
void List<T>::reverse()                 //Reverse the order of the elements
{
  //Get iterator to traverse List
  auto itr = begin();                   //Get an iterator at beginning of list
  List<T> temp;                         //Temp list
  while (itr.current->next != nullptr)
  {
    temp.push_front(itr.current->data); //Insert this list's itr and front of temp
    itr++;                              //Advance iterator
  }
  *this = temp;                         //Put contents of temp into *this
}

template <typename T>
T& List<T>::front()            // reference to the first element
{ return *begin(); }

template <typename T>
const T& List<T>::front() const
{ return *begin(); }

template <typename T>
T& List<T>::back()              // reference to the last element
{ return *--end(); }

template <typename T>
const T& List<T>::back() const
{ return *--end(); }

template <typename T>
void List<T>::push_front(const T & val) // insert to the beginning
{ insert( begin(), val); }

template <typename T>
void List<T>::push_front(T && val)      // move version of insert
{ insert( begin(), std::move(val) ); }

template <typename T>
void List<T>::push_back(const T & val)  // insert to the end
{ insert( end(), val ); }

template <typename T>
void List<T>::push_back(T && val)       // move version of insert
{ insert( end(), std::move(val) ); }

template <typename T>
void List<T>::pop_front()               // delete first element
{ erase( begin() ); }

template <typename T>
void List<T>::pop_back()                // delete last element
{ erase( --end() ); }

template <typename T>
void List<T>::remove(const T &val)      // remove all elements with value = val
{
  auto itr = begin();                 //Get an iterator at beginning of list
  while (itr.current != tail)         //Traverse through linked list
  {
    if (itr.current->data == val)     //If data matches given value
    {
      erase(itr);                     //Delete that node, return next iterator
      continue;
    }
    itr++;                            //Update iterator to next
  }
}

template <typename T>
template <typename PREDICATE>
void List<T>::remove_if(PREDICATE pred)	// remove all elements for which Predicate pred
                                    //  returns true. pred can take in a function object
{
  auto itr = begin();                 //Iterator to beginning of List<T>
  auto ritr = end();                  //Iterator to end of List<T>

  while (itr != ritr)                 //While beginning is not end
  {
    if (pred(*itr))                   //Check if PREDICATE is true
    {
      itr = erase(itr);               //If it is erase that itr and continue
      continue;
    }
    itr++;                            //Increment iterator
  }
}

// print out all elements. ofc is delimiter
template <typename T>
void List<T>::print(std::ostream& os, char ofc) const
{
  //Use iterator
  if (theSize == 0)                     //If nothing to print
      os << "";
  else
  {
    auto itr = begin();
    while (itr.current != tail)         //Traverse through linked list
    {
      os << (itr.current)->data << ofc;
      itr++;                            //Update iterator to next
    }
  }
}

template <typename T>
typename List<T>::iterator List<T>::begin()               // iterator to first element
{ return iterator( head->next );  }

template <typename T>
typename List<T>::const_iterator List<T>::begin() const
{ return const_iterator( head->next );  }

template <typename T>
typename List<T>::iterator List<T>::end()                 // end marker iterator
{ return iterator(tail); }

template <typename T>
typename List<T>::const_iterator List<T>::end() const
{ return const_iterator(tail); }

template <typename T>
typename List<T>::iterator List<T>::insert(iterator itr, const T& val)  // insert val ahead of itr
{
  Node *p = itr.current;
  ++theSize;
  return iterator( p->prev = p->prev->next = new Node{ val, p->prev, p } );
}

template <typename T>
typename List<T>::iterator List<T>::insert(iterator itr, T && val)      // move version of insert
{
  Node *p = itr.current;
  ++theSize;
  return iterator( p->prev = p->prev->next = new Node{ std::move( val ), p->prev, p } );
}

template <typename T>
typename List<T>::iterator List<T>::erase(iterator itr)                 // erase one element
{
  Node *p = itr.current;                     //p points to current Node
  iterator retVal( p->next );                //retVal points to next Node
  p->prev->next = p->next;                   //Update prev->next
  p->next->prev = p->prev;                   //Update next->prev
  delete p;                                  //Delete node at pointer p
  --theSize;                                 //Decrement size
  return retVal;                             //Return iterator AFTER deleted itr
}

template <typename T>
typename List<T>::iterator List<T>::erase(iterator start, iterator end) // erase [start, end)
{
  for( iterator itr = start; itr != end; )
    itr = erase( itr );

  return end;
}

template <typename T>
void List<T>::init()           // initialization
{
  theSize = 0;
  head = new Node;
  tail = new Node;
  head->next = tail;
  tail->prev = head;
}

/////////////////////////////STAND ALONE DEFINITIONS////////////////////////////

template <typename T>
bool operator==(const List<T> & lhs, const List<T> &rhs)
{
  if (lhs.size() != rhs.size())
    return false;
  else
  {
    auto l_itr = lhs.begin();
    auto l_ritr = lhs.end();
    auto r_itr = rhs.begin();
    while (l_itr != l_ritr)   //Traverse through linked list
    {
      if (*l_itr != *r_itr)
        return false;
      l_itr++;                //Update lhs iterator to next
      r_itr++;                //Update rhs iterator to next
    }
    return true;              //True if made it through while loop
  }
}

template <typename T>
bool operator!=(const List<T> & lhs, const List<T> &rhs)
{
  if (lhs.size() != rhs.size())
    return true;
  else
  {
    auto l_itr = lhs.begin();
    auto l_ritr = lhs.end();
    auto r_itr = rhs.begin();
    while (l_itr != l_ritr)   //Traverse through linked list
    {
      if (*l_itr != *r_itr)
        return true;
      l_itr++;                //Update lhs iterator to next
      r_itr++;                //Update rhs iterator to next
    }
    return false;             //False if made it through while loop
  }
}

// overloading output operator
template <typename T>
std::ostream & operator<<(std::ostream &os, const List<T> &l)
{
  l.print(os);                //Call List<T> print function to do work
  return os;
}

#endif
