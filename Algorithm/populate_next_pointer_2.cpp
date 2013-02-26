//
//  populate_next_pointer_2.cpp
//  Algorithm
//
//  Created by Shuai on 2/26/13.
//
//

#include "include.h"

class Solution {
public:
    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        while (root) {
            TreeLinkNode sentinel(0), *prev = &sentinel, *next = NULL;
            while (root) {
                if (root->left)
                    prev = prev->next = root->left;
                
                if (root->right)
                    prev = prev->next = root->right;
                
                if (!next && (root->left || root->right))
                    next = root->left ? root->left : root->right;
                
                root = root->next;
            }
            root = next;
        }
    }
};