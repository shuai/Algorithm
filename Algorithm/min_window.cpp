//
//  min_window.cpp
//  Algorithm
//
//  Created by Shuai on 1/27/13.
//
//

#include "include.h"

class Solution {
public:
    string minWindow(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        
        int flag[256];
        memset(flag, 0, sizeof(flag));
        
        int count = 0;
        for (int i=0; i<T.size(); i++) {
            flag[T[i]] --;
            if (flag[T[i]] == -1)
                count++;
        }
        
        int last = 0, min_len = INT_MAX;
        string ret;
        
        for (int i=0; i<S.size(); i++) {
            flag[S[i]]++;
            if (flag[S[i]] == 0)
                count--;
            while (last<i && flag[S[last]] > 0) {
                flag[S[last]]--;
                last++;
            }
            if (count == 0 && i-last+1 < min_len) {
                min_len = i-last+1;
                ret.assign(S, last, min_len);
            }
        }
        return ret;
    }
};