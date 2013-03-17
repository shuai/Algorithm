//
//  maximum_rectangle.cpp
//  Algorithm
//
//  Created by Shuai on 3/17/13.
//
//

#include "include.h"

class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (matrix.empty())
            return 0;
        
        int maximum = 0;
        for (int col=0; col<matrix[0].size(); col++)
            matrix[0][col] = (matrix[0][col] == '1');
        
        for (int row=1; row<matrix.size(); row++)
            for (int col=0; col<matrix[0].size(); col++)
                matrix[row][col] = matrix[row][col] == '1' ? matrix[row-1][col] + 1 : 0;
        
        for (int row=0; row<matrix.size(); row++)
            maximum = max(maximum, largestRectangleArea(matrix[row]));
        
        return maximum;
    }
    
    int largestRectangleArea(const vector<char> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int maximum = 0;
        vector<int> stack, left(height.size());
        
        for (int i=0; i<height.size(); i++) {
            while (stack.size() && height[stack.back()] >= height[i])
                stack.pop_back();
            left[i] = stack.empty() ? 0 : stack.back()+1;
            stack.push_back(i);
        }
        
        stack.clear();
        for (int i=height.size()-1; i>=0; i--) {
            while (stack.size() && height[stack.back()] >= height[i])
                stack.pop_back();
            int right = stack.empty() ? height.size()-1 : stack.back()-1;
            maximum = max(maximum, (right-left[i]+1)*height[i]);
            stack.push_back(i);
        }
        
        return maximum;
    }
    
};
