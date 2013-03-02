//
//  palindrome_partition.cpp
//  Algorithm
//
//  Created by Shuai on 3/2/13.
//
//

#include "include.h"

class Solution {
public:
    vector<vector<string>> partition(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        vector<vector<string>> result;
        vector<vector<bool>> flag; // offset, len
        
        flag.resize(s.size());
        for (auto &v : flag) {
            v.resize(s.size()+1);
            v[0] = v[1] = true;
        }
        
        for (int len=2; len<=s.size(); len++)
            for (int offset=0; offset<=s.size()-len; offset++)
                flag[offset][len] = s[offset] == s[offset+len-1] && flag[offset+1][len-2];
        
        vector<string> set;
        partition(result, flag, set, s, 0);
        return result;
    }
    
    void partition(vector<vector<string>>& result,
                   const vector<vector<bool>>& flag,
                   vector<string>& set,
                   const string& str,
                   int offset) {
        if (offset == str.size()) {
            result.push_back(set);
            return;
        }
        
        for (int len=1; len<=str.size()-offset; len++) {
            if (flag[offset][len]) {
                set.push_back(string(str, offset, len));
                partition(result, flag, set, str, offset+len);
                set.pop_back();
            }
        }
    }
};
