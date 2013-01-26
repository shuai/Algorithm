//
//  list.cpp
//  Algorithm
//
//  Created by Shuai on 9/7/12.
//
//

#include "list.h"
#include "test.h"


ListNode* nth_last(ListNode* list, unsigned n)
{
    if (!list || !n) {
        return NULL;
    }
    
    ListNode* first = list, *second = list;
    while (--n && first->next) {
        first = first->next;
    }
    
    if (n)
        return NULL;
    
    while (first->next) {
        first = first->next;
        second = second->next;
    }
    
    return second;
}

void test_nth_last()
{
    ListNode* list = build_list();
    for (int i=0; i<15; i++) {
        ListNode* node = nth_last(list, i);
        if (node)
            cout << i << "th last element is " << node->key << endl;
        else
            cout << i << "th last element is none" << endl;
    }
}

ListNode* find_circle_beginning(ListNode* node)
{
    if (!node) {
        return NULL;
    }
    
    ListNode* ptr1 = node, *ptr2 = node;
    while (ptr2) {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
        if (ptr2)
        {
            ptr2 = ptr2->next;
            if (ptr2 == ptr1)
                break;
        }
        else
            break;
    }
    
    if (!ptr2)
        return NULL;
    
    ptr2 = node;
    while (ptr1 != ptr2) {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    
    return ptr1;
}

void test_list_circle()
{
    ListNode* list = build_circular_list();
    cout << "Beginning of list :" << find_circle_beginning(list)->key << endl;
}
