//
//  reverse_list.cpp
//  Algorithm
//
//  Created by Shuai on 2/2/13.
//
//

#include "include.h"

class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        ListNode sentinel(0), *previous = &sentinel, *current = head;
        sentinel.next = head;
        
        n -= m;
        while (m-- > 1 && current) {
            previous = current;
            current = current->next;
        }
        
        if (!current || !current->next)
            return sentinel.next;
        
        ListNode* tail = current, *next = current->next;
        
        while (n-- > 0 && current && next) {
            ListNode* new_next = next->next;
            next->next = current;
            current = next;
            next = new_next;
        }
        
        tail->next = next;
        previous->next = current;
        return sentinel.next;
    }
};