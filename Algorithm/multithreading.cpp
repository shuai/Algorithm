//
//  multithreading.cpp
//  Algorithm
//
//  Created by Shuai on 9/22/12.
//
//

#include "include.h"
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>

using namespace std;

std::mutex m;
list<int> value;

void thread_read() {
    int last = -1;
    while(true) {
        lock_guard<mutex> guard(m);
        if (value.size()) {
            cout << " " << value.front() << endl;
            assert(value.front() > last);
            last = value.front();
            value.pop_front();
        }
    }
}

void thread_write() {
    for (int i=0; i<1000; i++) {
        this_thread::sleep_for(chrono::milliseconds(50));
        lock_guard<mutex> guard(m);
        value.push_back(i);
    }
    
}

void test_thread() {
    std::thread x(thread_read);
    thread y(thread_write);
    
    condition_variable cv;
    
    
    x.join();
    y.join();

    vector<int> array;
    
    for (int i=0; i<10; i++)
        array.push_back(i);

    for (auto &a : array) {
        a = 1;
    }

    for (auto a : array) {
        cout << a << " " << endl;
    }
    
}