/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-02-21 00:35:27
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-02-21 23:06:30
 * @Description: To be added.
 */


#include <iostream>
#include <queue>

class MyStack {
private:
    std::queue<int> q_main;
    std::queue<int> q_top;

public:  
    /** Initialize your data structure here. */
    MyStack() 
    {
        ;
    }

    //Queue:
    /** Push element x onto stack. */
    void push(int x) 
    {
        q_main.push(x);
        if(!q_top.empty()) q_top.front()=x;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() 
    {
        int result=top();
        q_top.pop();
        return result;
    }
    
    /** Get the top element. */
    int top() 
    {
        if(!q_top.empty())
            return q_top.front();
        
        else if(!q_main.empty())
        {
            for(int i=0;i<q_main.size()-1;i++)
            {
                q_main.push(q_main.front());
                q_main.pop();
            }
            
            q_top.push(q_main.front());
            q_main.pop();
            
            return q_top.front();
        }
        
        return 404;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() 
    {
        return q_main.empty() && q_top.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */
//Test Stub
int main()
{
    //TODO

    return 0;
}