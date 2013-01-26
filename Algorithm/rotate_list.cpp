//
//  rotate_list.cpp
//  Algorithm
//
//  Created by Shuai on 1/24/13.
//
//

#include "include.h"

class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (!head)
            return head;
        
        ListNode* ptr1 = head, *ptr2 = head;
        int len=0;
        while (ptr1) {
            len++;
            ptr1 = ptr1->next;
        }
        
        ptr1 = head;
        k %= len;
        
        while (k--) {
            ptr2 = ptr2->next;
        }
        
        while (ptr2 && ptr2->next) {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        
        ptr2->next = head;
        head = ptr1->next;
        ptr1->next = NULL;
        return head;
    }
};