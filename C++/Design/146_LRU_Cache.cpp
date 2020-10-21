#include<iostream>
#include <unordered_map>

using namespace std;

//Time Complexity: O(1)
//Space Complexity: O(capacity)
class LRUCache {
//Head and tail do NOT contain any data
//这里为什么要用到双链表?
//这道题要从时间复杂度的角度入手分析
//考察点也在于时间复杂度
class DLinkedNode
{
public:
        int key;
        int value;
        DLinkedNode* prev;
        DLinkedNode* next;
        DLinkedNode()
        {
            key=0;value=0;prev=next=nullptr;
        }
        DLinkedNode(int key, int value)
        {
            this->key=key;
            this->value=value;
        }
        ~DLinkedNode()=delete;
};
    
private:
    //请复习hashmap，hashtable相关的知识。
    unordered_map<int, DLinkedNode*> cache;
    int size;
    int capacity;
    DLinkedNode* head=nullptr, *tail=nullptr;

    //将新node添加到头部
    void addNode(DLinkedNode* node)
    {
        node->prev=head;
        node->next=head->next;
        
        head->next->prev=node;
        head->next=node;
    }
    
    
    void removeNode(DLinkedNode* node)
    {
        DLinkedNode* prev=node->prev;
        DLinkedNode* next=node->next;
        
        prev->next=next;
        next->prev=prev;
    }
    
    //一旦有inquiry，则将被访问的key移动到头部
    void moveToHead(DLinkedNode* node)
    {
        removeNode(node);
        addNode(node);
    }
    
    //返回tail的前一个node，即least visited node
    DLinkedNode* popTail()
    {
        DLinkedNode* res=tail->prev;
        
        removeNode(res);
        return res;
    }
       
public:
    LRUCache(int capacity) 
    {
        this->size=0;
        this->capacity=capacity;
        
        head=new DLinkedNode();
        
        tail=new DLinkedNode();

        head->prev=nullptr;
        tail->next=nullptr;
        head->next=tail;
        tail->prev=head;
    }
    
    
    int get(int key) 
    {
        DLinkedNode* node=cache[key];
        if(node==nullptr) return -1;
        
        //move inquired node to head
        moveToHead(node);
        
        return node->value;
    }
    
    void put(int key, int value) 
    {
        DLinkedNode* node=cache[key];
        
        //如果现有的key没在cache中
        if(node==nullptr)
        {
            DLinkedNode* newNode=new DLinkedNode();
            newNode->key=key;
            newNode->value=value;
            
            cache[key]=newNode;
            addNode(newNode);
            
            size++;
            
            if(size>capacity)
            {
                //pop the tail
                //这里没看懂
                DLinkedNode* tail=popTail();
                
                cache.erase(tail->key);
                size--;
            }
        }
        else
        {
            //如果key已经存在于当前cache中，则更新其value
            node->value=value;//这里的node不应该是nullptr啊？
                
            moveToHead(node);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main(int argc, char** argv)
{
    //TODO
    return 1;
}