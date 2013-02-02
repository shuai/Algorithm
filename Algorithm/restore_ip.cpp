//
//  restore_ip.cpp
//  Algorithm
//
//  Created by Shuai on 2/2/13.
//
//
#include "include.h"

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        vector<string> result;
        string dummy;
        restore(result, dummy, s, 0, 4);
        return result;
    }
    
    void restore(vector<string>& result, string& stack, const string& s, int pos, int count) {
        
        int c = 0;
        if (stack.size()) {
            stack.push_back('.');
            c ++;
        }
        
        int val = 0;
        for (int i=pos; i<s.size(); i++) {
            val = val*10 + s[i] - '0';
            if (val > 255)
                break;
            
            stack.push_back(s[i]);
            c ++;
            
            if (count == 1) {
                if (i == s.size()-1)
                    result.push_back(stack);
            } else {
                restore(result, stack, s, i+1, count-1);
            }
            
            if (val == 0)
                break;
        }
        
        stack.resize(stack.size()-c);
    }
};