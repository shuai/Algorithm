//
//  hash.cpp
//  Algorithm
//
//  Created by Shuai on 9/23/12.
//
//

#include "hash.h"
#include <cstring>
#include <iostream>

using namespace std;

bool HashTable::Add(const char* str)
{
    if (*str == 0 || size == capacity) {
        return false;
    }
    
    unsigned hash = hashString(str);
    unsigned index = hash % capacity;

    unsigned i = 1;
    while (items[index]) {
        index += i*i;
        i++;
    }
    
    const char* str2 = strdup(str);
    items[index] = str2;
    size ++;
    return true;
}

bool HashTable::Has(const char* str)
{
    if (*str == 0 || size == 0) {
        return false;
    }
    
    unsigned hash = hashString(str);
    unsigned index = hash % capacity;
    
    unsigned i = 1;
    while (items[index]) {
        if (strcmp(items[index], str) == 0) {
            return true;
        }
        
        index += i*i;
        i++;
    }
    
    return false;
}

unsigned HashTable::hashString(const char* str)
{
    unsigned hash = 0;
    while (*str != 0) {
        hash = hash*131 + *str++;
    }
    return hash;
}

HashTable::~HashTable()
{
    cout << "deleting hash set: ";
    for (int i=0; i<capacity; i++) {
        if (items[i]) {
            cout << items[i] << " ";
        }
        
        delete items[i];
        items[i] = NULL;
    }
    cout << endl;
}

void test_hash()
{
    HashTable hash(131);
    const char* str[] = {
        "test",
        "big",
        "apple",
        "google",
        "microsoft",
        "technology",
        "what?"
    };
    
    for (int i=0; i<sizeof(str)/sizeof(const char*); i++) {
        hash.Add(str[i]);
    }
}
