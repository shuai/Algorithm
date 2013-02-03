//
//  inorder_traversal.cpp
//  Algorithm
//
//  Created by Shuai on 2/2/13.
//
//

#include "include.h"

class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        vector<int> result;
        
        vector<TreeNode*> stack;
        while (root || stack.size()) {
            if (root) {
                stack.push_back(root);
                root = root->left;
            } else {
                root = stack.back();
                stack.pop_back();
                result.push_back(root->val);
                root = root->right;
            }
        }
        return result;
    }
};