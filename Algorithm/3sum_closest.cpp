//
//  3sum_closest.cpp
//  Algorithm
//
//  Created by Shuai on 3/16/13.
//
//

#include "include.h"

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int distance = INT_MAX;
        int closest = INT_MAX;
        sort(num.begin(), num.end());
        for (int i=0; i<num.size(); i++) {
            int left = i+1, right = num.size()-1, val = target-num[i];
            while (left < right) {
                int sum = num[left] + num[right];
                if (sum == val)
                    return target;
                if (abs(sum+num[i]-target) < distance) {
                    closest = sum+num[i];
                    distance = abs(closest-target);
                }
                
                if (sum < val)
                    left++;
                else
                    right--;
            }
        }
        return closest;
    }
};
