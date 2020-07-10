#ifndef STACK_H
#define STACK_H

#include "List.h"

template <typename T>
class Stack
{
    public:
        Stack(){};
        ~Stack(){};
        Stack(const Stack& s ) 
        { 
            _stack = s._stack;
        }
        Stack(Stack&& s){ _stack = s._stack;}
        Stack& operator=(const Stack &s) { _stack = s; return _stack;}
        Stack& operator=(Stack&& s) { _stack = s; return _stack;}
        
        /// Return true if data structure contains 1 or more elements
        bool empty() const {return _stack->empty();}
        
        /// Remove all elements of the data structure
        void clear(){_stack->clear();}

        /// Adds T to the stack
        void push(const T& t){_stack->push_back(t);}

        /// Adds T to the stack std::move(T)
        void push(T&& t){_stack->push_back(t);}

        /// Removes and discards the most recently added element of the Stack
        void pop(){_stack->pop_back();}

        /// returns a reference to the top element of the stack
        T& top(){return _stack->back();}

        /// const: accessor that returns the most recently added element of the stack
        const T& top() const{return _stack->back();}

        /// returns the number of elements in the data structure
        int size(){return _stack->size();}

        /// print stack from bottom to top
        void print(std::ostream& os, char ofc=' ') const
        {
            //_stack->reverse();
            _stack->print(os, ofc);
        }

        void reverse()
        {
            _stack->reverse();
        }

    private:
    cop4530::List<T> *_stack = new cop4530::List<T>();

};
template <typename T>
std::ostream& operator<<(std::ostream&os, const Stack<T>& stack)
{
    stack.print(os, ' ');
}

template <typename T>
bool operator==(const Stack<T>& stackA, const Stack<T>& stackB)
{
    return stackA == stackB;
}

template <typename T>
bool operator!=(const Stack<T>& stackA, const Stack<T>& stackB)
{
    return stackA != stackB;
}

template <typename T>
bool operator<=(const Stack<T>& stackA, const Stack<T>& stackB)
{
    Stack<T> stack_A = stackA;
    Stack<T> stack_B = stackB;

    while(!stack_A.empty())
    {
        if(stack_A.top() >= stack_B.top())
        {
            return false;
        }

        stack_A.pop();
        stack_B.pop();
    }
}

#endif 