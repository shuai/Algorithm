//
//  pow.cpp
//  Algorithm
//
//  Created by Shuai on 2/10/13.
//
//

#include "include.h"

class Solution {
public:
    double pow(double x, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (n == 0)
            return 1;
        
        bool sign = n > 0;
        unsigned un = abs(n);
        
        double result = 1, base = x;
        while (un) {
            if (un&1)
                result *= base;
            
            un >>= 1;
            base *= base;
        }
        return sign ? result : 1/result;
    }
};