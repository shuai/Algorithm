//
//  bigfile.cpp
//  Algorithm
//
//  Created by Shuai on 9/28/12.
//
//

#include <fstream>
#include <vector>
#include <cstdio>
#include <queue>
#include <iostream>
#include <cassert>

using namespace std;

string external_sort(const char* file)
{
    fstream f(file);
    vector<string> cache_files;
    string output;
    
    const unsigned cache = 1 << 20;
    
    unsigned* numbers = new unsigned [cache];

    try {
        while (f) {
            unsigned index = 0;
            while (f && index < cache) {
                f >> numbers[index++];
            }
            sort(numbers, numbers+index);
            string temp = tmpnam(NULL);
            fstream cache_file(temp.c_str(), ios::out);
            cache_file.exceptions(ios::failbit | ios::badbit);
            index = 0;
            while (index < cache && cache_file << numbers[index++] << endl) {
                ;
            }
            cache_files.push_back(temp);
        }
        
        assert(cache_files.size());
        priority_queue<pair<unsigned, unsigned>, vector<pair<unsigned, unsigned> >, greater<pair<unsigned, unsigned> > > heap;
        vector<fstream*> files;
        output = tmpnam(NULL);
        fstream merge_file(output.c_str(), ios::out);
        for (size_t i=0; i<cache_files.size(); i++) {
            fstream* f = new fstream(cache_files[i].c_str());
            files.push_back(f);
        }
        
        for (size_t i=0; i<files.size(); i++) {
            unsigned value;
            assert(*files[i]);
            *files[i] >> value;
            heap.push(make_pair(value, i));
        }
        
        while (heap.size()) {
            pair<unsigned, unsigned> min = heap.top();
            heap.pop();
            merge_file << min.first << endl;
            if (*files[min.second]) {
                *files[min.second] >> min.first;
                heap.push(min);
            }
        }
        merge_file.flush();
        cout << "output: " << output << endl;
        //merge_file.seekg(0);
        
//        fstream merge_file_read(output.c_str());
//        while (merge_file_read) {
//            unsigned num;
//            merge_file_read >> num;
//            cout << num << endl;
//        }

    } catch (const std::exception& e) {
        
    }

    for (size_t i=0; i<cache_files.size(); i++) {
        remove(cache_files[i].c_str());
    }

    
    return output;
}

//6、 给定a、b两个文件，各存放50亿个url，每个url各占64字节，内存限制是4G，让你找出a、b文件共同的url？



void test_external_sort()
{
    string fname = tmpnam(NULL);
    
    {
        fstream f(fname.c_str(), ios::out);
        for (size_t i=0; i<1000000; i++) {
            f << rand()%1000000 << endl;
        }
        
        f.flush();

        if (f.fail()) {
            cout << "fail!" << endl;
        }
    }
    
    cout << "sort begin" << endl;
    fname = external_sort(fname.c_str());
    cout << "sort done" << endl;

    
    fstream f(fname.c_str(), ios::in);
    
    if (!f) {
        cout << "fail the hell" << endl;
    }
}
