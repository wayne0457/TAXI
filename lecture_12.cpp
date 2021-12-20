//stack.cpp you may find stack.h at the bottom 
#include <iostream>
#include <stdlib.h>
#include "stack.h"
using namespace std;

/*  Re-write your Lab 8-2 using C++ class
 *  Put all of your member function definitions here
 *  Do not omit the destructor
 */


stack_t::stack_t(int size){
    top = 0;
    max_size = size;
    head = (int*) malloc (size * sizeof(int));
}
void stack_t::dynamic_push(int n){
    if (top + 1 > max_size) {
        head[top] = *new int[top];
        max_size = 2 * max_size;
    }
    head[top] = n;
    ++ top;
}

int stack_t::dynamic_pop(){
    if (top != 0) {
        if (top < max_size / 4) {
            max_size = max_size / 2;
        }
        return head[--top];
    } else {
        cout << "\nPopping empty stack!\n";
        exit(1);
    }
}

void stack_t::show(){
    cout << "Stack contains "<< top << " element(s)\n";
    for (int i = 0; i < top; ++i) {
        cout << head[i];
        if (i != top - 1) {
            cout << ' ';
        }
    }
    cout << "\ntop = " << top << " max_size = " << max_size << "\n";
}

stack_t::~stack_t(){
    delete [] head;
}

//stack.h


#ifndef STACK_H
#define STACK_H

class stack_t {
public:
    stack_t(int size);
    void dynamic_push(int n);
    int dynamic_pop();
    void show();
    ~stack_t();
private:
    int* head;
    int top;
    int max_size;
};

#endif
