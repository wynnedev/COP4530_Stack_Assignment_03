#ifndef STACK_H
#define STACK_H

#include "List.h"

template <typename T>
class Stack : public List
{
    private:
        Stack();
        ~Stack();
        Stack(const Stack&);
        Stack(Stack&&);
        Stack& operator=(const Stack &);
        Stack& operator=(Stack&&);
        
        /// Return true if data structure contains 1 or more elements
        bool empty() const;
        
        /// Remove all elements of the data structure
        void clear();

        /// Adds T to the stack
        void push(const T& t);

        /// Adds T to the stack std::move(T)
        void push(T&& t);

        /// Removes and discards the most recently added element of the Stack
        void pop();

        /// returns a reference to the top element of the stack
        T& top();

        /// const: accessor that returns the most recently added element of the stack
        const T& top();

        /// returns the number of elements in the data structure
        int size();

        /// print stack from bottom to top
        void print(std::ostream& os, char ofc=' ') const;

    public:

};

#endif 