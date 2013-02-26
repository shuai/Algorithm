//
//  populate_next_pointer.cpp
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
        
        while (root && root->left) {
            TreeLinkNode* current = root, *prev = NULL;
            while (current) {
                if (prev)
                    prev->next = current->left;
                prev = current->left;
                prev = prev->next = current->right;
                current = current->next;
            }
            root = root->left;
        }
    }
};
