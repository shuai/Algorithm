//
//  dutch_flag.cpp
//  Algorithm
//
//  Created by Shuai on 1/27/13.
//
//

#include "include.h"

class Solution {
public:
    void sortColors(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int current = 0, insert0 = 0, insert1 = 0;
        while (current < n) {
            if (A[current] == 0) {
                swap(A[current], A[insert0++]);
                insert1 = max(insert1, insert0);
            }
            
            if (A[current] == 1)
                swap(A[current], A[insert1++]);
            current ++;
        }
    }
};