//
//  spiral_matrix.cpp
//  Algorithm
//
//  Created by Shuai on 3/9/13.
//
//

#include "include.h"

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        
        vector<int> result;
        if (matrix.empty() || matrix[0].empty())
            return result;
        
        int left = 0, right = matrix[0].size()-1, top = 0, bottom = matrix.size()-1;
        while (left <= right && top <= bottom) {
            if (left == right) {
                for (int row=top; row<=bottom; row++)
                    result.push_back(matrix[row][left]);
            } else if (top == bottom) {
                for (int col=left; col<=right; col++)
                    result.push_back(matrix[top][col]);
            } else {
                for (int col=left; col<right; col++)
                    result.push_back(matrix[top][col]);
                for (int row=top; row<bottom; row++)
                    result.push_back(matrix[row][right]);
                for (int col=right; col>left; col--)
                    result.push_back(matrix[bottom][col]);
                for (int row=bottom; row>top; row--)
                    result.push_back(matrix[row][left]);
            }
            left ++;
            right --;
            top ++;
            bottom --;
        }
        return result;
    }
};