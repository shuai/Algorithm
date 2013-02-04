//
//  balanced_bst.cpp
//  Algorithm
//
//  Created by Shuai on 2/4/13.
//
//

#include "include.h"

class Solution {
public:
    bool isBalanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int dummy;
        return isBalanced(root, dummy);
    }
    
    bool isBalanced(TreeNode* root, int& height) {
        if (!root) {
            height = 0;
            return true;
        }
        
        int left_height, right_height;
        if (!isBalanced(root->left, left_height))
            return false;
        if (!isBalanced(root->right, right_height))
            return false;
        
        height = max(left_height, right_height) + 1;
        return abs(left_height - right_height) <= 1;
    }
};