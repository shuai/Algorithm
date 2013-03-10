//
//  rotate_image.cpp
//  Algorithm
//
//  Created by Shuai on 3/9/13.
//
//

#include "include.h"

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int size = matrix.size();
        for(int layer=0; layer<matrix.size()/2; layer++) {
            for (int col=layer; col<matrix.size()-layer-1; col++) {
                int val = matrix[layer][col];
                matrix[layer][col] = matrix[size-col-1][layer];
                matrix[size-col-1][layer] = matrix[size-layer-1][size-col-1];
                matrix[size-layer-1][size-col-1] = matrix[col][size-layer-1];
                matrix[col][size-layer-1] = val;
            }
        }
    }
};
