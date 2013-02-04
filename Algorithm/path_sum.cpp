//
//  path_sum.cpp
//  Algorithm
//
//  Created by Shuai on 2/4/13.
//
//

#include "include.h"

class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int value = 0;
        vector<TreeNode*> stack;
        while (root || stack.size()) {
            if (root) {
                stack.push_back(root);
                value += root->val;
                if (!root->left && !root->right && value == sum)
                    return true;
                root = root->left;
            } else {
                TreeNode* prev = NULL;
                root = stack.back()->right;
                while (stack.size() && stack.back()->right == prev) {
                    prev = stack.back();
                    value -= stack.back()->val;
                    stack.pop_back();
                }
            }
        }
        
        return false;
    }
    
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        vector<vector<int> > result;
        int value = 0;
        vector<TreeNode*> stack;
        while (root || stack.size()) {
            if (root) {
                stack.push_back(root);
                value += root->val;
                if (!root->left && !root->right && value == sum) {
                    vector<int> path;
                    for (int i=0; i<stack.size(); i++)
                        path.push_back(stack[i]->val);
                    result.push_back(path);
                }
                
                root = root->left;
            } else {
                TreeNode* prev = NULL;
                root = stack.back()->right;
                while (stack.size() && stack.back()->right == prev) {
                    prev = stack.back();
                    value -= stack.back()->val;
                    stack.pop_back();
                }
            }
        }
        
        return result;
    }
};