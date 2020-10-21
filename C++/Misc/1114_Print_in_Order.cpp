/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2020-03-14 23:27:59
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2020-03-14 23:30:36
 * @Description: To be added.
 */
#include <thread>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Foo {
protected:
    std::mutex mtx;
    std::condition_variable cv;
    int global_count=0;
public:
    Foo() 
    {
        global_count=1;
    }

    void first(function<void()> printFirst) {
        std::unique_lock<mutex> lck(mtx);
        printFirst();
        global_count=2;
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        std::unique_lock<mutex> lck(mtx);
        while(global_count!=2) 
            cv.wait(lck);//???
        printSecond();
        global_count=3;
        cv.notify_all();
    }

    void third(function<void()> printThird) {
        std::unique_lock<mutex> lck(mtx);
        while(global_count!=3) cv.wait(lck);
        printThird();
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int main() {
    //TODO
    // string line;
    // while (getline(cin, line)) {
    //     vector<int> nums = stringToIntegerVector(line);
        
    //     // int ret = Solution().foobar(nums);

    //     string out = to_string(ret);
    //     cout << out << endl;
    // }
    return 0;
}