//
//  word_ladder.cpp
//  Algorithm
//
//  Created by Shuai on 2/26/13.
//
//

#include "include.h"

class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        map<string, vector<string>> dict_map;
        for (const string& str : dict) {
            for (int i=0; i<str.size(); i++) {
                string tmp(str);
                tmp[i] = '*';
                dict_map[tmp].push_back(str);
            }
        }
        
        struct Node {
            string str;
            int distance;
        };
        
        // true: processed, false: explored
        map<string, bool> seen;
        list<Node> explored;
        explored.push_front(Node{start, 1});
        while (explored.size()) {
            Node current = explored.front();
            explored.pop_front();
            
            for (int i=0; i<current.str.size(); i++) {
                string tmp(current.str);
                tmp[i] = '*';
                if (dict_map.find(tmp) != dict_map.end()) {
                    for (const string& str : dict_map[tmp]) {
                        if (seen.find(str) == seen.end()) {
                            seen.insert(make_pair(str, false));
                            explored.push_back(Node{str, current.distance+1});
                        }
                    }
                }
            }
            
            seen[current.str] = true;
            if (current.str == end)
                return current.distance;
        }
        return 0;
    }
};
