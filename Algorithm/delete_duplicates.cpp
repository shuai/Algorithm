//
//  delete_duplicates.cpp
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
        
        ListNode* ptr = head, *pos = head ? head->next : 0;
        while (pos) {
            if (pos->val == ptr->val) {
                ptr->next = pos->next;
                delete pos;
                pos = ptr->next;
            }
            else {
                ptr = pos;
                pos = pos->next;
            }
        }
        
        return head;
    }
};