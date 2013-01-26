//
//  topcoder.cpp
//  Algorithm
//
//  Created by Shuai on 9/2/12.
//
//

#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

class TheBrickTowerEasyDivTwo
{
public:
    int find(int redCount, int redHeight, int blueCount, int blueHeight)
    {
        int count = 0;
        int height[redCount*redHeight + blueCount*blueHeight];
        memset(height, 0, sizeof(height));
        
        int i=0;
        for (; i< (redCount > blueCount ? blueCount : redCount); i++) {
            if (height[(redHeight + blueHeight)*i] == 0)
            {
                height[(redHeight + blueHeight)*i] = 1;
                count ++;
            }
            
            if (height[(redHeight + blueHeight)*i + redHeight] == 0)
            {
                height[(redHeight + blueHeight)*i + redHeight] = 1;
                count ++;
            }
            
            if (height[(redHeight + blueHeight)*i + blueHeight] == 0)
            {
                height[(redHeight + blueHeight)*i + blueHeight] = 1;
                count ++;
            }
        }
        
        int extra = redCount > blueCount ? redHeight : blueHeight;
        if (height[(redHeight + blueHeight)*i + extra] == 0)
        {
            height[(redHeight + blueHeight)*i + extra] = 1;
            count ++;
        }
        return count;
    }
};


class TheBrickTowerMediumDivTwo
{
public:
    vector <int> find(vector <int> heights)
    {

        vector<int> ret;
        
        for (int i=0; i<heights.size(); i++) {
            ret.push_back(i);
        }
        
        vector<int>::iterator max = max_element(heights.begin(), heights.end());
        vector<int>::iterator min = min_element(heights.begin(), heights.end());
        
        bool increasing = max > min;
                
        for (int i=1; i<ret.size(); i++) {
            int j=i;
            for (; j>0; j--) {
                if (heights[ret[j]] < heights[ret[j-1]])
                {
                    if (increasing)
                        swap(ret[j], ret[j-1]);
                    else
                        break;
                }
                else if (heights[ret[j]] == heights[ret[j-1]])
                {
                    if (ret[j] < ret[j-1])
                        swap(ret[j], ret[j-1]);
                    else
                        break;
                }
                else
                {
                    if (!increasing)
                        swap(ret[j], ret[j-1]);
                    else
                        break;
                }
            }
        }
        
        return ret;
    }
};

class XorBoardDivTwo
{
public:
    int theMax(vector <string> board)
    {
        int rowCount = board.size();
        int columnCount = board[0].size();
        
        int rowOneCounts[rowCount];
        int columnOneCounts[columnCount];
        int totalOneCount = 0;
        
        for (int i=0; i<rowCount; i++) {
            rowOneCounts[i] = 0;
            for (int j=0; j<columnCount; j++) {
                if (board[i][j] == '1')
                    rowOneCounts[i] ++;
            }
            totalOneCount += rowOneCounts[i];
        }
        
        for (int i=0; i<columnCount; i++) {
            columnOneCounts[i] = 0;
            for (int j=0; j<rowCount; j++) {
                if (board[j][i] == '1')
                    columnOneCounts[i] ++;
            }
        }
        
        int max = 0;
        for (int i=0; i<rowCount; i++) {
            for (int j=0; j<columnCount; j++) {
                int count = totalOneCount + columnCount - 2*rowOneCounts[i] + rowCount - 2*columnOneCounts[j];
                
                if (board[i][j] == '1')
                    count += 2;
                else
                    count -= 2;
                
                if (count > max)
                    max = count;
            }
        }

        return max;
    }
};


class CuttingBitString
{
public:
    int getmin(string S)
    {
        if (S[0] == '0')
            return -1;
        
        vector<string> powof5;
        unsigned long p = 1;
        while (true) {
            string s;
            unsigned long value = p;
            while (value) {
                if (value & 1)
                    s.insert(s.begin(), '1');
                else
                    s.insert(s.begin(), '0');
                value >>= 1;
            }
            
            if (s.size() > S.size())
                break;
            powof5.push_back(s);
            p *= 5;
        }
        
        int solution[S.size()+1];
        memset(solution, 0, sizeof(int)*(S.size()+1));
        solution[0] = 0;
        
        for (int i=1; i<=S.size(); i++) {
            for (int j=0; j<powof5.size(); j++) {
                int size = powof5[j].size();
                if (size <= i)
                {
                    if (solution[i-size] != -1 && S.compare(i-size, size, powof5[j]) == 0)
                    {
                        if (solution[i] == 0)
                            solution[i] = solution[i-size] + 1;
                        else if (solution[i-size] + 1 < solution[i])
                            solution[i] = solution[i-size] + 1;
                    }
                }
                else
                    break;
            }
            
            if (solution[i] == 0)
                solution[i] = -1;
        }
        
        return solution[S.size()];
    }
};


void test()
{
    CuttingBitString cc;
    cout << cc.getmin(string("10011100011110011100111110100001001110011"));
}