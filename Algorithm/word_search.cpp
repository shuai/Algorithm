//
//  word_search.cpp
//  Algorithm
//
//  Created by Shuai on 1/27/13.
//
//

#include "include.h"

class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (board.empty() || board[0].empty() || word.empty())
            return false;
        
        for (int i=0; i<board.size(); i++)
            for (int j=0; j<board[0].size(); j++)
                if (exist(board, word, j, i, 0))
                    return true;
        return false;
    }
    
    bool exist(vector<vector<char> > &board, string& word, int x, int y, int index) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        char c = board[y][x];
        if (c != word[index])
            return false;
        
        index ++;
        if (index == word.size())
            return true;
        
        board[y][x] = 0;
        if (x && exist(board, word, x-1, y, index))
            return true;
        
        if (x+1 < board[0].size() && exist(board, word, x+1, y, index))
            return true;
        
        if (y && exist(board, word, x, y-1, index))
            return true;
        
        if (y+1 < board.size() && exist(board, word, x, y+1, index))
            return true;
        
        board[y][x] = c;
        return false;
    }
};