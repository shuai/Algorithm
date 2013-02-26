//
//  flatten_bst.cpp
//  Algorithm
//
//  Created by Shuai on 2/26/13.
//
//


#include "include.h"

class Solution {
public:
    void flatten(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (!root)
            return;
        
        TreeNode* prev = NULL;
        vector<TreeNode*> stack;
        stack.push_back(root);
        while (stack.size()) {
            TreeNode* current = stack.back();
            stack.pop_back();
            
            if (current->right)
                stack.push_back(current->right);
            if (current->left)
                stack.push_back(current->left);
            
            if (prev)
                prev->right = current;
            prev = current;
            prev->left = NULL;
            
        }
    }
};