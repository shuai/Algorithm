//
//  tree_traversal.cpp
//  Algorithm
//
//  Created by Shuai on 8/9/12.
//
//

#include <vector>
#include <iostream>
#include <cassert>
#include "test.h"
using namespace std;

// Iterative tree traversal



enum TraversalOrder
{
    InOrder,
    PostOrder,
    PreOrder
};

void traverse_preorder(TreeNode* root)
{
    vector<TreeNode*> stack;
    stack.push_back(root);
    while (!stack.empty()) {
        TreeNode* curr = stack.back();
        stack.pop_back();
        
        if (curr) {
            cout << curr->val << endl;
            stack.push_back(curr->right);
            stack.push_back(curr->left);
        }
    }
}

void traverse_inorder(TreeNode* root)
{
    TreeNode* current = root;
    vector<TreeNode*> stack;
    
    while (current || !stack.empty()) {
        if (current) {
            stack.push_back(current);
            current = current->left;
        } else {
            current = stack.back();
            stack.pop_back();
            cout << current->val << endl;
            current = current->right;
        }
    }
}

void traverse_postorder(TreeNode* root)
{
    TreeNode* current = root, *last = NULL;
    vector<TreeNode*> stack;
    
    while (current || !stack.empty()) {
        if (current) {
            stack.push_back(current);
            current = current->left;
        } else {
            current = stack.back();
            if (current->right == NULL || current->right == last) {
                stack.pop_back();
                cout << current->val << endl;
                last = current;
                current = NULL;
            }
            else
                current = current->right;
        }
    }
}

void test_tree_traversal()
{
    TreeNode* tree = build_tree();
    cout << "preorder traversal" << endl;
    traverse_preorder(tree);
    cout << "inorder traversal" << endl;
    traverse_inorder(tree);
    cout << "postorder traversal" << endl;
    traverse_postorder(tree);
    cout << "done " << endl;
}