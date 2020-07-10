list : stack_test.o 
	-g++ -o stack_test stack_test.o 

stack_test.o : stack_test.cpp Stack.h
	-g++ -c -std=c++14 stack_test.cpp

clean : 
	rm list *.o