/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-09-19 08:28:13
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-09-19 22:18:01
 * @Description: To be added.
 */
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution_1 {
public:
    //Brute force Solution
    //Time Complexity: O((m+n)log(m+n))
    //Space Complexity: O(1)
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {   
        //std::copy(src_begin, src_end, dest_begin);
        std::copy(nums2.begin(), nums2.begin()+n, nums1.begin()+m);        
        for(auto item:nums1)
            std::cout<< item << " ";

        std::sort(nums1.begin(), nums1.end());
    }
};

class Solution_2 {
public:
    //Two pointers
    //Time Complexity: O(m+n)
    //Space Complexity: O(1)
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        int idx_1=m-1, idx_2=n-1;
        int len=m+n-1;
        while(idx_1>=0 && idx_2>=0)
        {
            if(nums1[idx_1]>=nums2[idx_2])  nums1[len--]=nums1[idx_1--];
            else nums1[len--]=nums2[idx_2--];            
        }
        std::cout << "idx_1 = " << idx_1 << std::endl;
        std::cout << "idx_2 = " << idx_2 << std::endl;
        
        while(idx_2>=0) 
        {
            nums1[len--]=nums2[idx_2--];
        }
        
        for(int n:nums1)    std::cout << n << " ";
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

int stringToInteger(string input) {
    return stoi(input);
}

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums1 = stringToIntegerVector(line);
        getline(cin, line);
        int m = stringToInteger(line);
        getline(cin, line);
        vector<int> nums2 = stringToIntegerVector(line);
        getline(cin, line);
        int n = stringToInteger(line);
        
        Solution_1().merge(nums1, m, nums2, n);

        string out = integerVectorToString(nums1);
        cout << out << endl;
    }
    return 0;
}