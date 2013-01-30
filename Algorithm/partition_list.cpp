//
//  partition_list.cpp
//  Algorithm
//
//  Created by Shuai on 1/30/13.
//
//

#include "include.h"

class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        ListNode lesser(0), *lesser_tail = &lesser, greater(0), *greater_tail = &greater;
        
        while (head) {
            if (head->val < x)
                lesser_tail = lesser_tail->next = head;
            else
                greater_tail = greater_tail->next = head;
            head = head->next;
        }
        
        lesser_tail->next = greater.next;
        greater_tail->next = NULL;
        return lesser.next;
    }
};