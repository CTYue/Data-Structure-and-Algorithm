/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2020-03-12 22:16:43
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2020-03-13 23:46:36
 * @Description: To be added.
 */
#include<iostream>
#include<vector>

using namespace std;
typedef vector<string>::const_iterator const_it;
int main(int argc, char** argv)
{

    // vector<string> v1(99,"SU");
    // cout<<"v1.size() == "<<v1.size()<<endl;
    // vector<string> v2=v1;
    // int a=666;int count=0;
    // // v1.assign(v2.begin(), v2.begin()+11);
    // // v1.push_back(v2.begin(), v2.begin()+11);
    // v1.assign(10, "CTY");
    // v1.erase(v1.begin(),v1.begin()+2);

    // //Capacity: the most number of elements the current vector can hold
    // //without allocating extra memory
    // cout<<"v1.capacity() == "<<v1.capacity()<<endl;
    // //Size: current number of elements inside the container 
    // cout<<"v1.size() == "<<v1.size()<<endl;
    

    // for(const_it it=v1.begin();it!=v1.end();++it)
    // for(auto it=v1.begin();it!=v1.end();++it)
    // {
    //     cout<<++count<<endl;
    //     *it="CA";
    //     cout<<*it<<" ";
    //     it->pop_back();
    // }
    // cout<<endl;


    // void* ptr=&a;
    // int* p2=(int*)ptr;
    
    // cout<<*ptr<<endl;//不能直接访问void*
    // cout<<*p2<<endl;

    vector<int> v1={1,2,3,4,5};
    cout<<*v1.begin()<<" "<<*(v1.begin()+1)<<" "<<*(v1.begin()+2)<<endl;
    
    return 1;
}