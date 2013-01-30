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
        
        ListNode sentinel(0), *prev = &sentinel, *start = head, *end = head;
        sentinel.next = head;
        
        while (end) {
            if (end->val == start->val)
                end = end->next;
            
            if (!end || end->val != start->val) {
                if (start->next != end) {
                    prev->next = end;
                    while (start != end) {
                        ListNode* next = start->next;
                        delete start;
                        start = next;
                    }
                } else {
                    prev = start;
                    start = end;
                }
            }
        }
        
        return sentinel.next;
    }
};