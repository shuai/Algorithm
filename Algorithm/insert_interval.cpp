//
//  insert_interval.cpp
//  Algorithm
//
//  Created by Shuai on 1/23/13.
//
//

#include "include.h"

class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        vector<Interval>::iterator first = intervals.end(),
        last = intervals.end(),
        pos = intervals.begin(),
        insert_pos = intervals.end();
        
        while (pos != intervals.end()) {
            if (pos->start <= newInterval.end && pos->end >= newInterval.start) {
                if (first == intervals.end())
                    first = pos;
                last = pos;
                newInterval.start = min(newInterval.start, pos->start);
                newInterval.end = max(newInterval.end, pos->end);
            }
            
            if (pos->start > newInterval.end && insert_pos == intervals.end())
                insert_pos = pos;
            
            pos++;
        }
        
        
        if (first != intervals.end()) {
            if (first != last) {
                intervals.erase(first+1, last+1);
            }
            *first = newInterval;
        } else
            intervals.insert(insert_pos, newInterval);
        
        return intervals;
    }
};