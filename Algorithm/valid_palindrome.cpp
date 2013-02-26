//
//  valid_palindrome.cpp
//  Algorithm
//
//  Created by Shuai on 2/26/13.
//
//

#include "include.h"

class Solution {
public:
    bool isPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int first = 0, last = s.size()-1;
        while (first < last) {
            if (!isalnum(s[first])) {
                first++;
                continue;
            }
            
            if (!isalnum(s[last])) {
                last--;
                continue;
            }
            
            if (tolower(s[first]) != tolower(s[last]))
                return false;
            first++;
            last--;
        }
        return true;
    }
};
