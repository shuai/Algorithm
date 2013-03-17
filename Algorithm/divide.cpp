//
//  divide.cpp
//  Algorithm
//
//  Created by Shuai on 3/17/13.
//
//

#include "include.h"

class Solution {
public:
    int divide(int dividend, int divisor) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        bool sign = dividend < 0 == divisor < 0;
        unsigned num = dividend > 0 ? dividend : -dividend;
        unsigned div = divisor > 0 ? divisor : -divisor;
        
        unsigned result = 0, exponent = 1, current = div;
        
        while (num >> 1 >= current) {
            current <<= 1;
            exponent <<= 1;
        }
        
        while (num >= div) {
            while (num < current) {
                current >>= 1;
                exponent >>= 1;
            }
            
            num -= current;
            result += exponent;
        }
        
        return sign ? result : -result;
    }
};
