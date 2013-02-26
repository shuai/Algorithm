//
//  distinct_subsequence.cpp
//  Algorithm
//
//  Created by Shuai on 2/26/13.
//
//

#include "include.h"    

class Solution {
public:
    int numDistinct(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int num[S.size()+1][T.size()+1];
        for (int i=0; i<= S.size(); i++)
            num[i][0] = 1;
        for (int i=1; i<= T.size(); i++)
            num[0][i] = 0;
        
        for (int row=1; row<=S.size(); row++)
            for (int col=1; col<=T.size(); col++) {
                num[row][col] = num[row-1][col];
                if (S[row-1] == T[col-1])
                    num[row][col] += num[row-1][col-1];
            }
        
        return num[S.size()][T.size()];
    }
};