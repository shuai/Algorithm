//
//  matrix.cpp
//  Algorithm
//
//  Created by Shuai on 9/7/12.
//
//

#include <stdio.h>

void rotateMatrix(unsigned* matrix, int n)
{
    int line = 0;
    
    for (; line < n/2; line++) {
        for (int i=line; i<n-line-1; i++) {
            unsigned top = matrix[i*n+line];
            matrix[i*n+line] = matrix[line*n+n-i-1];
            matrix[line*n + n-i-1] = matrix[n*(n-i-1)+n-line-1];
            matrix[n*(n-i-1)+n-line-1] = matrix[n*(n-line-1)+i];
            matrix[n*(n-line-1)+i] = top;
        }
    }
}

void test_rotate_matrix()
{
    unsigned matrix1[3][3] = {1,2,3,4,5,6,7,8,9};
    rotateMatrix((unsigned*)matrix1, 3);
    
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            printf("%d", matrix1[i][j]);
        }
        printf("\n");
    }
}