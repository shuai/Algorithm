//
//  sqrt_integer.cpp
//  Algorithm
//
//  Created by Shuai on 1/27/13.
//
//

#include "include.h"

class Solution {
public:
    int sqrt(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (x < 0)
            return -1;
        
        long long right = (long long)x+1;
        long long left = 0;
        
        while (left < right) {
            long long mid = (left+right)/2;
            long long val = mid*mid;
            
            if (val == x)
                return mid;
            
            if (val < x)
                left = mid+1;
            else
                right = mid;
        }
        return left-1;
    }
};

void test_sqrt() {
    Solution s;
    int val = s.sqrt(2147483647);
    assert (val == 46340);
}