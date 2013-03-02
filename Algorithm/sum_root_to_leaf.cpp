//
//  sum_root_to_leaf.cpp
//  Algorithm
//
//  Created by Shuai on 2/26/13.
//
//

#include "include.h"

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int sumNumbers(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (!root)
            return 0;
        return sumNumbers(root, 0);
    }
    
    int sumNumbers(TreeNode* root, int prefix) {
        prefix = prefix*10 + root->val;
        
        if (!root->left && !root->right)
            return prefix;
        
        int sum = 0;
        if (root->left)
            sum += sumNumbers(root->left, prefix);
        if (root->right)
            sum += sumNumbers(root->right, prefix);
        return sum;
    }
};