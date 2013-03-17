//
//  combination_sum.cpp
//  Algorithm
//
//  Created by Shuai on 3/17/13.
//
//

#include "include.h"

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> stack;
        combination(result, candidates, stack, 0, target);
        return result;
    }
    
    void combination(vector<vector<int>>& output,
                     const vector<int>& candidates,
                     vector<int>& stack,
                     int offset,
                     int target) {
        if (target == 0) {
            output.push_back(stack);
            return;
        }
        
        if (offset == candidates.size())
            return;
        
        int next_offset = offset;
        while (next_offset != candidates.size() && candidates[next_offset] == candidates[offset])
            next_offset++;
        
        int num = candidates[offset], count = target/num;
        for (int i=0; i<=count; i++) {
            combination(output, candidates, stack, next_offset, target);
            stack.push_back(num);
            target -= num;
        }
        
        stack.resize(stack.size()-count-1);
    }
};
