//
//  palindrome_partition_2.cpp
//  Algorithm
//
//  Created by Shuai on 3/2/13.
//
//

#include "include.h"

class Solution {
public:
    int minCut(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (s.empty())
            return 0;
        
        vector<vector<bool>> flag; // offset, len
        
        flag.resize(s.size());
        for (auto &v : flag) {
            v.resize(s.size()+1);
            v[0] = v[1] = true;
        }
        
        for (int len=2; len<=s.size(); len++)
            for (int offset=0; offset<=s.size()-len; offset++)
                flag[offset][len] = s[offset] == s[offset+len-1] && flag[offset+1][len-2];
        
        
        int cut[s.size()+1];
        cut[0] = -1;
        for (int i=0; i<s.size(); i++) {
            int c = cut[i];
            for (int start=0; start<=i; start++)
                if (flag[start][i-start+1])
                    c = min(c, cut[start]);
            cut[i+1] = c+1;
        }
        
        return cut[s.size()];
    }
};
