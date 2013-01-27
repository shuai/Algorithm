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
        
        string ret;
        for (int i=0; i<path.size(); i++) {
            if (path[i] == '.') {
                
                if (i+1 == path.size() || path[i+1] == '/') {
                    if (ret.size() && *ret.rbegin() == '/')
                        ret.resize(ret.size()-1);
                    continue;
                }
                
                if (i+1 != path.size() && path[i+1] == '.') {
                    i++;
                    if (ret.size() && *ret.rbegin() == '/')
                        ret.resize(ret.size()-1);
                    while (ret.size() && *ret.rbegin() != '/')
                        ret.resize(ret.size()-1);
                    continue;
                }
            }
            
            if (path[i] == '/' && ret.size() && *ret.rbegin() == '/')
                continue;
            
            ret.push_back(path[i]);
        }
        
        if (ret.size() && *ret.rbegin() == '/')
            ret.resize(ret.size()-1);
        
        if (ret.empty())
            ret.push_back('/');
        
        return ret;
    }
};

