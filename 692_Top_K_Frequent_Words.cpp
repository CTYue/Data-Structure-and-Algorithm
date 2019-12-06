/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-12-06 15:27:35
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-12-06 16:51:32
 * @Description: To be added.
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

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
class Solution {
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

int main(int argc, char** argv)
{
    //TODO

    return 1;
}