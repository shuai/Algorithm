//
//  same_tree.cpp
//  Algorithm
//
//  Created by Shuai on 2/3/13.
//
//

#include "include.h"

class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (q && !p)
            return false;
        
        vector<TreeNode*> stack_p, stack_q;
        while (p || stack_p.size()) {
            if (p) {
                if (!q)
                    return false;
                stack_p.push_back(p);
                p = p->left;
                stack_q.push_back(q);
                q = q->left;
            } else {
                if (q)
                    return false;
                p = stack_p.back();
                stack_p.pop_back();
                q = stack_q.back();
                stack_q.pop_back();
                if (p->val != q->val)
                    return false;
                p = p->right;
                q = q->right;
            }
        }
        return true;
    }
};