//
//  set_matrix_zero.cpp
//  Algorithm
//
//  Created by Shuai on 1/27/13.
//
//

#include "include.h"

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int line = -1;
        for (int i=0; i<matrix.size(); i++) {
            bool clear_line = false;
            
            for (int j=0; j<matrix[i].size(); j++) {
                if (matrix[i][j] == 0) {
                    if (line == -1)
                        line = i;
                    matrix[line][j] = 0;
                    clear_line = true;
                }
            }
            
            if (clear_line && i!=line) {
                for (int j=0; j<matrix[i].size(); j++)
                    matrix[i][j] = 0;
            }
        }
        
        if (line != -1) {
            for (int i=0; i<matrix[line].size(); i++) {
                if (matrix[line][i] == 0) {
                    for (int j=0; j<matrix.size(); j++) {
                        matrix[j][i] = 0;
                    }
                }
            }
            
            for (int i=0; i<matrix[line].size(); i++)
                matrix[line][i] = 0;
        }
    }
};