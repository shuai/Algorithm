//
//  rotated_array.cpp
//  Algorithm
//
//  Created by Shuai on 1/30/13.
//
//

#include "include.h"

class Solution {
public:
    bool search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (n == 0)
            return false;
        
        if (A[0] == target)
            return true;
        
        int start = 0;
        while (A[start] == A[n-1])
            start++;
        
        while (start < n) {
            int mid = (start+n)/2;
            int val = A[mid];
            if (val == target)
                return true;
            
            bool search_left = true;
            if (val > A[n-1] && (val < target || target < A[start])
                ||(val < A[n-1] && val < target && target <= A[n-1]))
                search_left = false;
            
            if (search_left)
                n = mid;
            else
                start = mid + 1;
        }
        
        return false;
    }
};