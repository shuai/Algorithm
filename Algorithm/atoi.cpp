//
//  atoi.cpp
//  Algorithm
//
//  Created by Shuai on 3/16/13.
//
//

#include "include.h"

class Solution {
public:
    int atoi(const char *str) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        while (*str == ' ')
            str++;
        
        bool sign = true;
        if (*str == '-' || *str == '+') {
            sign = *str == '+';
            str++;
        }
        
        unsigned overflow = sign ? INT_MAX : INT_MIN;
        
        int num = 0;
        while (isdigit(*str)) {
            if ((overflow - (*str - '0'))/10 < num)
                return sign ? INT_MAX : INT_MIN;
            
            num = num*10 + *str - '0';
            str ++;
        }
        
        return sign ? num : -num;
    }
};
