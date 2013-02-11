//
//  length_of_last_word.cpp
//  Algorithm
//
//  Created by Shuai on 2/10/13.
//
//

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int last = 0, current = 0;
        while (s && *s) {
            if (*s == ' ') {
                if (current)
                    last = current;
                current = 0;
            } else {
                current ++;
            }
            s++;
        }
        
        return current ? current : last;
    }
};
