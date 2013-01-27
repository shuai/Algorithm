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
        
        int insert = 2, pos = 2;
        for (;pos<n; pos++) {
            if (A[pos] != A[insert-2])
                A[insert++] = A[pos];
        }
        return min(n, insert);
    }
};