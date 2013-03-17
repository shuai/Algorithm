//
//  simplify_path.cpp
//  Algorithm
//
//  Created by Shuai on 1/27/13.
//
//

#include "include.h"

class Solution {
public:
    string simplifyPath(string path) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        string result;
        
        for (int i=0; i<path.size(); i++) {
            if (path[i] == '.') {
                if (path[i+1] == '.') {
                    i++;
                    if (result.size() > 1 && result.back() == '/')
                        result.pop_back();
                    while (result.size() && result.back() != '/')
                        result.pop_back();
                } else if (path[i+1] && path[i+1] != '/')
                    result.push_back('.');
                continue;
            }
            
            if (path[i] == '/' && result.size() && result.back() == '/')
                continue;
            
            result.push_back(path[i]);
        }
        
        if (result.size() > 1 && result.back() == '/')
            result.pop_back();
        
        return result;
    }
};