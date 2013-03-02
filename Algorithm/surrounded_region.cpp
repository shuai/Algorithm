//
//  surrounded_region.cpp
//  Algorithm
//
//  Created by Shuai on 2/26/13.
//
//

#include "include.h"


class Solution {
public:
    void solve(vector<vector<char>> &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        for (int row=0; row<board.size(); row++)
            for (int col=0; col<board[0].size(); col++) {
                if (board[row][col] == 'O') {
                    bool captured;
                    explore(board, row, col, captured, false);
                    if (captured)
                        explore(board, row, col, captured, true);
                }
            }
        
        for (int row=0; row<board.size(); row++)
            for (int col=0; col<board[0].size(); col++)
                if (board[row][col] == ' ')
                    board[row][col] = 'O';
        
    }
    
    void explore(vector<vector<char>> &board, int row, int col, bool& captured, bool flip) {
        captured = true;
        if (row == 0 || row == board.size()-1 || col == 0 || col == board[0].size()-1)
            captured = false;
        
        if (flip)
            board[row][col] = 'X';
        else
            board[row][col] = ' ';
        
        bool left = true, right = true, top = true, bottom = true;
        if (row != 0 && board[row-1][col] == 'O')
            explore(board, row-1, col, top, flip);
        if (row != board.size()-1 && board[row+1][col] == 'O')
            explore(board, row+1, col, bottom, flip);
        if (col != 0 && board[row][col-1] == 'O')
            explore(board, row, col-1, left, flip);
        if (col != board[0].size()-1 && board[row][col+1] == 'O')
            explore(board, row, col+1, right, flip);
        captured = captured && left && right && top && bottom;
    }
};