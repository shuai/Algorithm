//
//  tree.cpp
//  Algorithm
//
//  Created by Shuai on 9/24/12.
//
//

#include "test.h"

#include <vector>

using namespace std;

bool is_tree_identical(TreeNode* left, TreeNode* right)
{
    if (!left || !right) {
        return !left && !right;
    }
    
    vector<TreeNode*> stack;
    vector<TreeNode*> stack2;
    stack.push_back(left);
    stack2.push_back(right);

    while (!stack.empty()) {
        TreeNode* node = stack.back();
        TreeNode* node2 = stack2.back();
        stack.pop_back();
        stack2.pop_back();
        
        if (node->val != node2->val) {
            return false;
        }
        
        if (node->left)
        {
            if (!node2->left) {
                return false;
            }
            stack.push_back(node->left);
            stack2.push_back(node2->left);
        }
        else if (node2->left)
            return false;
        
        if (node->right)
        {
            if (!node2->right) {
                return false;
            }
            stack.push_back(node->right);
            stack2.push_back(node2->right);
        }
        else if (node2->right)
            return false;
    }
    
    return true;
}

void nth_in_tree(TreeNode* tree, unsigned& n)
{
    if (!tree || !n) {
        return;
    }
    
    nth_in_tree(tree->right, n);
    
    if (n == 0)
        return;

    n--;
    if (n == 0) {
        cout << tree->val << endl;
        return;
    }
    
    nth_in_tree(tree->left, n);
}

void tree2list(TreeNode* root, TreeNode*& first, TreeNode*& last)
{
    first = last = root;
    TreeNode* left_last = NULL, *right_first = NULL;
    if (root->left) {
        tree2list(root->left, first, left_last);
        left_last->right = root;
        root->left = left_last;
    }
    
    if (root->right) {
        tree2list(root->right, right_first, last);
        root->right = right_first;
        right_first->left = root;
    }
}

unsigned longest_distance(TreeNode* root, unsigned& longest_path)
{
    unsigned left_path = 0, right_path = 0, left = 0, right = 0;
    if (root->left) {
        left = longest_distance(root->left, left_path);
    }
    if (root->right) {
        right = longest_distance(root->right, right_path);
    }
    longest_path = max(left_path, right_path) + 1;
    return max(max(left, right), left_path + right_path + 1);
}

void test_tree2list()
{
    TreeNode* tree = build_tree();
    TreeNode* first, *last;
    tree2list(tree, first, last);
    
    while (first) {
        cout << first->val << endl;
        first = first->right;
    }
}

void test_tree()
{
    TreeNode* tree = build_tree();
    TreeNode* tree2 = build_tree();
    
    tree2->left->right->val = 0;
    
    //cout << "test tree identity: " << is_tree_identical(tree, tree2) << endl;
    
    for (unsigned i=1; i<20; i++) {
        unsigned n = i;
        nth_in_tree(tree, n);
    }
    
    unsigned dummy;
    cout << "longest distance in tree:" << longest_distance(tree, dummy) << endl;
}