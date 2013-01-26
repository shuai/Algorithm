//
//  string_algorithm.cpp
//  Algorithm
//
//  Created by  on 7/21/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <list>
using namespace std;

void generateP(const char* str, unsigned* p);

int kmp(const char* str1, const char* str2)
{
    unsigned size1 = strlen(str1); 
    unsigned size2 = strlen(str2);
    unsigned p[size2];
    generateP(str2, p);
    
    cout << "Searching " << str2 << " in " << str1 << endl ;
    cout << "Prefix array: ";
    for (int i=0; i<size2; i++) {
        cout << " " << p[i];
    }
    cout << endl;
    
    unsigned ptr1 = 0, ptr2 = 0;
    
    while (ptr1 < size1 && ptr2 < size2) {
        if (str1[ptr1] != str2[ptr2]) {
            if (ptr2 != 0)
                ptr2 = p[ptr2-1];
            else {
                ptr1++;
            }
        }
        else {
            ptr1++;
            ptr2++;
        }
    }
    
    if (ptr2 == size2)
        cout << " Found, " << str1 + ptr1-size2 << endl;
    else {
        cout << "Not found" << endl;
    }
    return 0;
}

void generateP(const char* str, unsigned* p)
{
    unsigned size = strlen(str);
    int ptr = -1;
    
    p[0] = 0;
    for (unsigned i=1; i<size; i++) {
        while (ptr >= 0 && str[ptr+1] != str[i]) {
            ptr = p[ptr] - 1;
        }
        
        if (str[ptr+1] == str[i])
            ptr++;
        
        p[i] = ptr + 1;
    }
}

void permutation(char* input, int count, int offset)
{
    for (int i=0; i<count; i++) {
        swap(input[offset], input[offset+i]);
        if (count > 1)
            permutation(input, count-1, offset+1);
        else
            printf("%s\n", input);
        swap(input[offset], input[offset+i]);
    }
}

void test_permutation()
{
    char str[] = "abc";
    permutation(str, sizeof(str)-1, 0);
}

bool string_mix(const char* string, const char* str1, const char* str2)
{
    if (!*string) {
        return !*str1 && !*str2;
    }

    if (*string == *str1 && string_mix(string+1, str1+1, str2)) {
        return true;
    }
    
    return *string == *str2 && string_mix(string+1, str1, str2+1);
}

void test_string_mix()
{
    const char* str1 = "abcd";
    const char* str2 = "adb"; 
    
    cout << "Test string mix: " << string_mix("abacdbd", str1, str2) << endl;
}

class TreeNode
{
public:
    TreeNode()
    {
        memset(children, 0, sizeof(children));
        complete = false;
    }
    TreeNode* children[128];
    bool complete;
};

void add_suffix(TreeNode* node, const char* str)
{
    if (!*str) {
        node->complete = true;
        return;
    }
    
    if (!node->children[*str]) {
        node->children[*str] = new TreeNode;
    }
    
    return add_suffix(node->children[*str], str+1);
}

string leftmost_path(TreeNode* node)
{
    string result;
    while (node) {
        
        bool found = false;
        for (int i=127; i>=0; i--) {
            if (node->children[i]) {
                result.push_back(i);
                node = node->children[i];
                found = true;
                break;
            }
        }
        
        if (!found) {
            break;
        }
    }
    return result;
}

void delete_tree(TreeNode* node)
{
    
}

string largest_suffix(const string& str)
{
    TreeNode* root = new TreeNode;
    
    for (size_t i=0; i<str.size(); i++) {
        add_suffix(root, str.c_str()+i);
    }
    
    string largest = leftmost_path(root);
    delete_tree(root);
    
    return largest;
}

string largest_suffix2(const string& str)
{
    list<unsigned> candidates;
    for (unsigned i=0; i<str.size(); i++) {
        candidates.push_back(i);
    }
    
    unsigned index = 0;
    while (candidates.size() > 1) {
        char largest = 0;
        int last_index = -1;
        list<unsigned>::iterator it = candidates.begin();
        while (it != candidates.end()) {
            char curr_char = str[*it+index];
            assert(curr_char >= 0);
            
            bool adjacent = last_index != -1 && last_index + 1 == *it;

            if (curr_char < largest) {
                it = candidates.erase(it);
            }
            else if (curr_char > largest){
                largest = curr_char;
                candidates.erase(candidates.begin(), it);
                it ++;
            }
            else
            {
                last_index = *it + index;

                if (adjacent){
                    cout << "adjacent string, ignore" << endl;
                    it = candidates.erase(it);
                }
                else
                    it ++;
            }
        }
        index ++;
    }
    return str.c_str() + candidates.front();
}


void test_largest_suffix()
{
    for (size_t i=0; i<100; i++) {
        string str;
        unsigned count = rand()%10 + 10;
        for (size_t j = 0; j<count; j++) {
            str.push_back(rand()%3 + 'a');
        }
        
        string result1 = largest_suffix(str);
        string result2 = largest_suffix2(str);
        
        if (result1 != result2) {
            cout << "test: " << str << endl;
            cout << "correct: " << result1 << endl;
            cout << "wrong: " << result2 << endl;
        }

    }
}