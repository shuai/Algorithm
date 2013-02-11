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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution2 {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (!head)
            return NULL;
        
        if (m >= n)
            return head;
        
        ListNode sentinel(0), *prev = &sentinel;
        sentinel.next = head;
        
        for (int pos=1; pos<m; pos++) {
            prev = head;
            head = head->next;
        }
        
        ListNode* sub_tail = head, *sub_head = head, *next = head->next;
        for (int i=0; i<n-m && next; i++) {
            ListNode* current = next;
            next = next->next;
            current->next = sub_head;
            sub_head = current;
        }
        
        prev->next = sub_head;
        sub_tail->next = next;
        return sentinel.next;
    }
};