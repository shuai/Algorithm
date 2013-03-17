//
//  find_missing_positive.cpp
//  Algorithm
//
//  Created by Shuai on 3/17/13.
//
//

#include "include.h"

class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        for (int i=0; i<n; i++) {
            int val = A[i];
            while (val > 0 && val <= n && A[val-1] != val) {
                int next = A[val-1];
                A[val-1] = val;
                val = next;
            }
        }
        
        for (int i=0; i<n; i++) {
            if (A[i] != i+1)
                return i+1;
        }
        
        return n+1;
    }
};
