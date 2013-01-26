//
//  merge_interval.cpp
//  Algorithm
//
//  Created by Shuai on 1/23/13.
//
//

#include "include.h"

bool comp(const Interval& left, const Interval& right) {
    return left.start < right.start;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (intervals.empty())
            return intervals;
        
        sort(intervals.begin(), intervals.end(), comp);
        
        int last = 0;
        for (int i=0; i<intervals.size(); i++) {
            if (intervals[last].start <= intervals[i].end &&
                intervals[last].end >= intervals[i].start){
                intervals[last].end = max(intervals[last].end, intervals[i].end);
            } else {
                last++;
                if (last != i)
                    intervals[last] = intervals[i];
            }
        }
        
        intervals.resize(last+1);
        return intervals;
    }
};