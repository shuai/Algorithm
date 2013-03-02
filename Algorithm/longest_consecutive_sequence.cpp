//
//  longest_consecutive_sequence.cpp
//  Algorithm
//
//  Created by Shuai on 2/26/13.
//
//

#include "include.h"

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        struct Pointer {
            Pointer* next;
            Pointer* prev;
            Pointer() : next(nullptr), prev(nullptr) {}
        };
        
        unordered_map<int, Pointer> map;
        for (int val : num) {
            if (map.find(val) != map.end())
                continue;
            
            auto current = map.insert(make_pair(val, Pointer())).first;
            
            auto prev = map.find(val-1);
            if (prev != map.end()) {
                prev->second.next = &current->second;
                current->second.prev = &prev->second;
            }
            
            auto next = map.find(val+1);
            if (next != map.end()) {
                current->second.next = &next->second;
                next->second.prev = &current->second;
            }
        }
        
        int max_len = 0;
        for (auto entry : map) {
            if (entry.second.prev == nullptr) {
                int count = 1;
                Pointer* ptr = entry.second.next;
                while (ptr) {
                    count++;
                    ptr = ptr->next;
                }
                max_len = max(max_len, count);
            }
        }
        return max_len;
    }
};
