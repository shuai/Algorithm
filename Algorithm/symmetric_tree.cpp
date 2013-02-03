//
//  symmetric_tree.cpp
//  Algorithm
//
//  Created by Shuai on 2/3/13.
//
//

#include "include.h"

class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (!root)
            return true;
        
        return isSymmetric(root->left, root->right);
    }
    
    bool isSymmetric(TreeNode* left, TreeNode* right) {
        if (!left || !right)
            return !left && !right;
        
        return left->val == right->val &&
        isSymmetric(left->left, right->right) &&
        isSymmetric(left->right, right->left);
    }
};

class SolutionIterative {
public:
    bool isSymmetric(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (!root)
            return true;
        
        vector<TreeNode*> stack, stack_rev;
        TreeNode *p = root, *p_rev = root;
        
        while (p || stack.size()) {
            if (p) {
                if (!p_rev)
                    return false;
                stack.push_back(p);
                p = p->left;
                stack_rev.push_back(p_rev);
                p_rev = p_rev->right;
            } else {
                if (p_rev)
                    return false;
                p = stack.back();
                stack.pop_back();
                p_rev = stack_rev.back();
                stack_rev.pop_back();
                if (p->val != p_rev->val)
                    return false;
                p = p->right;
                p_rev = p_rev->left;
                
                if (stack.empty())
                    break;
            }
        }
        return true;
    }
};