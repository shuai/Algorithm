//
//  bst_zigzag_level_traversal.cpp
//  Algorithm
//
//  Created by Shuai on 2/3/13.
//
//

#include "include.h"

class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        vector<vector<int> > result;
        vector<TreeNode*> level;
        if (root)
            level.push_back(root);
        
        bool l2r = true;
        while (level.size()) {
            vector<TreeNode*> next_level;
            vector<int> value;
            for (int i=0; i<level.size(); i++) {
                if (level[i]->left)
                    next_level.push_back(level[i]->left);
                if (level[i]->right)
                    next_level.push_back(level[i]->right);
            }
            if (l2r) {
                for (int i=0; i<level.size(); i++)
                    value.push_back(level[i]->val);
            } else {
                for (int i=level.size()-1; i>=0; i--)
                    value.push_back(level[i]->val);
            }
            l2r = !l2r;
            result.push_back(value);
            level.swap(next_level);
        }
        return result;
    }
};