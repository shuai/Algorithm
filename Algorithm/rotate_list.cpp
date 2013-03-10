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
            return nullptr;
        
        ListNode* forward = nullptr;
        while (true) {
            int count = 0;
            forward = head;
            while (forward && count < k) {
                count ++;
                forward = forward->next;
            }
            
            if (count <= k && !forward)
                k %= count;
            else
                break;
        }
        
        if (k == 0)
            return head;
        
        ListNode* last = head;
        while (forward->next) {
            forward = forward->next;
            last = last->next;
        }
        
        forward->next = head;
        head = last->next;
        last->next = nullptr;
        return head;
    }
};