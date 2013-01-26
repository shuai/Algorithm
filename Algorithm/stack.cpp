//
//  stack.cpp
//  Algorithm
//
//  Created by Shuai on 9/9/12.
//
//

#include <cassert>
#include <iostream>

using namespace std;

class stackwithmin
{
public:
    stackwithmin(unsigned size);
    int pop();
    int min();
    void push(int);
    int peek() { return *(stack - 1); }
    bool isEmpty() { return stack == array; }
private:
    int *array;
    unsigned size;
    int *stack;
    int *minstack;
};

stackwithmin::stackwithmin(unsigned s)
{
    size = s;
    array = new int[size];
    stack = array;
    minstack = array + size;
}

int stackwithmin::pop()
{
    assert(stack>array);
    if (stack>array) {
        int key = *(stack - 1);
        stack--;
        if (key == *minstack)
            minstack ++;
        return key;
    }
    return -1;
}

void stackwithmin::push(int key)
{
    if (stack == minstack) {
        return;
    }
    
    if (stack + 1 == minstack && key <= *minstack)
        return;
    
    *stack++ = key;
    if (minstack == array + size || key <= *minstack ) {
        minstack --;
        *minstack = key;
    }
}

int stackwithmin::min()
{
    if (stack > array) {
        return *minstack;
    }
    return -1;
}


void sort_with_stacks(stackwithmin& stack)
{
    stackwithmin another(100);
    
    while (!stack.isEmpty()) {
        int top = stack.pop();
        cout << "stack 1 pop " << top << endl;
                
        while (!another.isEmpty() && another.peek() > top) {
            
            cout << "stack 1 push back " << another.peek() << endl;

            stack.push(another.pop());
            

        }
        
        cout << "stack 2 push " << top << endl;

        another.push(top);
    }
    
    while (!another.isEmpty()) {
        cout << " " << another.pop();
    }
    cout << endl;
}

void test_stackwithmin()
{
    stackwithmin sm(10);
    
    sm.push(5);
    
    cout << "current min:" << sm.min() << endl;

    sm.push(2);
    
    cout << "current min:" << sm.min() << endl;
    
    sm.push(1);
    sm.push(10);
    sm.push(1);
    
    sm.push(6);
    
    cout << "current min:" << sm.min() << endl;

    cout << "pop " << sm.pop() << endl;
    
    sm.push(-2);
    
    cout << "current min:" << sm.min() << endl;

    cout << "pop " << sm.pop() << endl;
    
    cout << "current min:" << sm.min() << endl;

    cout << "pop " << sm.pop() << endl;
    
    cout << "current min:" << sm.min() << endl;

    cout << "pop " << sm.pop() << endl;

    cout << "current min:" << sm.min() << endl;

    cout << "pop " << sm.pop() << endl;
    
    cout << "current min:" << sm.min() << endl;
 

    stackwithmin smsort(100);
    smsort.push(5);
    smsort.push(8);
    smsort.push(1);
    smsort.push(10);
    smsort.push(0);
    
    sort_with_stacks(smsort);
}
