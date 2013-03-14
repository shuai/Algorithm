//
//  strstr.cpp
//  Algorithm
//
//  Created by Shuai on 3/14/13.
//
//

#include "include.h"

class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int len = strlen(needle);
        if (!len)
            return haystack;
        
        int next[len];
        next[0] = -1;
        if (len > 1)
            next[1] = 0;
        
        int pos = 2, c = 0;
        while (pos < len) {
            if (needle[c] == needle[pos-1]) {
                c++;
                next[pos++] = c;
            } else if (c)
                c = next[c];
            else
                next[pos++] = 0;
        }
        
        pos = 0;
        while (*haystack) {
            if (*haystack == needle[pos]) {
                if (pos == len-1)
                    return haystack-pos;
                pos++;
                haystack++;
            } else if (pos)
                pos = next[pos];
            else
                haystack++;
        }
        
        return nullptr;
    }
};