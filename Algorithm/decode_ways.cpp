//
//  decode_ways.cpp
//  Algorithm
//
//  Created by Shuai on 2/1/13.
//
//

#include "include.h"

class Solution {
public:
    int numDecodings(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (s.empty())
            return 0;
        
        int ways[s.size()+1];
        ways[0] = 1;
        ways[1] = s[0] <= '9' && s[0] >= '1';
        
        for (int i=1; i<s.size(); i++) {
            int count = 0;
            if (s[i] != '0')
                count += ways[i];
            if (s[i-1] == '1' || s[i-1] == '2' && s[i] <= '6')
                count += ways[i-1];
            
            ways[i+1] = count;
        }
        
        return ways[s.size()];
    }
};