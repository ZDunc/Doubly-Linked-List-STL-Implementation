test.x: test.o List.h List.hpp
	g++ -o test.x test.o

test.o: test.cpp List.h List.hpp
	g++ -c -std=c++11 test.cpp

clean:
	rm -f test.x *.o
