//
//  reverse_k-group.cpp
//  Algorithm
//
//  Created by Shuai on 3/4/13.
//
//

#include "include.h"

class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        ListNode* current = head, sentinel(0), *prev = &sentinel;
        sentinel.next = head;
        
        while (current) {
            ListNode* tail = current, *head = nullptr;
            
            int count = 0;
            while (current && count < k) {
                ListNode* next = current->next;
                current->next = head;
                head = current;
                current = next;
                count ++;
            }
            
            if (count == k) {
                prev->next = head;
                tail->next = current;
                prev = tail;
            } else {
                current = head;
                k = count;
            }
        }
        return sentinel.next;
    }
};