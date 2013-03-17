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
        
        int* p0 = A, *p2 = A+n-1, *p = A;
        while (p <= p2) {
            if (*p == 2) {
                swap(*p2--, *p);
                continue;
            }
            if (*p == 0)
                swap(*p0++, *p);
            p++;
        }
    }
};