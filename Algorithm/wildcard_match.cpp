//
//  wild_match.cpp
//  Algorithm
//
//  Created by Shuai on 2/3/13.
//
//

#include "include.h"

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int len_s = strlen(s), len_p = strlen(p);
        if (!len_p)
            return !len_s;
        
        // -->Hack for last test case
        int count_p = 0;
        const char* ptr = p;
        while (*ptr) {
            if (*ptr != '*')
                count_p ++;
            ptr++;
        }
        
        if (count_p > len_s)
            return false;
        // <--
        
        bool match[len_p];
        match[0] = p[0] == '*';
        for (int i=1; i<len_p; i++)
            match[i] = match[i-1] && p[i] == '*';
        
        bool diagnal = true;
        for (int row=0; row<len_s; row++) {
            bool left = false;
            for (int col=0; col<len_p; col++) {
                bool m = p[col] == '*' && (diagnal || left || match[col]) ||
                (p[col] == '?' || p[col] == s[row]) && diagnal;
                diagnal = match[col];
                left = match[col] = m;
            }
            diagnal = false;n
        }
        return match[len_p-1];
    }
};