//
//  scramble_string.cpp
//  Algorithm
//
//  Created by Shuai on 2/1/13.
//
//

#include "include.h"

class Solution {
public:
    bool isScramble(string s1, string s2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (s1.empty() || s1.size() != s2.size())
            return false;
        
        int b[s1.size()][s2.size()][s1.size()+1];
        for (int row=0; row<s1.size(); row++)
            for (int col=0; col<s2.size(); col++)
                b[row][col][1] = s1[row] == s2[col];
        
        for (int len=2; len<=s1.size(); len++) {
            for (int row=0; row<s1.size(); row++) {
                if (row + len > s1.size())
                    break;
                
                for (int col=0; col<s2.size(); col++){
                    if (col + len > s2.size())
                        break;
                    
                    b[row][col][len] = false;
                    for (int i=1; i<len; i++)
                        if (b[row][col][i] && b[row+i][col+i][len-i] ||
                            b[row][col+len-i][i] && b[row+i][col][len-i]) {
                            b[row][col][len] = true;
                            break;
                        }
                }
            }
        }
        
        return b[0][0][s1.size()];
    }
};