//
//  palindrome_number.cpp
//  Algorithm
//
//  Created by Shuai on 2/10/13.
//
//

class Solution {
public:
    bool isPalindrome(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (x < 0)
            return false;
        
        int base = 1;
        while (base <= x/10)
            base*=10;
        
        while (x) {
            int high_digit = x/base;
            int low_digit = x%10;
            if (high_digit != low_digit)
                return false;
            
            x = x%base/10;
            base /= 100;
        }
        return true;
    }
};