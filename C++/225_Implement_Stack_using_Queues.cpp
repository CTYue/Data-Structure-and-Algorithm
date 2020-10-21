/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-02-21 00:35:27
 * @LastEditors  : Zidong Yu
 * @LastEditTime : 2020-02-17 00:42:24
 * @Description: To be added.
 */

#include <iostream>
#include <queue>
using namespace std;

class MyStack_Two_Queues {
//Two Queues
//pop():  O(n)
//top():  O(1)
//push(): O(1)
private: queue<int> main_queue;
         queue<int> temp_queue;
         int top_val;
public:
    //Using two queues to implement
    /** Initialize your data structure here. */
    MyStack_Two_Queues() 
    {
        ;
    }
    
    /** Push element x onto stack. */
    void push(int x) 
    {
        main_queue.push(x);
        top_val=x;//Update top value
    }
    
    /** Removes the element on top of the stack and returns that element. */
    //O(n)
    int pop() 
    {
        while(main_queue.size()>1)
        {
            int temp=main_queue.front();
            temp_queue.push(temp);
            main_queue.pop();
        }
        
        int main_front=main_queue.front();
        main_queue.pop();
        
        cout<<"POP: size of main_queue: "<<main_queue.size()<<endl;
        
        while(!temp_queue.empty())
        {
            int temp=temp_queue.front();
            main_queue.push(temp);
            temp_queue.pop();
            //Update top value
            top_val=temp;
        }
        
        return main_front;
    }
    
    /** Get the top element. */
    //O(1)
    int top() 
    {
       return top_val;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() 
    {
        return main_queue.empty();
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

class MyStack_One_Queue {
private:
    std::queue<int> queue;
public:
    /** Initialize your data structure here. */
    MyStack_One_Queue() 
    {
        queue={};
    }
    
    /** Push element x onto stack. */
    //O(n)
    void push(int x) 
    {
        queue.push(x);
        int size=queue.size();
        
        while(size>1)
        {
            queue.push(queue.front());
            queue.pop();
            size--;
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    //O(1)
    int pop() 
    {
        int top=queue.front();
        queue.pop();
        
        return top;
    }
    
    /** Get the top element. */
    //O(1)
    int top() 
    {
        return queue.front();   
    }
    
    /** Returns whether the stack is empty. */
    //O(1)
    bool empty() {
        return queue.empty();
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




//Test Stub
int main()
{
    //TODO

    return 0;
}