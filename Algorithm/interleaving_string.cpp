//
//  interleaving_string.cpp
//  Algorithm
//
//  Created by Shuai on 2/3/13.
//
//
#include "include.h"

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (s1.size() + s2.size() != s3.size())
            return false;
        
        bool b[s1.size()+1][s2.size()+1];
        b[0][0] = true;
        
        for (int i=1; i<=s1.size(); i++)
            b[i][0] = b[i-1][0] && s1[i-1] == s3[i-1];
        
        for (int i=1; i<=s2.size(); i++)
            b[0][i] = b[0][i-1] && s2[i-1] == s3[i-1];
        
        for (int row=1; row<=s1.size(); row++) {
            for (int col=1; col<=s2.size(); col++) {
                b[row][col] = b[row-1][col] && s1[row-1] == s3[row+col-1] ||
                b[row][col-1] && s2[col-1] == s3[row+col-1];
            }
        }
        return b[s1.size()][s2.size()];
    }
};