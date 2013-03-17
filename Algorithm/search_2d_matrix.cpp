//
//  search_2d_matrix.cpp
//  Algorithm
//
//  Created by Shuai on 3/17/13.
//
//

#include "include.h"

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int left = 0, right = matrix.size()*matrix[0].size();
        while (left < right) {
            int middle = (left+right)/2;
            int val = matrix[middle/matrix[0].size()][middle%matrix[0].size()];
            if (val == target)
                return true;
            if (val < target)
                left = middle+1;
            else
                right = middle;
        }
        return false;
    }
};