/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-09-03 00:08:36
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-09-03 18:07:06
 * @Description: To be added.
 * @AC: Yes
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>

using namespace std;

//Time Complexity: ???
//Space Complexity: ???
class ValidWordAbbr {
public:
    ValidWordAbbr(vector<string> &dictionary) {
        for (string word : dictionary) {
            string key = word.front() + to_string(word.length() - 2) + word.back();
            hash[key].insert(word);//注意：hash[k].insert不会产生out of bound error
        }
    }
    
    bool isUnique(string word) {
        string key = word.front() + to_string(word.length() - 2) + word.back();        
        return hash[key].count(word) == hash[key].size();
    }
    
private:
    unordered_map<string, unordered_set<string> > hash;
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr* obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj->isUnique(word);
 */