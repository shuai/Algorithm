//
//  interval_tree.cpp
//  Algorithm
//
//  Created by Shuai on 2/9/13.
//
//

#include "include.h"

struct IntervalTreeNode {
    IntervalTreeNode* left;
    IntervalTreeNode* right;
    Interval interval;
    int max_end;
    
    IntervalTreeNode():left(NULL), right(NULL), max_end(0) {}
};

void insert(IntervalTreeNode* root, const Interval& interval) {
    
    bool left = interval.start <= root->interval.start;
    if (left && root->left) {
        insert(root->left, interval);
    } else if (!left && root->right) {
        insert(root->right, interval);
    } else {
        IntervalTreeNode* node = new IntervalTreeNode;
        node->interval = interval;
        node->max_end = interval.end;
        if (left)
            root->left = node;
        else
            root->right = node;
    }
    
    if (left)
        root->max_end = max(root->max_end, root->left->max_end);
    else
        root->max_end = max(root->max_end, root->right->max_end);
}

// return if interval is contained in the tree
bool contains(IntervalTreeNode* root, Interval interval) {
    if (!root)
        return false;
    
    if (interval.end <= root->interval.start)
        return contains(root->left, interval);
    
    if (interval.start >= root->max_end)
        return false;
    
    if (interval.start < root->interval.start)
       return contains(root->left, Interval(interval.start, root->interval.start)) &&
        contains(root->right, Interval(root->interval.start, interval.end));
    
    return contains(root->right, interval);
}

void test_intervals() {

}