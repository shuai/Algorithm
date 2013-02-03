//
//  sorted_list_to_bst.cpp
//  Algorithm
//
//  Created by Shuai on 2/3/13.
//
//

#include "include.h"

class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        ListNode* pos = head;
        int count = 0;
        while (pos) {
            count ++;
            pos = pos->next;
        }
        
        return build(head, count, pos);
    }
    
    TreeNode* build(ListNode* head, int count, ListNode* &tail) {
        if (!count)
            return NULL;
        int left_count = count/2;
        int right_count = count-count/2-1;
        
        ListNode *root = head;
        TreeNode *left = build(head, left_count, root);
        
        TreeNode* root_node = new TreeNode(root->val);
        root_node->left = left;
        tail = root->next;
        root_node->right = build(root->next, right_count, tail);
        return root_node;
    }
};