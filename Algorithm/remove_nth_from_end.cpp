//
//  remove_nth_from_end.cpp
//  Algorithm
//
//  Created by Shuai on 3/4/13.
//
//

#include "include.h"

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        ListNode* first = head, *second = head, sentinel(0), *prev = &sentinel;
        sentinel.next = head;
        
        while (n--) {
            first = first->next;
        }
        
        while (first) {
            first = first->next;
            prev = second;
            second = second->next;
        }
        
        prev->next = second->next;
        delete second;
        return sentinel.next;
    }
};