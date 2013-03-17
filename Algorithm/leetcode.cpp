//
//  leetcode.cpp
//  Algorithm
//
//  Created by Shuai on 10/22/12.
//
//


#include <vector>
#include <algorithm>
#include <cassert>
#include <string>
#include <list>
#include <iostream>
#include <map>


struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};


using namespace std;

  struct TreeNode2 {
      int val;
      TreeNode2 *left;
      TreeNode2 *right;
      TreeNode2(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        vector<vector<int> > result;
        if (num.size() < 3)
            return result;
        
        sort(num.begin(), num.end());
        for (unsigned i=0; i<num.size()-2; i++)
        {
            if (i && num[i] == num[i-1])
                continue;
            // Fix a item and then do linear twoSum
            unsigned first = i+1, last=num.size()-1;
            while (first != last)
            {
                if (num[first]+num[last] == -num[i])
                {
                    vector<int> v;
                    v.push_back(num[i]);
                    v.push_back(num[first]);
                    v.push_back(num[last]);
                    result.push_back(v);
                }
                
                if (num[first]+num[last] > -num[i])
                {
                    last --;
                    while (num[last] == num[last+1] && last > first)
                        last --;
                }
                else
                {
                    first ++;
                    while (num[first] == num[first-1] && last > first)
                        first ++;
                }
            }
        }
        
        return result;
    }
    
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        vector<vector<int> > output;
        vector<int> selected;
        
        if (num.size() < 4)
            return output;
        
        sort(num.begin(), num.end());
        bool finish=false;
        fourSumInternal(output, selected, 4, num, 0, target, finish);
        return output;
    }
    
    void fourSumInternal(vector<vector<int> >& output, vector<int>& selected, unsigned count,
                         vector<int> &num, unsigned offset, int target, bool& finish) {
        if (count == 2) {
            unsigned start = offset;
            unsigned end = num.size()-1;
            while (start < end) {
                int sum = num[start]+num[end];
                if (sum < target)
                    start++;
                else if (sum > target)
                    end--;
                else {
                    selected.push_back(num[start]);
                    selected.push_back(num[end]);
                    output.push_back(selected);
                    selected.pop_back();
                    selected.pop_back();
                }
                
                if (start == offset && end == offset+1 && sum >= target)
                    finish = true;
                
                if (sum == target) {
                    start++;
                    while (start < end && num[start] == num[start-1])
                        start++;
                }
            }
            return;
        }
        
        assert(count > 0 && count <= num.size()-offset);
        assert(offset < num.size());
        
        for (unsigned i=offset; i<num.size()-count+1; i++) {
            if (i > offset && num[i] == num[i-1])
                continue;
            selected.push_back(num[i]);
            fourSumInternal(output, selected, count-1, num, i+1, target-num[i], finish);
            selected.pop_back();
            if (finish) {
                finish = i == offset; // there is no point for parent to continue searching
                break;
            }
        }
    }

    string addBinary(string a, string b) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string carry;
        carry.resize(1+max(a.size(), b.size()), '0');
        
        string& longer = a.size() > b.size() ? a : b;
        string& shorter = a.size() > b.size() ? b : a;
        
        bool work_to_do = true;
        while (work_to_do)
        {
            work_to_do = false;
            
            for (unsigned i=0; i<shorter.size(); i++)
            {
                unsigned index_l = longer.size() - i - 1;
                unsigned index_s = shorter.size() - i - 1;
                unsigned index_c = carry.size() - i - 2;
                if (shorter[index_s] == longer[index_l])
                {
                    if (longer[index_l] == '1')
                    {
                        carry[index_c] = '1';
                        work_to_do = true;
                        longer[index_l] = '0';
                    }
                }
                else
                    longer[index_l] = '1';
            }
            
            if (work_to_do)
            {
                shorter = longer;
                longer = carry;
                carry.assign(carry.size(), '0');
            }
        }
        
        unsigned c = 0;
        while (c+1 < longer.size() && longer[c] == '0')
            c++;
        longer.erase(0,c);
        return longer;
    }
    
    vector<string> anagrams(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> output;
        
        vector<pair<string, unsigned> > temp;
        for (unsigned i=0; i<strs.size(); i++)
        {
            string s = strs[i];
            sort(&s[0], &s[s.size()]);
            temp.push_back(make_pair(s, i));
        }
        sort(temp.begin(), temp.end());
        
        bool found=false;
        for (unsigned i=1; i<temp.size(); i++)
        {
            unsigned index=temp[i].second;
            string& s = temp[i].first;
            if (s.size() == temp[i-1].first.size()
                && s == temp[i-1].first)
            {
                if (!found)
                {
                    output.push_back(strs[temp[i-1].second]);
                    found = true;
                }
                output.push_back(strs[temp[i].second]);
            }
            else
                found=false;
        }
        
        
        return output;
    }
    
    
    typedef vector<int>::iterator ITERATOR;
        
    vector<string> generateParenthesis(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        vector<string> output;
        string str;
        generateParenthesis(output, str, n, n);
        return output;
    }
    
    void generateParenthesis(vector<string>& output, string& str, int left, int right) {
        if (left == 0 && right == 0)
            output.push_back(str);
        
        if (left)
        {
            str.push_back('(');
            generateParenthesis(output, str, left-1, right);
            str.resize(str.size()-1);
        }
        
        if (right > left)
        {
            str.push_back(')');
            generateParenthesis(output, str, left, right-1);
            str.resize(str.size()-1);
        }
    }
    
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        vector<Interval>::iterator begin = intervals.end(), end = intervals.begin();
        
        while (end != intervals.end())
        {
            if (end->start <= newInterval.end &&
                end->end >= newInterval.start)
            {
                if (begin == intervals.end())
                {
                    begin = end;
                    newInterval.start = min(newInterval.start, end->start);
                }
                newInterval.end = max(newInterval.end, end->end);
            }
            else
                break;
            
            end ++;
        }
        
        if (begin != end)
            intervals.erase(begin, end);
        
        if (begin == intervals.end())
            intervals.push_back(newInterval);
        else
            intervals.insert(begin, newInterval);
        return intervals;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (s1.size() + s2.size() != s3.size())
            return false;
        if (s1.empty() || s2.empty())
            return s1+s2 == s3;
        
        bool b[s1.size()+1][s2.size()+1];
        b[0][0] = true;
        for (int i=0; i<s1.size(); i++)
        {
            b[i+1][0] = b[i][0] && s1[i] == s3[i];
        }
        
        for (int i=0; i<s2.size(); i++)
        {
            b[0][i+1] = b[0][i] && s2[i] == s3[i];
        }
        
        for (int i=1; i<=s1.size(); i++)
        {
            for (int j=1; j<=s2.size(); j++)
            {
                b[i][j] = false;
                //
            }
        }
        
        return b[s1.size()][s2.size()];
    }
    
    int jump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (n <= 1)
            return 0;
        
        vector<int> layer;
        layer.push_back(0);
        layer.push_back(1);
        
        while (true)
        {
            int max = 0;
            for (int i=layer[layer.size()-2]; i<layer.back(); i++)
            {
                if (i+A[i] > max)
                    max = i+A[i];
            }
            
            max++;
            
            if (max == layer.back())
                return -1;
            if (max >= n)
                return layer.size() - 1;
            
            layer.push_back(max);
        }
        
        return -1;
    }


};

void sort_list(list<pair<string, string> >& str_list)
{
    typedef list<pair<string, string> >::iterator ITERATOR;
    
    map<string, ITERATOR> strings, next;
    ITERATOR pos = str_list.begin();
    while (pos != str_list.end()) {
        strings[pos->first] = pos;
        pos++;
    }
    
    pos = str_list.begin();
    while (pos != str_list.end()) {
        strings[pos->first] = pos;
    }
    
}


