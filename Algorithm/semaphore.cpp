//
//  semaphore.cpp
//  Algorithm
//
//  Created by Shuai on 1/26/13.
//
//

#include "include.h"
#include <mutex>
#include <condition_variable>
#include <thread>

class semaphore {
public:
    semaphore(int count)
    : count_(count) {
        
    }
    
    void wait() {
        unique_lock<mutex> lock(mutex_);
        
        while (count_ == 0) {
            condition_.wait(lock);
        }
        count_ --;
    }
    
    void notify() {
        lock_guard<mutex> guard(mutex_);
        count_++;
        condition_.notify_all();
    }
    
    int count() {
        return count_;
    }
private:
    mutex mutex_;
    condition_variable condition_;
    int count_;
};

static mutex m;
semaphore sem(0);
list<int> queue;
int last = 0;

void read() {
    while (true) {
        sem.wait();
        
        lock_guard<mutex> guard(m);
        int c = sem.count();
        int val = queue.front();
        assert(val == last+1);
        last = val;
        queue.pop_front();
        cout << val << endl;
    }
}

void write() {
    for (int i=1; i<1000000; i++) {
        lock_guard<mutex> guard(m);
        queue.push_back(i);
        sem.notify();
    }
}

void test_semaphore() {
    thread writer(write);
    vector<thread> reader;
    
    for (int i=0; i<100; i++) {
        reader.push_back(thread(read));
    }
    
    writer.join();
    for (auto &t : reader) {
        t.join();
    }
}
