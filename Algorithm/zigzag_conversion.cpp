//
//  zigzag_conversion.cpp
//  Algorithm
//
//  Created by Shuai on 3/9/13.
//
//

#include "include.h"


class Solution {
public:
    string convert(string s, int nRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (nRows == 1)
            return s;
        
        string result;
        int unit = 2*nRows-2;
        int pivot = (s.size() + unit-1)/unit;
        
        for (int row=0; row<nRows; row++) {
            int last = -1;
            for (int p=0; p<pivot; p++) {
                int current_p = nRows+unit*p-1;
                int left = current_p-nRows+1+row;
                if (left != last && left>=0 && left<s.size()) {
                    result.push_back(s[left]);
                    last = left;
                }
                
                int right = current_p+nRows-1-row;
                if (right != last && right<s.size()) {
                    result.push_back(s[right]);
                    last = right;
                }
            }
        }
        return result;
    }
};