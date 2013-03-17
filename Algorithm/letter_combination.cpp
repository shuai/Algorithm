//
//  letter_combination.cpp
//  Algorithm
//
//  Created by Shuai on 3/17/13.
//
//

#include "include.h"

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        const char* letters[] = {
            "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };
        
        vector<string> output;
        string stack;
        combination(letters, digits, 0, output,stack);
        return output;
    }
    
    void combination(const char* letters[],
                     const string& digits,
                     int offset,
                     vector<string>& output,
                     string& stack) {
        if (offset == digits.size()) {
            output.push_back(stack);
            return;
        }
        
        int index = digits[offset] - '2';
        const char* p = letters[index];
        while (*p) {
            stack.push_back(*p);
            combination(letters, digits, offset+1, output, stack);
            stack.pop_back();
            p++;
        }
    }
};
