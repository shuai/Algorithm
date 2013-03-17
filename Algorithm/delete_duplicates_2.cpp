//
//  delete_duplicates_2.cpp
//  Algorithm
//
//  Created by Shuai on 1/30/13.
//
//

#include "include.h"

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        ListNode sentinel(0), *prev = &sentinel;
        sentinel.next = head;
        
        while (head) {
            if (head->next && head->val == head->next->val) {
                int val = head->val;
                while (head && head->val == val) {
                    ListNode* next = head->next;
                    delete head;
                    head = next;
                }
                prev->next = head;
            } else {
                prev = head;
                head = head->next;
            }
        }
        return sentinel.next;
    }
};