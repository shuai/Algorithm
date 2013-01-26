//
//  include.h
//  Algorithm
//
//  Created by Shuai on 1/26/13.
//
//

#ifndef Algorithm_include_h
#define Algorithm_include_h

#include <vector>
#include <string>
#include <map>
#include <set>
#include <list>

using namespace std;


struct ListNode {
     int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};


#endif
