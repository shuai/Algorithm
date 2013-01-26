////
////  multithreading.cpp
////  Algorithm
////
////  Created by Shuai on 9/22/12.
////
////
//
//#include "pthread.h"
//#include "semaphore.h"
//#include <list>
//#include <iostream>
//using namespace std;
//
//#define MAX_BUFFER_SIZE 10
//
//list<unsigned> buffer;
//
//static unsigned data = 0;
//pthread_mutex_t mutex;
//pthread_cond_t full, empty;
//
//void* produce(void*)
//{
//
//    while (true) {
//        pthread_mutex_lock(&mutex);
//                
//        if (buffer.size() == MAX_BUFFER_SIZE) {
//            pthread_cond_wait(&empty, &mutex);
//        }
//        
//        if (data == 101) {
//            pthread_mutex_unlock(&mutex);
//            return 0;
//        }
//        
//        buffer.push_back(data++);
//        cout << "producing " << buffer.back() << endl;
//        
//        if (buffer.size() == 1) {
//            pthread_cond_signal(&full);
//        }
//        
//        pthread_mutex_unlock(&mutex);
//    }
//    
//}
//
//void* consume(void*)
//{
//    while (true) {
//        pthread_mutex_lock(&mutex);
//        
//        if (buffer.empty()) {
//            pthread_cond_wait(&full, &mutex);
//        }
//        
//        cout << "consuming-------- " << buffer.front() << endl;
//        buffer.pop_front();
//        
//        if (buffer.empty()) {
//            pthread_cond_signal(&empty);
//        }
//        
//        pthread_mutex_unlock(&mutex);
//
//    }
//}
//
//sem_t semfull, semempty;
//
//// consumer-producer with semaphore
//// buggy
//void* consume2(void*)
//{
//    while (true) {
//        sem_wait(&semfull);
//        pthread_mutex_lock(&mutex);
//        
//        if (buffer.empty()) {
//            cout << "wtf??????????????????" << endl;
//        }
//        else
//        {
//        cout << "consuming------------ " << buffer.front() << endl;
//        buffer.pop_front();
//        }
//        
//        pthread_mutex_unlock(&mutex);
//        sem_post(&semempty);
//    }
//
//}
//
//void* produce2(void*)
//{
//    while (true) {
//        sem_wait(&semempty);
//        pthread_mutex_lock(&mutex);
//        
//        cout << "producing " << data << endl;
//        buffer.push_back(data++);
//        
//        pthread_mutex_unlock(&mutex);
//        sem_post(&semfull);
//    }
//}
//
//// reader writer
//
//
//
//void test_producer_consumer()
//{
//    pthread_mutex_init(&mutex, NULL);
//    pthread_cond_init(&full, NULL);
//    pthread_cond_init(&empty, NULL);
//    sem_init(&semfull, 0, 0);
//    sem_init(&semempty, 0, 1);
//
//    pthread_t t1,t2,t3,t4;
//    pthread_create(&t1, NULL, produce, NULL);
//    pthread_create(&t2, NULL, consume, NULL);
//    //pthread_create(&t3, NULL, consume, NULL);
//    
//    sleep(1);
//    pthread_cancel(t1);
//    pthread_cancel(t2);
//    //pthread_cancel(t3);
//    //pthread_cancel(t4);
//    
//    sem_destroy(&semfull);
//    sem_destroy(&semempty);
//    pthread_mutex_destroy(&mutex);
//    pthread_cond_destroy(&full);
//    pthread_cond_destroy(&empty);
//
//}
