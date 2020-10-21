/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2020-03-06 14:30:45
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2020-03-14 23:06:28
 * @Description: To be added.
 */

#include <iostream>
#include <thread>
#include <pthread.h>
#include <time.h>
#include <unistd.h>

using namespace std;

#ifndef NUM_THREADS
#define NUM_THREADS 5

//std::thread支持的callable有
//A function pointer
//A function object
//A lambda expression

// void* say_hello(void* args)
// {
//     //之所以出现乱序的结果，是因为cout不是线程安全的！
//     cout<<"I am thread(with para) #"<<args<<"."<<endl;
//     return 0;
// }

//Simple functions
void say_hello()
{
    cout<<"hello"<<endl;
    return;
}

void say_hi()
{
    cout<<"hi"<<endl;
    return;
}


//More complex functions
int global_counter = 0;
std::mutex counter_mutex;//mutex需要手动指定锁定区域，lock和unlock需要成对使用

void five_thread_fn(){
    for(int i = 0; i<5; i++){
        counter_mutex.lock();
        // std::lock_guard<std::mutex> locker(counter_mutex);
        global_counter++;
        // counter_mutex.unlock();
        std::cout << "Updated from five_thread"  << endl;
        // counter_mutex.unlock();
        // std::this_thread::sleep_for(std::chrono::seconds(1));
        sleep(1);
        counter_mutex.unlock();
    }
    //When this thread finishes we wait for it to join
}

void ten_thread_fn(){
    for(int i = 0; i<10; i++){
        counter_mutex.lock();
        // std::lock_guard<std::mutex> locker(counter_mutex);
        global_counter++;
        // counter_mutex.unlock();
        std::cout << "Updated from ten_thread"  << endl;
        // counter_mutex.unlock();
        // std::this_thread::sleep_for(std::chrono::seconds(1));
        sleep(1);
        counter_mutex.unlock();
    }
    //When this thread finishes we wait for it to join
}


int main()
{
    //Demo pthread 
    // int indexs[NUM_THREADS];
    // pthread_t tids[NUM_THREADS];
    // //什么是线程池？为什么要使用线程池？
    
    // for(int i=0;i<NUM_THREADS;++i)
    // {
    //     //参数：要创建的线程的ID，线程参数，调用的函数，传入的参数
    //     // usleep(100);
    //     indexs[i]=i;
    //     //pthread_create的最后一个参数怎么搞？为什么要强制转换成void*
    //     int ret=pthread_create(&tids[i], NULL, say_hello, (void*)(indexs[i]));
        
    //     if(ret!=0)
    //     {
    //        cout << "pthread_create error: error_code=" << ret << endl;
    //     }
    // }
    
    // pthread_exit(NULL);
    //End Demo pthread

    // //Demo stl thread
    // string hello="Hello there!";
    // void* ptr=&hello;
    // // std::thread t(say_hello, (void*)ptr);//第二个参数写什么？
    // std::thread t1(say_hello);


    // // std::cout << t1.hardware_concurrency() << std::endl;//可以并发执行多少个(不准确)
    // // std::cout << "native_handle " << t1.native_handle() << std::endl;//可以并发执行多少个(不准确)
    
    // //To wait for t to finish
    // t1.join();//不用join会出现什么？
    // //这里如果不join thread的话，main函数可能会在thread执行完成之前结束.
    // //会出现terminating: abort错误.

    // std::thread t2(say_hi);
    // t2.join();
    // detach 是什么意思？

    // cout<<"This is main function."<<endl;

    // return 1;


    //Demo threads with locks
    std::thread ten_thread(ten_thread_fn);
    // std::cout << "Running ten threads" << endl;

    std::thread five_thread(five_thread_fn);
    // std::cout << "Running five threads" << endl;

    ten_thread.join();
    // ten_thread.detach();//主调线程不用等待被调线程执行完成即可结束
    //如果join和detach同时执行，会怎样?
    std::cout << "Ten Thread is done." << std::endl;
    five_thread.join();
    // five_thread.detach();
    std::cout << "Five Thread is done." << std::endl;

    //
    cout<<"global_counter = "<<global_counter<<endl;

    //那么问题来了，什么是线程安全？
    //Thread safety indicates multiple threads handles shared resources properly.
    
    //C++的string是线程安全的吗？
    //不是，原因是。。。


    //Synchronization of process(thread)
    //Multiple concurrent processes (threads) access shared resources(critical resources) 
    //in a sequance.
    //to make sure there's conflict.


}
#endif