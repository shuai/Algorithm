//
//  maximum_subarray.cpp
//  Algorithm
//
//  Created by Shuai on 3/17/13.
//
//

#include "include.h"

class Solution {
public:
    int maxSubArray(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int sum = 0, max_sum = INT_MIN;
        for (int i=0; i<n; i++) {
            sum += A[i];
            max_sum = max(max_sum, sum);
            if (sum <= 0)
                sum = 0;
        }
        
        return max_sum;
    }
};
