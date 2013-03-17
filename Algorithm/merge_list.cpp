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
#include <cmath>

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
