//
//  valid_number.cpp
//  Algorithm
//
//  Created by Shuai on 1/26/13.
//
//
#include "include.h"

class Solution {
public:
    bool isNumber(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (!s)
            return false;
        
        while (*s == ' ')
            s++;
        
        bool expect_sign = true, expect_e = false, expect_dot = true;
        bool expect_only_space = false, seen_digit = false, seen_e = false;
        
        while (*s) {
            if (*s == '+' || *s == '-') {
                if (!expect_sign)
                    return false;
                s++;
            }
            expect_sign = false;
            
            if (expect_only_space && *s != ' ')
                return false;
            
            if (*s == ' ') {
                expect_only_space = true;
            }
            else if (isdigit(*s)) {
                seen_digit = true;
                if (!seen_e)
                    expect_e = true;
            } else if (*s == '.') {
                if (!expect_dot)
                    return false;
                expect_dot = false;
            } else if (*s == 'e') {
                if (!expect_e)
                    return false;
                expect_e = false;
                expect_dot = false;
                expect_sign = true;
                seen_e = true;
                
                if (!isdigit(s[1]) && (s[1]!='-' && s[1]!='+' || !isdigit(s[2])))
                    return false;
                
            } else {
                return false;
            }
            s++;
        }
        return seen_digit;
    }
};