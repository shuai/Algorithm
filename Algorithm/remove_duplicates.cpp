//
//  remove_duplicates.cpp
//  Algorithm
//
//  Created by Shuai on 1/27/13.
//
//

#include "include.h"

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int pos = 0;
        for (int i=0; i<n; i++) {
            if (pos < 2 || A[pos-2] != A[i])
                A[pos++] = A[i];
        }
        return pos;
    }
};