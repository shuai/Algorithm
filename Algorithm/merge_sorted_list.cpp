//
//  merge_sorted_list.cpp
//  Algorithm
//
//  Created by Shuai on 2/10/13.
//
//

#include "include.h"

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        ListNode sentinel(0), *tail = &sentinel;
        
        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail = tail->next = l1;
                l1 = l1->next;
            } else {
                tail = tail->next = l2;
                l2 = l2->next;
            }
        }
        
        if (l1)
            tail->next = l1;
        else
            tail->next = l2;
        return sentinel.next;
    }
};