//
//  multiply_string.cpp
//  Algorithm
//
//  Created by Shuai on 2/10/13.
//
//

#include "include.h"

class Solution {
public:
    string multiply(string num1, string num2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (num1.size() == 1 && num1[0] == '0' ||
            num2.size() == 1 && num2[0] == '0')
            return "0";
        
        vector<char> result;
        result.resize(num1.size() + num2.size());
        for (int i=0; i<num1.size(); i++) {
            
            int digit1 = num1[num1.size()-i-1] - '0';
            if (digit1 == 0)
                continue;
            
            // multiply num2
            vector<char> product;
            char carry = 0;
            for (int j=0; j<num2.size(); j++) {
                char digit2 = num2[num2.size()-j-1] - '0';
                char p = digit1*digit2 + carry;
                carry = p/10;
                product.push_back(p%10);
            }
            if (carry)
                product.push_back(carry);
            
            carry = 0;
            for (int j=0; j<product.size(); j++) {
                char p = product[j]+result[j+i]+carry;
                carry = p/10;
                result[j+i] = p%10;
            }
            if (carry)
                result[product.size()+i] = carry;
        }
        
        while (result.size() > 1 && result.back() == 0)
            result.pop_back();
        
        for (int i=0; i<result.size(); i++)
            result[i] += '0';
        return string(result.rbegin(), result.rend());
    }
};