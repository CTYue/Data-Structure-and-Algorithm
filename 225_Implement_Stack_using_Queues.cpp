/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-02-21 00:35:27
 * @LastEditors  : Zidong Yu
 * @LastEditTime : 2019-12-18 23:48:57
 * @Description: To be added.
 */

#include <iostream>
#include <queue>

class MyStack {
private:
    //Complexity:
    //Push: O(1)
    //Pop: O(n)
    //需要考虑两个queue之间的更新问题
    std::queue<int> main_queue;
    std::queue<int> top_queue;
public:
    //用两个queue实现
    /** Initialize your data structure here. */
    MyStack() 
    {
        ;
    }
    
    /** Push element x onto stack. */
    void push(int x) 
    {
        //这里为什么
        main_queue.push(x);
        //将栈顶更新为x
        if(!top_queue.empty()) top_queue.front()=x;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() 
    {
        int res=top();
        top_queue.pop();
        
        return res;
    }
    
    /** Get the top element. */
    int top() 
    {
        //如果只用一个queue的话，这里就不方便处理了。
        //所以，在这里return top_queue的top
        if(!top_queue.empty())  return top_queue.front();
        
        else if(!main_queue.empty())
        {
            //Reverse the main queue
            //Transform it
            for(int i=0;i<main_queue.size()-1;i++)
            {
                main_queue.push(main_queue.front());
                main_queue.pop();
            }
            
            //将main_queue的front pop到top_queue当中
            top_queue.push(main_queue.front());
            main_queue.pop();//
            
            return top_queue.front();
        }
        
        return 404;    
    }
    
    /** Returns whether the stack is empty. */
    bool empty() 
    {
        return top_queue.empty() && main_queue.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

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