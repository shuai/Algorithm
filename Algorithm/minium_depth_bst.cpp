//
//  minium_depth_bst.cpp
//  Algorithm
//
//  Created by Shuai on 2/4/13.
//
//

#include "include.h"

class Solution {
public:
    int minDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (!root)
            return 0;
        
        if (!root->left && !root->right)
            return 1;
        
        if (root->left && root->right)
            return min(minDepth(root->left), minDepth(root->right)) + 1;
        if (root->left)
            return minDepth(root->left)+1;
        return minDepth(root->right)+1;
    }
};