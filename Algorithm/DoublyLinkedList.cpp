//
//  DoublyLinkedList.cpp
//  Algorithm
//
//  Created by  on 7/22/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
using namespace std;

class DoubleLinkedList
{
public:
    struct Node
    {
        int value;
        unsigned long bipointer;
    };
    
    DoubleLinkedList():head(NULL), tail(NULL) {}
    ~DoubleLinkedList();
    
    void iterate(bool reverse=false);
    void push_front(int value);
    void push_back(int value);
    
private:
    DoubleLinkedList(const DoubleLinkedList&);
    const DoubleLinkedList& operator = (const DoubleLinkedList&);
    
    Node* head;
    Node* tail;
};

DoubleLinkedList::~DoubleLinkedList()
{
    unsigned long previous = NULL;
    while (head)
    {
        Node* next = reinterpret_cast<Node*>(head->bipointer ^ previous);
        previous = reinterpret_cast<unsigned long>(head);
        
        delete head;
        head = next;
    }
    tail = NULL;
}


void DoubleLinkedList::iterate(bool reverse)
{
    Node* node = reverse ? tail : head;
    
    cout << "Iterating " << (reverse ? "reversely" : "");
    unsigned long previous = NULL;
    while (node)
    {
        cout << " " << node->value;
        Node* next = reinterpret_cast<Node*>(node->bipointer ^ previous);
        previous = reinterpret_cast<unsigned long>(node);
        node = next;
    }
    cout << endl;
}

void DoubleLinkedList::push_back(int value)
{
    Node* node = new Node;
    if (!node)
        return;
    
    node->value = value;
    node->bipointer = reinterpret_cast<unsigned long>(tail);
    
    if (tail)
        tail->bipointer ^= reinterpret_cast<unsigned long>(node);
    tail = node;
    if (!head)
        head = node;
}

void DoubleLinkedList::push_front(int value)
{
    Node* node = new Node;
    if (!node)
        return;
    
    node->value = value;
    node->bipointer = reinterpret_cast<unsigned long>(head);
    
    if (head)
        head->bipointer ^= reinterpret_cast<unsigned long>(node);
    head = node;
    if (!tail)
        tail = node;
}

void test_dbl_linked_list()
{
    DoubleLinkedList list;
    list.push_back(2);
    list.push_front(3);
    list.push_front(4);
    list.push_back(6);
    
    list.iterate();
    list.iterate(true);
}

