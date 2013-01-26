//
//  merge_list.cpp
//  Algorithm
//
//  Created by Shuai on 10/30/12.
//
//

#include <list>
#include <cassert>
#include <vector>
#include <string>
#include <bitset>
#include <queue>
#include <algorithm>

using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};
 


class heap
{
public:
    heap(unsigned capacity)
    :capacity(capacity)
    {
        assert (capacity);
        size = 0;
        store = new ListNode*[capacity];
        //memset(store, 0, size*sizeof(*store));
    }
    
    ~heap()
    {
        size = 0;
        delete[] store;
        store = 0;
        capacity = 0;
    }
    
    bool empty() {return size == 0;}
    ListNode* extract()
    {
        assert(size);
        ListNode* ret = store[0];
        swap(store[0], store[size-1]);
        size--;
        if (size > 1)
            heapify(0);
        return ret;
    }
    
    void insert(ListNode* node)
    {
        assert(size < capacity);
        store[size++] = node;
        heapify(size-1);
    }
    
private:
    int parent(int i) { return (i-1)/2; }
    int left(int i) { return 2*i+1; }
    int right(int i) { return 2*i+2; }
    void heapify(int i)
    {
        while (i>0 && store[parent(i)]->val > store[i]->val)
        {
            swap(store[i], store[parent(i)]);
            i = parent(i);
        }
        
        while (i < size)
        {
            int minimum = i;
            if (left(i) < size && store[left(i)]->val < store[minimum]->val)
                minimum = left(i);
            
            if (right(i) < size && store[right(i)]->val < store[minimum]->val)
                minimum = right(i);
            
            if (minimum == i)
                break;
            
            swap(store[i], store[minimum]);
            i = minimum;
        }
    }
    
    ListNode** store;
    unsigned size;
    unsigned capacity;
};

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        ListNode* head = NULL;
        ListNode* tail = NULL;
        if (lists.empty())
            return tail;
        
        heap h(lists.size());
        
        for (int i=0; i<lists.size(); i++)
        {
            if (lists[i])
                h.insert(lists[i]);
        }
        
        while (!h.empty())
        {
            ListNode* node = h.extract();
            
            if (tail)
                tail->next = node;
            if (!head)
                head = node;
            tail = node;
            
            if (node->next)
                h.insert(node->next);
        }
        
        return head;
    }
    
    static string minWindow(string S, string T) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            if (S.empty() || T.empty())
                return "";
            
            int counter[255];
            int negative = T.size();
            memset(counter, 0, sizeof(counter));
            for (int i=0; i<T.size(); i++)
            {
                counter[T[i]] --;
            }
            
            int start = 0, count = INT_MAX, s = 0;
            for (int i=0; i<S.size(); i++)
            {
                counter[S[i]] ++;
                if (counter[S[i]] > 0)
                {
                    while (s < S.size() && counter[S[s]] > 0)
                    {
                        counter[S[s]] --;
                        s++;
                    }
                }
                else
                {
                    negative --;
                }
                
                if (i-s+1 < count && negative == 0)
                {
                    count = i-s+1;
                    start = s;
                }
            }
            if (count == INT_MAX)
                return "";
            
            return string(S.c_str() + start, count);
        }
    
    static void add(string& num, unsigned value, unsigned bit)
    {
        string x;
        
        while (value)
        {
            assert(bit < num.size());
            value = value + num[bit] - '0';
            num[bit] = '0' + value % 10;
            value /= 10;
            bit ++;
        }
    }
    
    static string multiply(string num1, string num2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (num1.empty() || num2.empty())
            return "";
        
        string result;
        result.assign(num1.size() + num2.size(), '0');
        
        unsigned carry = 0, bit = 0;
        string::const_reverse_iterator it = num1.rbegin();
        while (it != num1.rend())
        {
            unsigned bit2 = 0;
            string::const_reverse_iterator it2 = num2.rbegin();
            while (it2 != num2.rend())
            {
                int product = (*it-'0')*(*it2-'0') + result[bit+bit2] - '0' + carry;
                result[bit + bit2] = '0' + product % 10;
                carry = product / 10;
                it2 ++;
                bit2 ++;
            }
            add(result, carry, bit+bit2);
            carry = 0;
            
            it ++;
            bit ++;
        }
        
        int i=result.size()-1;
        for (; i>0; i--)
            if (result[i] != '0')
                break;
        result.erase(result.begin() + i + 1, result.end());
        std::reverse(result.begin(), result.end());
        return result;
    }
    
    };

int test_merge()
{
    ListNode* list = new ListNode(1);
    list->next = new ListNode(2);
    list->next->next = new ListNode(5);
    
    vector<ListNode*> v;
    v.push_back(list);
    
    string ret = Solution::minWindow("ab", "b");
    priority_queue<int> x;


    string te = Solution::multiply("9", "9");
}