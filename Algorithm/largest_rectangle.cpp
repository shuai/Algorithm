//
//  largest_rectangle.cpp
//  Algorithm
//
//  Created by Shuai on 3/2/13.
//
//

#include "include.h"

class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int maximum = 0;
        vector<int> stack, left(height.size());
        
        // pair<height, index>
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