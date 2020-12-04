/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2020-02-17 20:42:46
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2020-02-19 20:41:37
 * @Description: To be added.
 */

#include <iostream>
#include <stack>

using namespace std;

//Implement all following methods in constant time.
class MinStack_Two_Stack {
private:
    stack<int> main_stack;
    stack<int> min_stack;
public:
    /** initialize your data structure here. */
    MinStack_Two_Stack() 
    {
        main_stack={};
        min_stack={};
    }
    
    void push(int x) 
    {
        main_stack.push(x);
        
        //min stack按大小顺序排序
        if(min_stack.empty() || x<=getMin()) min_stack.push(x);
    }
    
    void pop() 
    {
        if(min_stack.top()==main_stack.top())   min_stack.pop();
        main_stack.pop();
    }
    
    int top() 
    {
        return main_stack.top();   
    }
    
    int getMin() 
    {
        return min_stack.top();
    }
};

class MinStack_One_Stack {
private:
    int min=INT_MAX;
    stack<int> main_stack;
    //本题所需的stack仍然是正常的stack，但要求getMin方法能实时返回stack中最小的数
    //这里的min相当于一个指针，实时指向stack中的最小值
public:
    /** initialize your data structure here. */
    MinStack_One_Stack() 
    {
        main_stack={};   
    }
    
    void push(int x) 
    {
        if(x<=min)
        {
            //push上一次的值(min)
            main_stack.push(min);
            min=x;
        }
        
        //如果当前值比min大，则直接push入
        main_stack.push(x);
    }
    
    void pop() 
    {
        //如果当前栈顶的元素是min
        //那么pop两次，因为栈中实际上存了两次,min(上次的元素)和x(本次元素，如果小于min的话)
        if(main_stack.top()==min)
        {
            main_stack.pop();
            //Update min
            min=main_stack.top();
        }
        
        main_stack.pop();
    }
    
    int top() 
    {
        return main_stack.top();
    }
    
    int getMin() 
    {
        return min;   
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */


/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main(int argc, char** argv)
{
    //TODO
    
    return 1;
}