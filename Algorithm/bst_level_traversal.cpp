//
//  bst_level_traversal.cpp
//  Algorithm
//
//  Created by Shuai on 2/3/13.
//
//

#include "include.h"

class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        vector<vector<int> > result;
        vector<TreeNode*> level;
        if (root)
            level.push_back(root);
        
        while (level.size()) {
            vector<TreeNode*> next_level;
            vector<int> value;
            for (int i=0; i<level.size(); i++) {
                value.push_back(level[i]->val);
                if (level[i]->left)
                    next_level.push_back(level[i]->left);
                if (level[i]->right)
                    next_level.push_back(level[i]->right);
            }
            result.push_back(value);
            level.swap(next_level);
        }
        return result;
    }
};