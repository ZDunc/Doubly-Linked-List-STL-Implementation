# Doubly Linked List (STL Style) Implementation

### PROGRAM DESCRIPTION -- Implementation of aemplated (doubly) linked list class. Additionally, implement an associated iterator class to help with generic container traversals.

## DOUBLY LINKED LIST CLASS --

### Member functions of List class template 
-----------------------------------------------------------------------------------------------------

List()
- 0 parameter default constructor, which calls init() for proper initialization of list member variables

List(const List &rhs)
- Copy constructor, which creates a new list identical to List rhs

List(List &&rhs) 
- Move constructor (for efficiency -- "steal" the resources held by a List that is about to be destroyed by the compiler, rather than creating a copy of it)

List(int num, const T & val = T())
- ADDITIONAL CONSTRCUTOR, creates a List of size num with ALL elements initialized to value val

List(const_iterator start, const_iterator end)
- ADDITIONAL CONSTRUCTOR, creates a List with elements from an ALREADY_EXISTING list, btwn a start element and end element of that provided list (function expects two const_iterator objects to determine these start & end elements). Includes the element referred to by the start iterator, but NOT the end iterator: [start, end)

List(std::initializer_list<T> iList)
- ADDITIONAL CONSTRUCTOR, creates a List with elements from a provided initializer list. Allows declarations such as below:
     List<int> newList {3, 6, 9, 12, 15, 18, 21, 24};
  
~List()
- DESTRUCTOR, must properly release all dynamically-allocated memory

operator=(List &rhs) 
- copy assignment operator

operator=(List &&rhs) 
- move assignment operator (for greater program efficiency)

operator=(std::initializer_list<T> iList) 
- Assigns an initializer list of T data to be the new of data of a calling object
     I.e.
           example_list = {0, 2, 4, 6, 8, 10, 12, 14};
  
size()
- Return List size, or num of elements

empty()
- If no elements in List, return true; else, return false

clear() 
- DELETE all list elements

reverse() 
- reverse the order of a List object

front()
- return reference to the FIRST element in a List object
     
 back()
- return reference to LAST element in a List object

push_front() 
- insert new object as the FIRST element in a List object

push_front(T && val)     
- MOVE VERSION of push_front()
     
push_back()
- insert new object as the LAST element in a List object

push_front(T && val)     
- MOVE VERSION of push_back()

pop_front() 
- delete the FIRST element in a List object

pop_back()
- delete the LAST element in a List object

remove(const T & val)
- delete ALL nodes with value val from a List object

remove_if(PREDICATE pred)
- delete ALL nodes for which PREDICATE pred returns true. 
     - PREDICATE is a template type, allowing a FUNCTION OBJECT to be passed as a parameter (This might include true/false conditions or others functions passed in        via the functor)

print(ostream &os, char ofc = ' ')
- prints a List object, from first element to last element. Char ofc is the deliminator btwn List elements, dependent upon valid operator overloading

begin()
- Returns an ITERATOR to the FIRST element in a List object

end()
- return an ITERATOR to the MARKER of a List object (the TAIL)

insert(iterator itr, const T & val)
- Inserts a value val IN FRONT OF of the node referred to by iterator itr

insert(iterator itr, T && val)
- MOVE VERSION OF insert()
     
erase(iterator itr)
- Delete the node referred to by iterator itr. Returns the FOLLOWING node

erase(iterator start, iterator end)
- Delete ALL nodes btwn start and end (including start but NOT end) as read by iterator arguments

init()
- Helper function to INITIALIZE member variables of a List
     

### NON-CLASS FUNCS --
-----------------------------------------------------------------------------------------------------

operator==(const List<T> & lhs, const List<T> & rhs)
- check if two lists contain the same sequence of elements. Two lists are equal if they have the same number of elements and the elements at the corresponding position are equal.

operator!=(const List<T> & lhs, const List<T> & rhs)
- opposite of operator==().

operator<<(ostream & os, const List<T> & l)
- print out all elements in list l by calling List<T>::print() function. 
     

### NESTED ITERATOR CLASSES --
-----------------------------------------------------------------------------------------------------

### Member funcs of nested const_iterator class:

const_iterator()
- 0 parameter default constructor, which sets ptr current to null

operator*()
- REFERENCE OPERATOR OVERLOAD, implementated to facilitate functionality of retrieve() member func

operator++(int), operator++(), operator--(int), operator--()
- prefix and postfix increment and decrement OPERATOR OVERLOADS

operator==() and operator!=()
- equal and not equal OPERATOR OVERLOADS

retrieve()
- returns a REFERENCE the corresponding list element

const_iterator(Node *p)
- ADDITIONAL CONSTRUCTOR of 1 parameter, which set ptr current to provided node ptr p

     
### Member funcs of nested iterator class:

iterator()
- 0 parameter default constructor

operator*()
- REFERENCE OPERATOR OVERLOAD, implementated to facilitate functionality of retrieve() member func

operator++(), operator++(int), operator--(), operator--(int): 
- prefix and postfix increment and decrement OPERATOR OVERLOADS

iterator(Node *p): 
- ADDITIONAL CONSTRUCTOR of 1 parameter


     

## REPOSITORY CONTENTS
- List.h
- List.hpp
- driver.cpp
- makefile
- analysis.txt
