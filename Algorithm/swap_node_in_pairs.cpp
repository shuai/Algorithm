//
//  swap_node_in_pairs.cpp
//  Algorithm
//
//  Created by Shuai on 3/4/13.
//
//

#include "include.h"

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        ListNode sentinel(0), *prev = &sentinel;
        sentinel.next = head;
        
        while (head && head->next) {
            ListNode* next = head->next->next;
            head->next->next = head;
            prev->next = head->next;
            prev = head;
            head = head->next = next;
        }
        
        return sentinel.next;
    }
};