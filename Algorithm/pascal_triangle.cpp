//
//  pascal_triangle.cpp
//  Algorithm
//
//  Created by Shuai on 2/26/13.
//
//

#include "include.h"

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        vector<vector<int>> result;
        if (numRows)
            result.push_back(vector<int>(1,1));
        for (int i=1; i<numRows; i++) {
            vector<int> v(i+1, 0), &last = result[i-1];
            for (int pos=1; pos<i; pos++)
                v[pos] = last[pos-1] + last[pos];
            v.front() = v.back() = 1;
            result.push_back(move(v));
        }
        return move(result);
    }
};
