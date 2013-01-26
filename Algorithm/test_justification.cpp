//
//  test_justification.cpp
//  Algorithm
//
//  Created by Shuai on 1/26/13.
//
//

#include "include.h"

class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        vector<string> result;
        
        int line_len = -1, line_start = -1, line_end = -1;
        
        for (int i=0; i<words.size(); i++) {
            if (line_len != -1 && line_len + 1 + words[i].size() > L) {
                // justify line
                
                string line;
                int spaces = L - line_len + line_end - line_start;
                
                for (int pos=line_start; pos<=line_end; pos++) {
                    if (pos == line_end) {
                        line.append(words[pos]);
                        line.append(spaces, ' ');
                    } else {
                        int insert_spaces = (spaces + (line_end-pos-1))/(line_end-pos);
                        spaces -= insert_spaces;
                        line.append(words[pos]);
                        line.append(insert_spaces, ' ');
                    }
                }
                result.push_back(line);
                
                line_len = line_start = line_end = -1;
            }
            
            line_len += 1 + words[i].size();
            if (line_start == -1)
                line_start = i;
            line_end = i;
        }
        
        string line;
        for (int pos=line_start; pos<line_end; pos++) {
            line.append(words[pos]);
            line.append(1, ' ');
        }
        line.append(words[line_end]);
        if (line.size() < L)
            line.append(L-line.size(), ' ');
        result.push_back(line);
        
        return result;
    }
};

void test_text_justification() {
    vector<string> input;
    input.push_back(string("a"));
    input.push_back("b");
    input.push_back("c");
    input.push_back("d");
    input.push_back("e");
    
    Solution s;
    s.fullJustify(input, 3);
}
