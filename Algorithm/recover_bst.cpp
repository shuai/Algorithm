//
//  recover_bst.cpp
//  Algorithm
//
//  Created by Shuai on 2/3/13.
//
//

#include "include.h"

class Solution {
public:
    void recoverTree(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        TreeNode* prev = NULL, *first = NULL, *second = NULL;
        
        vector<TreeNode*> stack;
        while  (root || stack.size()) {
            if (root) {
                stack.push_back(root);
                root = root->left;
            } else {
                root = stack.back();
                stack.pop_back();
                if (prev && root->val < prev->val) {
                    if (!first)
                        first = prev;
                    second = root;
                }
                prev = root;
                root = root->right;
            }
        }
        
        if (first)
            swap(first->val, second->val);
    }
};