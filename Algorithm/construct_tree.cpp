//
//  construct_tree.cpp
//  Algorithm
//
//  Created by Shuai on 2/3/13.
//
//

#include "include.h"

class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        return buildTree(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }
    
    TreeNode* buildTree(vector<int> &preorder,
                        int offset_pre,
                        int count_pre,
                        vector<int> &inorder,
                        int offset_in,
                        int count_in) {
        
        if (!count_pre)
            return NULL;
        
        int root = preorder[offset_pre];
        vector<int>::iterator it = find(inorder.begin()+offset_in, inorder.begin()+offset_in+count_in, root);
        int left = it-inorder.begin()-offset_in;
        int right = count_in - left - 1;
        
        TreeNode* root_node = new TreeNode(root);
        root_node->left = buildTree(preorder, offset_pre+1, left, inorder, offset_in, left);
        root_node->right = buildTree(preorder, offset_pre+1+left, right, inorder, offset_in+left+1, right);
        return root_node;
    }
};