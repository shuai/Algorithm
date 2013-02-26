
//
//  maximum_path_sum.cpp
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
    int maxPathSum(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int dummy;
        return maxPath(root, dummy);
    }
    
    int maxPath(TreeNode* root, int& path) {
        if (!root)
            return INT_MIN;
        
        int left_path = 0, right_path = 0;
        int left_sum = maxPath(root->left, left_path);
        int right_sum = maxPath(root->right, right_path);
        path = max(0, max(left_path, right_path) + root->val);
        int sum = left_path + right_path + root->val;
        return max(sum, max(left_sum, right_sum));
    }
};