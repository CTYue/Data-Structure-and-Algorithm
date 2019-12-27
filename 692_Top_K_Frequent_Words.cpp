/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-12-06 15:27:35
 * @LastEditors  : Zidong Yu
 * @LastEditTime : 2019-12-19 23:16:22
 * @Description: To be added.
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue> //注意，priority_queque没有单独的header，而是包括在queue header中

using namespace std;

//cmp函数要求： bool cmp(const Type1 &a, const Type2 &b);
//如果返回a<b, 那么按升序排列
//如果返回a>b, 则按降序排列
// bool comp(const unordered_map<string, int>::iterator a, const unordered_map<string, int>::iterator b)
// {
//     if((*a).second>(*b).second) return true;

//     else if((*a).second==(*b).second)
//     {
//         //return value of str.compare()
//         //0 strings are equal
//         //<0 前str的第一个不匹配的char小于后者，或者后者的字符与前者完全匹配，但前者更短
//         //>0 前str的第一个不匹配char大于后者，或者后者的字符与前者匹配，但前者更长
//         //此处，如果前string小于后string，则返回true，反之，返回false
//         return (*a).first.compare((*b).first) < 0; //按从短到长排列
//     }
    
//     //如果前者出现的次数小于后者出现的次数，则直接返回false
//     else
//         return false;
// }

typedef unordered_map<string, int>::iterator umap_it;

bool comp(const umap_it a, const umap_it b)
{
    //Desending order by frequency
    if (a->second > b->second) return true;
    
    //在frequency一致的情况下，按从短到长排序。
    else if (a->second == b->second) return a->first.compare(b->first) < 0;
    
    //若前者的frequency小于后者，则返回false
    else return false;
}

//Time Complexity: O(N)(dictionary traversal)+2*O(N)(Map traversal+forming res)+O(N*logN)(Sorting)
//so the average time complexity would be O(N*logN)
//Space Complexity: O(N)(size of map, worst case)+2*O(N)(size of v and res, worst case), so the average 
//space complexity would be O(N)
//STL Sorting Solution
class Solution_Sorting {
public:    
    vector<string> topKFrequent(vector<string>& words, int k) 
    {
       unordered_map<string, int> map;
       
       for(int i=0;i<words.size();i++)
       {
          //
          if(map.find(words[i])==map.end()) map.insert(pair<string, int>(words[i],1));
          else
              map[words[i]]++;
       }
      vector<string> res;
      vector<umap_it> v;
      for(auto it=map.begin();it!=map.end();it++)   v.push_back(it);
    
      //comp函数不能放在class里面，为什么？
      //less和greater是如何实现的？
      //less(升序)function templated:
      //template <class T> struct less {
      //bool operator() (const T& x, const T& y) const {return x<y;}
      //typedef T first_argument_type;
      //typedef T second_argument_type;
      //typedef bool result_type;
      //};
      //greater(降序) function templated:
      //template <class T> struct greater {
      //bool operator() (const T& x, const T& y) const {return x>y;}
      //typedef T first_argument_type;
      //typedef T second_argument_type;
      //typedef bool result_type;
      //};
      std::sort(v.begin(),v.end(), comp);
        
      for(int i=0;i<k;i++)  res.push_back((*v[i]).first);

      for(auto str: res)    cout<<str<<" ";
      cout<<endl;
        
      return res;
    }
};


typedef map<string, int>::iterator map_it;
class Solution_heap_1 {
private:
    struct comp
    {
        comp()=default;
        ~comp()=default;
        bool operator()(const map_it a, const map_it b)
        {
            //Form a max heap by using following code
            if(a->second < b->second) return true;
            else if(a->second == b->second)
            {
                //Shorter string comes first
                return a->first.compare(b->first)>0;
            }
            
            else return false;
        }
    };

public:
    //PriorityQueue
    //Time Complexity: O(n)+O(m)+O(k*logk)=O(n*logn)
    //Space Complexity: O(m)+O(m)+O(k)
    vector<string> topKFrequent(vector<string>& words, int k) 
    {
        map<string, int> map;
        //O(n) n是words的长度
        for(auto d: words)
        {
            if(map.find(d)==map.end())  map.insert(pair<string, int>(d,1));
            else    map[d]++;
        }
        
        priority_queue<map_it, vector<map_it>, comp> p_queue;
        //O(m) m是单词的个数
        for(map_it it=map.begin();it!=map.end();it++) p_queue.push(it);
        
        vector<string> res;
        //O(k*logk)
        for(int i=0;i<k;i++)
        {
            res.push_back(p_queue.top()->first);
            p_queue.pop();
        }

        return res;
    }
};


//Another heap
//Time Complexity: O(klogk)+O(m)+O(n): m:单词的个数， n:words的长度
//Space Complexity: 2*O(m)+O(k)
class Solution_heap_2 {
private:
struct comp
{
bool operator()(const pair<int, string> a, const pair<int, string> b)
{
    //less: max_heap
    if(a.first<b.first) return true;

    else if(a.first==b.first)
    {
        return a.second.compare(b.second)>0;
    }
    else 
        return false;
}

};
public:
    vector<string> topKFrequent(vector<string>& words, int k) 
    {
        unordered_map<string, int> count;
        //O(n)
        for(auto d: words)
        {
            count[d]++;//hashmap在[index]不存在的时候，依然可以访问
        }
        
        // for(auto p:count)
        // {
            // cout<<p.first<<": "<<p.second<<endl;
        // }
        
        //pair<int, string>的排序有问题, string被按照从长到短的顺序排列，
        //然而要求是string从短到长排列.所以要重写comp函数
        priority_queue<pair<int, string>, vector<pair<int, string> >, comp> max_heap;
        
        //Max heap
        //O(m) m是单词的个数
        for(auto p: count)
        {
            //make_pair 
            int freq=p.second;
            string word=p.first;
            auto new_pair=std::make_pair(freq, word);
            max_heap.push(new_pair);
        }
        
        vector<string> res;
        //Extract的时间复杂度是O(klogk), 原因是因为需要maintaining the heap
        //仅仅在删除的时候才重建heap，所以这里的复杂度是O(klogk)
        while(!max_heap.empty() && k!=0)
        {
            res.push_back(max_heap.top().second);
            max_heap.pop();
            k--;
        }
    
        return res;
    }
};




int main(int argc, char** argv)
{
    //TODO

    return 1;
}