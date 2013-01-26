//
//  test.cpp
//  Algorithm
//
//  Created by Shuai on 8/12/12.
//
//

#include "test.h"
#include <vector>
#include <cstdio>

using namespace std;

ListNode* build_list()
{
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);
    ListNode* node6 = new ListNode(6);
    ListNode* node7 = new ListNode(7);
    ListNode* node8 = new ListNode(8);
    ListNode* node9 = new ListNode(9);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node7;
    node7->next = node8;
    node8->next = node9;
    return node1;
}

ListNode* build_circular_list()
{
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);
    ListNode* node6 = new ListNode(6);
    ListNode* node7 = new ListNode(7);
    ListNode* node8 = new ListNode(8);
    ListNode* node9 = new ListNode(9);
    ListNode* node10 = new ListNode(10);
    ListNode* node11 = new ListNode(11);
    ListNode* node12 = new ListNode(12);
    ListNode* node13 = new ListNode(13);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node7;
    node7->next = node8;
    node8->next = node9;
    node9->next = node10;
    node10->next = node11;
    node11->next = node12;
    node12->next = node13;
    node13->next = node6;
    return node1;
}

TreeNode* build_tree()
{
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node5 = new TreeNode(5);
    TreeNode* node6 = new TreeNode(6);
    TreeNode* node7 = new TreeNode(7);
    TreeNode* node8 = new TreeNode(8);
    TreeNode* node9 = new TreeNode(9);

    node5->left = node2;
    node5->right = node8;
    node2->left = node1;
    node2->right = node4;
    node4->left = node3;
    node8->left = node7;
    node7->left = node6;
    node8->right = node9;
    
    return node5;
}


void build_random_array(unsigned size, unsigned max, vector<int>& array)
{
    for (int i=0; i<size; i++) {
        array.push_back(rand()%(max+1));
    }
}

void build_dag(vector<bool>& array)
{
    array.resize(14*14);
    array[0*14 + 4] = array[0*14 + 5] = array[0*14 + 11] = true;
    array[1*14 + 2] = array[1*14 + 4] = array[1*14 + 8] = true;
    array[2*14 + 5] = array[2*14 + 6] = array[2*14 + 9] = true;
    array[3*14 + 2] = array[3*14 + 6] = array[3*14 + 13] = true;
    array[4*14 + 7] = true;
    array[5*14 + 8] = array[5*14 + 12] = true;
    array[6*14 + 5] = true;
    array[8*14 + 7] = true;
    array[9*14 + 10] = true;
    array[10*14 + 13] = true;
    array[12*14 + 9] = true;
}

void build_weighted_dag(vector<vector<int> >& array)
{
    array.resize(5);
    for (unsigned i=0; i<array.size(); i++) {
        array[i].resize(5);
        for (unsigned j=0; j<array[i].size(); j++) {
            if (i==j) {
                array[i][j] = 0;
            }
            else
                array[i][j] = INT_MAX;
        }
    }

    array[0][1] = 10;
    array[0][3] = 5;

    array[1][2] = 1;
    array[1][3] = -2;
    
    array[2][4] = 4;
    
    array[3][1] = 3;
    array[3][2] = 9;
    //array[3][4] = 2;

    array[4][2] = 6;
    array[4][0] = 7;
}


void build_random_weighted_graph(unsigned v, vector<unsigned>& array)
{
    array.resize(v*v);
    
    for (unsigned i=1; i<v; i++) {
        for (unsigned j=1; j<v; j++) {
            
            if (rand()%5 == 0) {
                array[i*v+j] = rand()%10;
            }
            else
                array[i*v+j] = UINT_MAX;
        }
    }
}

TreeNode* build_random_tree(unsigned int size)
{
    srand(time(NULL));
    TreeNode* root = NULL;
    
    for (int i=0; i<size; i++) {
        int key = rand()%size;
        
        if (!root)
        {
            root = new TreeNode;
            root->left = root->right = NULL;
            root->key = key;
        }
        else
        {
            TreeNode* newnode = new TreeNode;
            newnode->left = newnode->right = NULL;
            newnode->key = key;
            
            TreeNode* target = root;
            while (true) {
                if (target->key > key)
                {
                    if (target->left)
                        target = target->left;
                    else
                    {
                        target->left = newnode;
                        break;
                    }
                }
                else
                {
                    if (target->right)
                        target = target->right;
                    else
                    {
                        target->right = newnode;
                        break;
                    }
                }
            }
        }
    }
    return root;
}
