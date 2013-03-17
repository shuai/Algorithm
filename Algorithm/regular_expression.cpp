//
//  regular_expression.cpp
//  Algorithm
//
//  Created by Shuai on 1/20/13.
//
//

class SolutionRegex {
public:
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (!*p)
            return !*s;
        if (p[1] == '*')
            return isMatch(s, p+2) || (*p == '.' && *s || *s == *p) && isMatch(s+1, p);
        if (*p == '.')
            return *s && isMatch(s+1, p+1);
        return *s == *p && isMatch(s+1, p+1);
    }
};
