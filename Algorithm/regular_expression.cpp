//
//  regular_expression.cpp
//  Algorithm
//
//  Created by Shuai on 1/20/13.
//
//

#include <unordered_set>

class SolutionRegex {
public:
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (*p == 0)
            return *s == 0;
        
        if (*s == 0) {
            if (*(p+1) != '*')
                return false;
            return (s, p+2);
        }
        
        if (p[1] == '*') {
            if (p[0] == '.' || p[0] == s[0])
                return isMatch(s+1, p) || isMatch(s, p+2);
            return isMatch(s, p+2);
        }
        
        if (p[0] != '.' && p[0] != s[0])
            return false;
        
        return isMatch(s+1, p+1);
    }
};
