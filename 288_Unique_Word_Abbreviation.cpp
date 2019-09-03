/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-09-03 00:08:36
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-09-03 00:08:45
 * @Description: To be added.
 * @AC: Yes
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;
class ValidWordAbbr {
public:
    ValidWordAbbr(vector<string> &dictionary) {
        for (auto a : dictionary) {
            string k = a[0] + to_string(a.size() - 2) + a.back();
            m[k].insert(a);
        }
    }
    
    bool isUnique(string word) {
        string k = word[0] + to_string(word.size() - 2) + word.back();
        return m[k].count(word) == m[k].size();
    }
    
private:
    unordered_map<string, set<string>> m;
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr* obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj->isUnique(word);
 */