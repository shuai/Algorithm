//
//  concatenate_strings.cpp
//  Algorithm
//
//  Created by Shuai on 3/9/13.
//
//

#include "include.h"

// Given M strings of length N, 2 strings a,b can be concatenated if a[1,n] = b[0, n-1]
// Return the maximum number of strings that can be concatenated. No duplicate prefixes
// or postfixes are allowed. Cycle should be ignored.

void concatenate(const vector<string>& input) {
    map<pair<string, bool>, int> map;
    set<pair<string, bool>> head;
    
    for (int i=0; i<input.size(); i++) {
        string left(input[i], 0, input[i].size()-1);
        string right(input[i], 1, input[i].size()-1);

        map.insert(make_pair(make_pair(left, true), i));

        if (map.find(make_pair(left, false)) != map.end())
            map[make_pair(left, false)] = i;
        else
            head.insert(make_pair(left, true));
            
        if (map.find(make_pair(right, true)) != map.end()) {
            map.insert(make_pair(make_pair(right, false), map[make_pair(right, true)]));
            head.erase(head.find(make_pair(right, true)));
        }
        else
            map.insert(make_pair(make_pair(right, false), -1));
    }
    
    for (auto p : head) {
        bool front = true;
        auto pair = p;
        while (map[pair] != -1) {
            if (front)
                cout << input[map[pair]] << endl;
            front = !front;
            pair.first = front ? string(input[map[pair]], 0, input[map[pair]].size()-1)
                                : string(input[map[pair]], 1, input[map[pair]].size()-1);
            pair.second = front;
        }
    }
}

void test_concatenate() {
    vector<string> input;
    input.push_back("abbbc");
    input.push_back("bbbcd");
    input.push_back("cabbb");
    input.push_back("acabb");
    concatenate(input);
}
