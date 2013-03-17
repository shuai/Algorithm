//
//  longest_common_prefix.cpp
//  Algorithm
//
//  Created by Shuai on 3/16/13.
//
//

#include "include.h"

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (strs.empty())
            return "";
        
        int count = 0;
        while (count < strs[0].size()) {
            char c = strs[0][count];
            for (auto &str : strs) {
                if (str.size() == count || str[count] != c)
                    return string(str, 0, count);
            }
            count ++;
        }
        return string(strs[0], 0, count);
    }
};
