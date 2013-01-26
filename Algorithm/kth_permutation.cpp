//
//  kth_permutation.cpp
//  Algorithm
//
//  Created by Shuai on 1/23/13.
//
//
#include "include.h"

string getPermutation(int n, int k) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    
    vector<char> numbers;
    for (int i=0; i<n; i++)
        numbers.push_back(i+'1');
    
    vector<int> factorial;
    factorial.push_back(1);
    for (int i=1; i<n; i++)
        factorial.push_back(i*factorial.back());
    
    string result;
    
    k--;
    while (k) {
        int i = k/factorial[n-result.size()-1];
        k -= i*factorial[n-result.size()-1];
        result.push_back(numbers[i]);
        numbers.erase(numbers.begin()+i);
    }
    
    result.append(numbers.begin(), numbers.end());
    return result;
}