//
//  search_for_range.cpp
//  Algorithm
//
//  Created by Shuai on 3/17/13.
//
//

#include "include.h"

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        vector<int> result;
        result.push_back(search(A, n, target, true));
        result.push_back(search(A, n, target, false));
        return result;
    }
    
    int search(int A[], int n, int target, bool first) {
        int left = 0, right = n;
        while (left < right) {
            int middle = (left + right)/2;
            if (A[middle] == target)
                if (first && middle && A[middle-1] == target)
                    right = middle;
                else if (!first && middle<n-1 && A[middle+1] == target)
                    left = middle+1;
                else
                    return middle;
            
            if (A[middle] > target)
                right = middle;
            else if (A[middle] < target)
                left = middle+1;
        }
        return -1;
    }
};
