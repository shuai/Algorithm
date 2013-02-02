//
//  merge_sorted_array.cpp
//  Algorithm
//
//  Created by Shuai on 2/1/13.
//
//

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int *insert = A+m+n-1;
        while (m && n) {
            if (A[m-1] > B[n-1]) {
                m--;
                *insert-- = A[m];
            }
            else {
                n--;
                *insert-- = B[n];
            }
        }
        
        while (n) {
            *insert-- = B[--n];
        }
    }
};