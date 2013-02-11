//
//  bst_serialization.cpp
//  Algorithm
//
//  Created by Shuai on 2/9/13.
//
//

#include "include.h"
#include "test.h"

// Serialize binary tree
void serialize(TreeNode* tree, vector<int>& output) {
    if (!tree) {
        output.push_back(INT_MIN);
        return;
    }
    
    output.push_back(tree->val);
    serialize(tree->left, output);
    serialize(tree->right, output);
}

TreeNode* deserialize(const vector<int>& array, int& offset) {
    if (array.size() == offset || array[offset++] == INT_MIN)
        return NULL;
    
    TreeNode* node = new TreeNode(array[offset++]);
    node->left = deserialize(array, offset);
    node->right = deserialize(array, offset);
    return node;
}

// Serialize binary search tree
void serialize_bst(TreeNode* tree, vector<int>& output) {
    if (!tree)
        return;
    
    output.push_back(tree->val);
    serialize_bst(tree->left, output);
    serialize_bst(tree->right, output);
}

TreeNode* deserialize_bst(const vector<int>& output, int& offset, int max = INT_MAX) {
    if (offset == output.size() || output[offset] >= max)
        return NULL;
    
    TreeNode* node = new TreeNode(output[offset++]);
    node->left = deserialize_bst(output, offset, node->val);
    node->right = deserialize_bst(output, offset, max);
    return node;
}


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

void test_serialization() {
    TreeNode* tree = build_tree();
    
    vector<int> output;
    int offset = 0;
    
    cout << "Serialize bst: ";
    serialize_bst(tree, output);
    for (auto i : output) {
        cout << i << " ";
    }
    cout << endl;
    
    TreeNode* tree2 = deserialize_bst(output, offset);
    Solution s;
    assert(s.isSameTree(tree, tree2));
    
    cout << "Serialize: ";
    output.clear();
    serialize(tree, output);
    for (auto i : output) {
        if (i == INT_MIN)
            cout << "null ";
        else
            cout << i << " ";
    }
    cout << endl;
    
}
