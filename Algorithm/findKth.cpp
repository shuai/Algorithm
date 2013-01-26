//
//  findKth.cpp
//  Algorithm
//
//  Created by Shuai on 1/19/13.
//
//
#include "test.h"

class SolutionKth {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (m+n == 0)
            return 0;
        
        int k1 = (m+n+1)/2;
        int k2 = (m+n)/2+1;
        return (findKth(A, m, B, n, k1) + findKth(A, m, B, n, k2))/2;
    }
    
    double findKth(int* A, int m, int* B, int n, int k) {
        if (m == 0)
            return B[k-1];
        if (n == 0)
            return A[k-1];
        if (k == m+n)
            return max(A[m-1], B[n-1]);
        
        int a_index = min(m-1, (k-1)/2);
        int b_index = k-1-a_index;
        if (b_index >= n) {
            b_index = n-1;
            a_index =- k-1-b_index;
        }
        
        if (A[a_index] == B[b_index])
            return A[a_index];
        
        if (A[a_index] > B[b_index]) {
            swap(A,B);
            swap(a_index, b_index);
            swap(m,n);
        }
        
        if (b_index > 0)
            if (A[a_index] <= B[b_index-1])
                return findKth(A + a_index + 1, m - a_index - 1, B, b_index + 1, k - a_index - 1);
        
        
        return A[a_index];
    }
};

void test_median()
{
    int A[] = {3,4,5,6};
    int B[] = {1,2};
    
    SolutionKth s;
    double ret = s.findMedianSortedArrays(A, sizeof(A)/sizeof(*A), B, sizeof(B)/sizeof(*B));
    cout << "Median " << ret << endl;
}