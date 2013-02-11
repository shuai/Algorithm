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
    
    void nextPermutation(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (num.empty())
            return;
        
        int max = INT_MIN;
        int index = num.size() - 1;
        while (index >= 0 && num[index] >= max)
        {
            max = num[index];
            index --;
        }
        
        if (index != -1)
        {
            int bigger = index + 1;
            while (bigger + 1 < num.size() && num[bigger+1] > num[index])
                bigger ++;
            swap(num[index], num[bigger]);
        }
        
        int first = index + 1, last = num.size() - 1;
        while (first < last)
        {
            swap(num[first], num[last]);
            first ++;
            last --;
        }
    }
    
    int threeSumClosest(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (num.size() < 3)
            return -1;
        
        int result = 0;
        bool result_set = false;
        sort(num.begin(), num.end());
        for (unsigned i=0; i<num.size()-2; i++)
        {
            if (i && num[i] == num[i-1])
                continue;
            // Fix a item and then do linear twoSum
            unsigned first = i+1, last=num.size()-1;
            while (first != last)
            {
                int sum = num[first]+num[last]+num[i];
                if (sum == target)
                    return target;
                
                if (!result_set || abs(sum-target) < abs(result-target))
                    result = sum;
                
                result_set = true;
                
                if (sum > target)
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
//    ListNode *reverseKGroup(ListNode *head, int k) {
//        // Start typing your C/C++ solution below
//        // DO NOT write int main() function
//        
//        if (!head)
//            return NULL;
//        
//        ListNode sentinel(0);
//        sentinel.next = head;
//        
//        ListNode* prev = &sentinel, *current = head;
//        
//        while (current)
//        {
//            // reverse the maximum k length list starting from current
//            ListNode* sub_tail = current, *sub_head = NULL;
//            
//            int count = 0;
//            while (current && count < k)
//            {
//                ListNode* sub_next = current->next;
//                current->next = sub_head;
//                sub_head = current;
//                current = sub_next;
//                count ++;
//            }
//            
//            if (count == k)
//            {
//                prev->next = sub_head;
//                sub_tail->next = current;
//                prev = sub_tail;
//            }
//            else
//            {
//                k = count;
//                current = sub_head;
//            }
//        }
//        return sentinel.next;
//    }
    
    bool isScramble(string origin, string scramble) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (origin.empty())
            return true;
        
        // first, last, index_in_origin
        bool dp[origin.size()][origin.size()][origin.size()];
        
        // initialize length 1 str
        for (int i = 0; i < scramble.size(); i ++)
            for (int k = 0; k < origin.size(); k++)
                dp[i][i][k] = scramble[i] == origin[k];
        
        for (int len = 2; len <= origin.size(); len ++)
        {
            for (int start = 0; start <= origin.size() - len; start ++)
            {
                for (int index_origin = 0; index_origin <= origin.size() - len; index_origin ++)
                {
                    dp[start][start+len-1][index_origin] = false;
                    for (int partition = start; partition < start + len - 1; partition ++)
                    {
                        if ((dp[start][partition][index_origin]
                            && dp[partition+1][start+len-1][index_origin+partition-start+1]) ||
                            (dp[start][partition][index_origin+len+start-partition-1]
                            && dp[partition+1][start+len-1][index_origin])
                            )
                        {
                            dp[start][start+len-1][index_origin] = true;
                            break;
                        }
                    }
                }
            }
        }
        
        return dp[0][origin.size()-1][0];
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
    
//    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
//        // Start typing your C/C++ solution below
//        // DO NOT write int main() function
//        ListNode* tail = NULL, *head = NULL;
//        bool carry = false;
//        while (l1 || l2 || carry)
//        {
//            int value = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + (carry ? 1 : 0);
//            carry = value > 9;
//            if (carry)
//                value -= 10;
//            ListNode* node = new ListNode(value);
//            if (tail)
//                tail->next = node;
//            tail = node;
//            if (!head)
//                head = tail;
//            
//            l1 = l1 ? l1->next : NULL;
//            l2 = l2 ? l2->next : NULL;
//        }
//        
//        return head;
//    }
    
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
    
    
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> selected;
        vector<vector<int> > output;
        
        sort(candidates.begin(), candidates.end());
        
        combinationSumInternal(output, selected, candidates, 0, target);
        return output;
    }
    
    void combinationSumInternal(vector<vector<int> >& output, vector<int>& selected,
                                vector<int> &candidates, unsigned offset, int target) {
        for (unsigned i=offset; i<candidates.size(); i++)
        {
            if (i>offset && candidates[i] == candidates[i-1])
                continue;
            
            unsigned count = 0;
            
            do {
                count++;
                selected.push_back(candidates[i]);
                target -= candidates[i];
                
                if (target == 0)
                    output.push_back(selected);
                else if (target > candidates[i])
                    combinationSumInternal(output, selected, candidates, i+1, target);
            } while (target >= candidates[i]);
            
            target += count*candidates[i];
            
            selected.erase(selected.begin() + selected.size() - count, selected.end());
        }
    }
    
    TreeNode2 *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (inorder.empty() || postorder.empty())
            return NULL;
        
        return buildTree(inorder, 0, inorder.size(), postorder, 0, postorder.size());
    }
    
    TreeNode2 *buildTree(vector<int> &inorder, unsigned offset, unsigned count,
                        vector<int> &postorder, unsigned offset2, unsigned count2) {
        
        int root = postorder[offset2+count2-1];
        vector<int>::iterator pos = find(inorder.begin()+offset, inorder.begin()+offset+count,root);
        unsigned left = pos-inorder.begin()-offset;
        unsigned right = inorder.begin()+offset+count-pos-1;
        
        TreeNode2* node = new TreeNode2(root);
        node->left = left ? buildTree(inorder, offset, left, postorder, offset2, left) : NULL;
        if (right)
            node->right = buildTree(inorder, offset+left+1, right, postorder, offset2+left, right);
        return node;
    }
    
    TreeNode2 *buildTree2(vector<int> &preorder, vector<int> &inorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return NULL;
        
        if (preorder.empty() || inorder.empty())
            return NULL;
        return buildTree(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
    }
    
    typedef vector<int>::iterator ITERATOR;
    
    TreeNode2* buildTree(ITERATOR pre_start, ITERATOR pre_end, ITERATOR in_start, ITERATOR in_end)
    {
        int root_val = *pre_start;
        ITERATOR it = find(in_start, in_end, root_val);
        int left = it - in_start;
        
        TreeNode2* node = new TreeNode2(root_val);
        if (left)
            node->left = buildTree(pre_start+1, pre_start+1+left, in_start, it);
        if (it+1 < in_end)
            node->right = buildTree(pre_start+left+1, pre_end, it+1, in_end);
        return node;
    }
    
    int maxArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int max_capacity = 0;
        
        if (height.size())
        {
            vector<pair<int, int> > tmp;
            for (unsigned i=0; i<height.size(); i++)
                tmp.push_back(make_pair(height[i],i));
            
            sort(tmp.rbegin(), tmp.rend());
            int min_x = tmp.front().second, max_x = min_x;
            unsigned i=1;
            while (i<height.size())
            {
                int capacity = tmp[i].first*max(abs(tmp[i].second-min_x), abs(tmp[i].second-max_x));
                if (capacity > max_capacity)
                    max_capacity = capacity;
                min_x = min(min_x, tmp[i].second);
                max_x = max(max_x, tmp[i].second);
                i++;
            }
        }
        
        return max_capacity;
    }
        
    int numDistinct(string T, string S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int num[S.size()+1][T.size()+1];
        for (int i=0; i<=T.size(); i++)
        {
            num[0][i] = 1;
        }
        
        for (int i=1; i<=S.size(); i++)
        {
            num[i][0] = 0;
            for (int j=1; j<=T.size()-(S.size()-i); j++)
            {
                if (S[i-1] == T[j-1])
                    num[i][j] = num[i][j-1] + num[i-1][j-1];
                else
                    num[i][j] = num[i][j-1];
            }
        }
        
        return num[S.size()][T.size()];
    }
    
    int divide(int _dividend, int _divisor) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        assert(_divisor);
        
        long long dividend = _dividend;
        long long divisor = _divisor;
        
        bool negative = (divisor < 0) != (dividend < 0);
        if (dividend < 0)
            dividend = -dividend;
        if (divisor < 0)
            divisor = -divisor;
        
        long long n = 0;
        long long d = divisor;
        long long c = 1;
        while (dividend >= divisor)
        {
            while (d <= (dividend >> 1) )
            {
                d <<= 1;
                c <<= 1;
            }
            
            while (d > dividend)
            {
                d >>= 1;
                c >>= 1;
            }
            
            dividend -= d;
            n += c;
        }
        return negative ? -n : n;
    }
        
    
    void flatten(TreeNode2 *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        TreeNode2* tail = NULL;
        vector<TreeNode2*> stack;
        if (root)
            stack.push_back(root);
        
        while (stack.size())
        {
            TreeNode2* node = stack.back();
            stack.pop_back();
            
            if (node->right)
                stack.push_back(node->right);
            if (node->left)
                stack.push_back(node->left);
            
            node->left = tail;
            if (tail)
                tail->right = node;
            tail = node;
        }
    }
    
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
    
    int largestRectangleArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int area = 0;
        vector<pair<unsigned, unsigned> > candidates;
        
        for (int i=0; i<height.size(); i++)
        {
            unsigned start = i;
            for (int k=0; k<candidates.size(); k++)
            {
                if (candidates[k].first <= height[i])
                {
                    int a = (i - candidates[k].second + 1)*candidates[k].first;
                    if (a > area)
                        area = a;
                }
                else
                {
                    start = candidates[k].second;
                    candidates.erase(candidates.begin()+k, candidates.end());
                    break;
                }
            }
            
            if (candidates.empty() || candidates.back().first < height[i])
            {
                candidates.push_back(make_pair(height[i], start));
                
                int a = (i - start + 1)*height[i];
                if (a > area)
                    area = a;
            }
        }
        
        return area;
    }
    
    int lengthOfLastWord(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int len = 0;
        
        
        if (s)
        {
            const char* last_space = s;
            const char* space = NULL;
            while (*s)
            {
                if (*s == ' ')
                {
                    if (!space)
                    {
                        len = s - last_space;
                        last_space = NULL;
                    }
                    space = s;
                }
                else
                {
                    if (!last_space)
                        last_space = s;
                    
                    space = NULL;
                }
                s++;
            }
            
            
            if (!space && last_space)
                len = s - last_space;
        }
        return len;
    }
    
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (m == 0 && n == 0)
            return 0;
        
        int left, right;
        if ((m + n)&1)
        {
            left = right = (m+n+1)/2;
        }
        else
        {
            left = (m+n)/2;
            right = left + 1;
        }
        return (findKth(A,m,B,n,left) + findKth(A,m,B,n,right))/2;
    }
    
    int findKth(int* A, int m, int* B, int n, int k)
    {
        if (m == 0)
            return B[k-1];
        if (n == 0)
            return A[k-1];
        
        if (k == m + n)
            return max(A[m-1], B[n-1]);
        
        int pivot_a = min(m-1, k/2);
        int pivot_b = k - pivot_a - 1;
        if (pivot_b > n - 1)
        {
            pivot_b = n - 1;
            pivot_a = k - pivot_b - 1;
        }
        
        int a_1 = pivot_a > 0 ? A[pivot_a - 1] : INT_MIN;
        int b_1 = pivot_b > 0 ? B[pivot_b - 1] : INT_MIN;
        
        if (A[pivot_a] <= B[pivot_b] && A[pivot_a] >= b_1)
            return A[pivot_a];
        if (B[pivot_b] < A[pivot_a] && B[pivot_b] >= a_1)
            return B[pivot_b];
        
        if (A[pivot_a] < B[pivot_b])
        {
            return findKth(A + pivot_a + 1, m - pivot_a - 1, B, pivot_b + 1, k - pivot_a - 1);
        }
        else
        {
            return findKth(B + pivot_b + 1, n - pivot_b - 1, A, pivot_a + 1, k - pivot_b - 1);
        }
    }
    

};

void test_solution()
{
    Solution s;
    vector<Interval> input;
    input.push_back(Interval(1,5));
    s.insert(input, Interval(6, 8));
    
    
//    Solution s;
//    vector<int> input;
//    input.push_back(0);
//    input.push_back(0);
//    input.push_back(0);
//    input.push_back(0);
//    vector<vector<int> > result = s.fourSum(input, 2);
//    
//    string x = s.addBinary("1", "111");
//    
//    vector<int> input2;
//    input2.push_back(7);
//    input2.push_back(3);
//    input2.push_back(2);
    
//    vector<vector<int> > ret = s.combinationSum(input2, 18);
//    
//    int A[] = {1,1000};
//    int num = s.firstMissingPositive(A, 2);
//    cout << num << endl;
//    
//    TreeNode2 t1(1);
//    TreeNode2 t2(2);
//    t1.left = &t2;
//    
//    s.flatten(&t1);
//    
//    vector<int> xx;
//    xx.insert(xx.begin(), 0);
//    cout << xx.size() << endl;
    
    int A[] = {1};
    int B[] = {2,3};
    double r = s.findMedianSortedArrays(A, 1, B, 2);
}

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


