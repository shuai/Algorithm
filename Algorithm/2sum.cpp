//
//  2sum.cpp
//  Algorithm
//
//  Created by Shuai on 2/9/13.
//
//

#include "include.h"

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        vector<int> result;
        
        map<int, int> map;
        for (int i=0; i<numbers.size(); i++) {
            int val = target - numbers[i];
            if (map.find(val) != map.end()) {
                result.push_back(map[val]+1);
                result.push_back(i+1);
                break;
            }
            
            if (map.find(numbers[i]) == map.end())
                map.insert(make_pair(numbers[i], i));
        }
        return result;
    }
};