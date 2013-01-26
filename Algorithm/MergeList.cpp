//
//  MergeList.cpp
//  Algorithm
//
//  Created by Shuai on 1/20/13.
//
//
#include <vector>
#include <set>

using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(0) {}
  };
 

class compListNode {
public:
bool operator ()(const ListNode* left, const ListNode* right) const {
    return left->val < right->val;
}
};

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        ListNode head(0), *last = &head;
        
        multiset<ListNode*, compListNode> heap;
        for (int i=0; i<lists.size(); i++) {
            heap.insert(lists[i]);
        }
        
        while (heap.size()) {
            multiset<ListNode*, compListNode>::iterator min = heap.begin();
            last->next = new ListNode((*min)->val);
            last = last->next;
            if ((*min)->next)
                heap.insert((*min)->next);
            heap.erase(min);
        }
        return head.next;
    }
};