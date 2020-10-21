/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2020-03-13 23:38:35
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2020-03-14 00:45:07
 * @Description: To be added.
 */

#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;
typedef map<string,int>::iterator map_it;

int main()
{

    //Demo linear map
    // map<string, int> map;
    // map.insert(make_pair("CTY",99));
    // map.insert(pair<string, int>("Yunhao", 59));
    // map.insert(pair<string, int>("Yunhao", 70));

    // //注意，map的iterator只重载了++ and --，不能使用+1访问下一个元素, 尽管map是所谓linear container
    // cout<<map.begin()->first<<": "<<map.begin()->second<<endl;
    
        
    // for(auto it=map.begin();it!=map.end();++it)
    //     cout<<it->first<<": "<<it->second<<endl;
    
    // if(map.count("CTY")!=0)
    //     cout<<"CTY has a record with us."<<endl;

    // //Erase CTY's record
    // map.erase("CTY");
    // if(map.count("CTY")!=0) cout<<"CTY has a record with us."<<endl;
    // else cout<<"No, we don't have CTY's record on file."<<endl;

    //Demo hashmap
    unordered_map<string, int> hashmap;
    hashmap.insert({"Alice", 90});
    hashmap.insert(make_pair("Bob",60));
    hashmap.insert(pair<string, int>("Cris",80));
    hashmap.insert({"Dong", 95});
    
    // cout<<hashmap.begin()->first<<": "<<hashmap.begin()->second<<endl;
    // auto it=++hashmap.begin();
    // // cout<<*(hashmap.begin()+1)->first<<": "<<*(hashmap.begin()+1)->second<<endl;//Doesn't work in this way.
    // cout<<it->first<<": "<<it->second<<endl;
    // it++;
    // cout<<it->first<<": "<<it->second<<endl;
    // it++;
    // cout<<it->first<<": "<<it->second<<endl;
    
    hashmap.erase("Dong");
    for(auto it=hashmap.begin();it!=hashmap.end();++it)
        cout<<it->first<<": "<<it->second<<endl;

    
    
    return 1;
}