/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2020-02-17 17:35:58
 * @LastEditors  : Zidong Yu
 * @LastEditTime : 2020-02-17 17:36:53
 * @Description: To be added.
 */

#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
private:
    stack<int> main;
    stack<int> temp;
public:
    /** Initialize your data structure here. */
    MyQueue() 
    {
        main={};
        temp={};
    }
    
    /** Push element x to the back of queue. */
    void push(int x) 
    {
        while(!main.empty())
        {
            temp.push(main.top());
            main.pop();
        }
        
        temp.push(x);
        
        while(!temp.empty())
        {
            main.push(temp.top());
            temp.pop();
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int top=main.top();
        main.pop();
        return top;
    }
    
    /** Get the front element. */
    int peek() {
        return main.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return main.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

int main(int argc, char** argv)
{
    //TODO

    return 1;
}