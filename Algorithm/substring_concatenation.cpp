//
//  substring_concatenation.cpp
//  Algorithm
//
//  Created by Shuai on 3/17/13.
//
//

#include "include.h"

class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        vector<int> result;
        
        int len = L[0].size();
        map<string, int> dict;
        for (int i=0; i<L.size(); i++)
            dict[L[i]] ++;
        
        for (int offset = 0; offset < len; offset++) {
            int words = (S.size() - offset)/len;
            if (!words)
                break;
            
            int start = 0, need = dict.size();
            map<string, int> map(dict);
            for (int i=0; i<words; i++) {
                string str(S, i*len+offset, len);
                
                map[str] --;
                if (map[str] == 0)
                    need--;
                
                for (; start<i; start++) {
                    string str(S, start*len+offset, len);
                    if (map[str] >= 0)
                        break;
                    map[str] ++;
                }
                
                if (need == 0 && i-start+1 == L.size())
                    result.push_back(start*len+offset);
            }
        }
        return result;
    }
};