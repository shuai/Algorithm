//
//  list.h
//  Algorithm
//
//  Created by Shuai on 9/7/12.
//
//

#ifndef Algorithm_list_h
#define Algorithm_list_h

struct ListNode
{
    ListNode(int k){
        key = k;
        next = 0;
    }
    int key;
    struct ListNode* next;
};

#endif
