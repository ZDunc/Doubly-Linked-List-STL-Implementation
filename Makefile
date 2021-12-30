proj2.x: test_list.o List.h List.hpp
	g++ -o proj2.x test_list.o

test_list.o: test_list.cpp List.h List.hpp
	g++ -c -std=c++11 test_list.cpp

clean:
	rm -f proj2.x *.o
