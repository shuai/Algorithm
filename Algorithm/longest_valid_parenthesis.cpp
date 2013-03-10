//
//  longest_valid_parenthesis.cpp
//  Algorithm
//
//  Created by Shuai on 3/9/13.
//
//

#include "include.h"


class Solution {
public:
    int longestValidParentheses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        vector<int> stack;
        for (int i=0; i<s.size(); i++)
            if (stack.size() && s[i] == ')' && s[stack.back()] == '(')
                stack.pop_back();
            else
                stack.push_back(i);
        
        if (stack.empty())
            return s.size();
        
        int longest = max(stack.front(), (int)s.size()-stack.back()-1);
        for (int i=1; i<stack.size(); i++)
            longest = max(longest, stack[i]-stack[i-1]-1);
        return longest;
    }
};