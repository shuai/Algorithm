//
//  min_path_sum.cpp
//  Algorithm
//
//  Created by Shuai on 2/10/13.
//
//

#include "include.h"

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (grid.empty() || grid[0].empty())
            return 0;
        
        for (int row=1; row<grid.size(); row++)
            grid[row][0] += grid[row-1][0];
        
        for (int col=1; col<grid[0].size(); col++)
            grid[0][col] += grid[0][col-1];
        
        for (int row=1; row<grid.size(); row++)
            for (int col=1; col<grid[0].size(); col++)
                grid[row][col] += min(grid[row-1][col], grid[row][col-1]);
        return grid[grid.size()-1][grid[0].size()-1];
    }
};
