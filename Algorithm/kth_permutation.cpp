//
//  kth_permutation.cpp
//  Algorithm
//
//  Created by Shuai on 1/23/13.
//
//
#include "include.h"

class Solution {
public:
    string getPermutation(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (n < 1)
            return "";
        
        int factorial[n];
        factorial[0] = 1;
        for (int i=1; i<n; i++)
            factorial[i] = factorial[i-1]*i;
        
        if (k > n*factorial[n-1])
            return "";
        
        vector<char> numbers;
        for (int i=0; i<n; i++)
            numbers.push_back(i+'1');
        
        k--;
        string ret;
        while (numbers.size()) {
            int index = k/factorial[numbers.size()-1];
            k %= factorial[numbers.size()-1];
            ret.push_back(numbers[index]);
            numbers.erase(numbers.begin() + index);
        }
        
        return ret;
    }
};