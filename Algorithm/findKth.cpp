//
//  findKth.cpp
//  Algorithm
//
//  Created by Shuai on 1/19/13.
//
//
#include "test.h"

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int count = m+n;
        int left = (count-1)/2, right = count/2;
        return (kth(A, m, B, n, left) + kth(A, m, B, n, right))/2;
    }
    
    double kth(int* A, int m, int* B, int n, int k) {
        if (m == 0)
            return B[k];
        if (n == 0)
            return A[k];
        if (k == m+n-1)
            return max(A[m-1], B[n-1]);
        
        int pivot_a = k*m/(m+n);
        int pivot_b = k-pivot_a;
        if (pivot_b >= n) {
            pivot_b = n-1;
            pivot_a = k-pivot_b;
        }
        
        if (A[pivot_a] == B[pivot_b])
            return A[pivot_a];
        
        if (A[pivot_a] > B[pivot_b]) {
            swap(A, B);
            swap(m, n);
            swap(pivot_a, pivot_b);
        }
        
        if (pivot_b == 0 || A[pivot_a] >= B[pivot_b-1])
            return A[pivot_a];
        
        return kth(A+pivot_a+1, m-pivot_a-1, B, pivot_b, k-pivot_a-1);
    }
};