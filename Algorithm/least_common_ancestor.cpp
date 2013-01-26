//
//  least_common_ancestor.cpp
//  Algorithm
//
//  Created by Shuai on 9/2/12.
//
//

#include <vector>
#include <cassert>
#include "test.h"

using namespace std;


TreeNode* least_common_ancestor(TreeNode* root, int value1, int value2)
{
    TreeNode* ancestor = NULL, *current = root, *last = NULL;
    
    vector<TreeNode*> stack;
    stack.push_back(root);
    
    while (!stack.empty())
    {
        TreeNode* child = NULL;
        if (!last || last->left == current || last ->right == current)
        {
            if (current->key == value1 || current->key == value2)
            {
                if (ancestor)
                    return ancestor;
                
                ancestor = current;
            }
            
            child = current->left ? current->left : current->right;
        }
        else if (current->left == last)
        {
            child = current->right;
        }
        
        if (child)
        {
            stack.push_back(child);
            last = current;
            current = child;
        }
        else
        {
            stack.pop_back();
            if (!stack.empty())
            {
                last = current;
                current = stack.back();
                if (ancestor == last)
                    ancestor = current;
            }
        }
    }
    return ancestor;
}

TreeNode* lca_recursive(TreeNode* root, int value1, int value2, bool& found)
{
    found = false;
    if (!root) {
        return NULL;
    }
    
    assert(value1 != value2);
    
    bool found_left, found_right, found_self = false;
    TreeNode* ancestor = lca_recursive(root->left, value1, value2, found_left);
    if (ancestor) {
        return ancestor;
    }
    
    ancestor = lca_recursive(root->right, value1, value2, found_right);
    if (ancestor) {
        return ancestor;
    }
    
    if (value1 == root->key || value2 == root->key) {
        found_self = true;
    }
    
    int count = found_self + found_left + found_right;
    
    if (count == 2)
        return root;
    else
        found = count == 1;
    
    return NULL;
}

void test_lca()
{
    bool dummy;
    TreeNode* root = build_tree();
    int node1 = 2, node2 = 3;
    cout << "Test lca, common ancestor of " << node1 << " & " << node2 << " is " << least_common_ancestor(root, node1, node2)->key << endl;
    cout << "Test lca, common ancestor of " << node1 << " & " << node2 << " is " << lca_recursive(root, node1, node2, dummy)->key << endl;

    node1 = 4;
    node2 = 2;
    cout << "Test lca, common ancestor of " << node1 << " & " << node2 << " is " << least_common_ancestor(root, node1, node2)->key << endl;
    cout << "Test lca, common ancestor of " << node1 << " & " << node2 << " is " << lca_recursive(root, node1, node2, dummy)->key << endl;

    node1 = 2;
    node2 = 4;
    cout << "Test lca, common ancestor of " << node1 << " & " << node2 << " is " << least_common_ancestor(root, node1, node2)->key << endl;
    cout << "Test lca, common ancestor of " << node1 << " & " << node2 << " is " << lca_recursive(root, node1, node2, dummy)->key << endl;

    node1 = 4;
    node2 = 9;
    cout << "Test lca, common ancestor of " << node1 << " & " << node2 << " is " << least_common_ancestor(root, node1, node2)->key << endl;
    cout << "Test lca, common ancestor of " << node1 << " & " << node2 << " is " << lca_recursive(root, node1, node2, dummy)->key << endl;

    node2 = 5;
    cout << "Test lca, common ancestor of " << node1 << " & " << node2 << " is " << least_common_ancestor(root, node1, node2)->key << endl;
    cout << "Test lca, common ancestor of " << node1 << " & " << node2 << " is " << lca_recursive(root, node1, node2, dummy)->key << endl;

    node2 = 3;
    cout << "Test lca, common ancestor of " << node1 << " & " << node2 << " is " << least_common_ancestor(root, node1, node2)->key << endl;
    cout << "Test lca, common ancestor of " << node1 << " & " << node2 << " is " << lca_recursive(root, node1, node2, dummy)->key << endl;

    node2 = 7;
    cout << "Test lca, common ancestor of " << node1 << " & " << node2 << " is " << least_common_ancestor(root, node1, node2)->key << endl;
    cout << "Test lca, common ancestor of " << node1 << " & " << node2 << " is " << lca_recursive(root, node1, node2, dummy)->key << endl;

    node2 = 8;
    cout << "Test lca, common ancestor of " << node1 << " & " << node2 << " is " << least_common_ancestor(root, node1, node2)->key << endl;
    cout << "Test lca, common ancestor of " << node1 << " & " << node2 << " is " << lca_recursive(root, node1, node2, dummy)->key << endl;

    node1 = 1;
    cout << "Test lca, common ancestor of " << node1 << " & " << node2 << " is " << least_common_ancestor(root, node1, node2)->key << endl;
    cout << "Test lca, common ancestor of " << node1 << " & " << node2 << " is " << lca_recursive(root, node1, node2, dummy)->key << endl;

    node1 = 3;
    cout << "Test lca, common ancestor of " << node1 << " & " << node2 << " is " << least_common_ancestor(root, node1, node2)->key << endl;
    cout << "Test lca, common ancestor of " << node1 << " & " << node2 << " is " << lca_recursive(root, node1, node2, dummy)->key << endl;


}