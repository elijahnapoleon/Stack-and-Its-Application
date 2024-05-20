#ifndef COP4530_STACK_H
#define COP4530_STACK_H

#include <iostream>
#include <stdexcept> 

namespace cop4530
{

template <typename T>
class Stack
{
    public:
    Stack(); 
~Stack(); 
Stack(const Stack<T> &); 
Stack(Stack<T> &&); 
Stack& operator=(const Stack<T> &); 
Stack& operator=(Stack<T> &&); 
bool empty() const; 
void clear();
T& top(); 
const T& top() const; 
void pop(); 
void push(const T& x); 
void push(T&& x); 
int size() const; 
void reserve(int newCapacity);
void print(std::ostream& os, char ofc = ' ') const;

private:
int theSize;
int theCapacity;
T* array;

void doubleCapacity();

};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Stack<T>& a);

template <typename T>
bool operator==(const Stack<T>&, const Stack<T>&);

template <typename T>
bool operator!=(const Stack<T>&,const Stack<T>&);

template <typename T>
bool operator<=(const Stack<T>& a, const Stack<T>& b);


#include "stack.hpp"
}
#endif