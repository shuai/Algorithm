//
//  N-queen.cpp
//  Algorithm
//
//  Created by Shuai on 11/1/12.
//
//
#include <vector>
#include <string>
#include <cassert>
#include <iostream>
#include <set>

using namespace std;

struct Queen
{
    Queen(unsigned x, unsigned y) : x(x), y(y) {}
    unsigned x;
    unsigned y;
    
    bool operator < (const Queen& right) const
    {
        return x < right.x || (x == right.x && y < right.y);
    }
    
    bool operator == (const Queen& right) const
    {
        return x == right.x && y == right.y;
    }
    
    bool attack(unsigned _x, unsigned _y)
    {
        return x == _x || y == _y || x + _y == y + _x || x + y == _x + _y;
    }
};

class Solution {
public:
    bool rotateBoard90(const vector<Queen>& stack, vector<Queen>& rotated)
    {
        rotated.assign(stack.begin(), stack.end());
        for (int i=0; i<rotated.size(); i++)
        {
            swap(rotated[i].x, rotated[i].y);
        }
        sort(rotated.begin(), rotated.end());
        if (rotated == stack)
            rotated.clear();
        return !rotated.empty();
    }
    
    bool mirror(const vector<Queen>& stack, vector<Queen>& rotated, bool horizontal)
    {
        rotated.assign(stack.begin(), stack.end());
        for (int i=0; i<rotated.size(); i++)
        {
            if (horizontal)
                rotated[i].y = rotated.size() - rotated[i].y - 1;
            else
                rotated[i].x = rotated.size() - rotated[i].x - 1;
        }
        sort(rotated.begin(), rotated.end());
        if (rotated == stack)
            rotated.clear();
        return !rotated.empty();
    }
    
    void produceMirrors(set<vector<Queen> >& candidates, const vector<Queen>& stack)
    {
        candidates.insert(stack);
        
        vector<Queen> m;
        if (mirror(stack, m, true))
            candidates.insert(m);
        
        
        if (mirror(stack, m, false))
        {
            candidates.insert(m);
            vector<Queen> b;
            if (mirror(m, b, true) && b != stack)
                candidates.insert(b);
        }
    }
    
    void generateBoard(vector<vector<string> >& ret, const vector<Queen>& stack)
    {
        vector<string> result(stack.size());
        for (int i=0; i<result.size(); i++)
            result[i].assign(stack.size(), '.');
        
        for (int i=0; i<stack.size(); i++)
        {
            assert(i == stack[i].x);
            result[i][stack[i].y] = 'Q';
        }
        
        ret.push_back(result);
    }
    
    void produceVariations(vector<vector<string> >& ret, const vector<Queen>& stack)
    {
        set<vector<Queen> > candidates;
        produceMirrors(candidates, stack);
        
        vector<Queen> rotated;
        if (rotateBoard90(stack, rotated))
            produceMirrors(candidates, rotated);
        
        set<vector<Queen> >::iterator it = candidates.begin();
        while (it != candidates.end()) {
            generateBoard(ret, *it);
            it++;
        }
    }
    
    vector<vector<string> > solveNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        vector<vector<string> > ret;
        if (n < 1)
            return ret;
        
        vector<Queen> stack;
        int row = 0;
        while (row != -1)
        {
            assert (row == stack.size() || row + 1 == stack.size());
            
            int end = row == 0 ? (n+1)/2 : n;
            int start = row == stack.size() ? 0 : stack[row].y + 1;
            
            int column = start;
            for (; column<end; column++)
            {
                bool attack = false;
                for (int i=0; i<row; i++)
                {
                    if (stack[i].attack(row, column))
                    {
                        attack = true;
                        break;
                    }
                }
                
                if (attack)
                    continue;
                
                if (row == stack.size())
                    stack.push_back(Queen(row, column));
                else
                    stack[row].y = column;
                
                row ++;
                break;
            }
            
            // backtrack if reaching end
            if (column == end)
            {
                if (row + 1 == stack.size())
                    stack.pop_back();

                row --;
            }
            else if (row == n)
            {
                // found one result, output all its varations
                //produceVariations(ret, stack);
                row --;
            }
        }
        
        return ret;
    }
};

void test_nqueen()
{
    Solution ss;
    vector<vector<string> > result = ss.solveNQueens(13);
    
    cout << result.size() << endl;
    
    for (int i=0; i<result.size(); i++) {
        for (int j =0; j<result[i].size(); j++) {
            cout << result[i][j] << endl;
        }
        cout << "--------" << endl;
    }
    
}