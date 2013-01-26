//
//  hash.h
//  Algorithm
//
//  Created by Shuai on 9/23/12.
//
//

#ifndef Algorithm_hash_h
#define Algorithm_hash_h

class HashTable {
    unsigned capacity;
    unsigned size;
    const char** items;
    
    unsigned hashString(const char* str);
    
    HashTable& operator = (const HashTable&);
    HashTable(const HashTable&);
public:
    HashTable(unsigned c)
    : capacity(c), size(0), items(0)
    {
        items = new const char*[c];
    }
    
    ~HashTable();
    
    bool Add(const char* str);
    bool Has(const char* str);
};

#endif
