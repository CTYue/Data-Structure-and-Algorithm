/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-08-20 01:00:30
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-08-21 21:11:05
 * @Description: To be added.
 * @AC: Yes
 */
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <queue>

using namespace std;

//Explanation:
//   Consider a 1D overlap (Interval problem).
//      For an overlap to occur necessary condition is
     
//              x3,y2          x4,y2
//                |--------------|
//      |--------------|
//      x1,y1         x2,y1
              
//      x1 < x3 < x2  && x3 < x2 < x4 
     
//      Or simplified - x1 < x4 && x3 < x2
//      For 2D case use 1D conditions for both X and Y axes
     
//      Case-1: Rec2 intersects with Rec1 on top right corner

//                ____________________x4,y4
//               |                   |
//        _______|______x2,y2        |
//       |       |______|____________|
//       |      x3,y3   |
//       |______________|
//      x1,y1
              
//      Case-2: Rec2 intersects with Rec1 on top left corner
//        ___________________  x4,y4
//       |                   |
//       |            _______|____________x2,y2
//       |___________|_______|           |
//     x3,y3         |                   | 
//                   |___________________|
//                 x1,y1

//      Case-3: Rec2 intersects with Rec1 on bottom left corner
     
//                ____________________x2,y2
//               |                   |
//        _______|______x4,y4        |
//       |       |______|____________|
//       |      x1,y1   |
//       |______________|
//      x3,y3
              
//      Case-4: Rec2 intersects with Rec1 on bottom right corner
     
//        ___________________  x2,y2
//       |                   |
//       |            _______|____________x4,y4
//       |___________|_______|           |
//     x1,y1         |                   | 
//                   |___________________|
//                 x3,y3
    
//     bool case1 = (x1 < x4 && x3 < x2 && y1 < y4 && y3 < y2); //top right intersection
//     bool case2 = (x3 < x2 && x1 < x4 && y1 < y4 && y3 < y2); //top left intersection
//     bool case3 = (x3 < x2 && x1 < x4 && y3 < y2 && y4 < y1); //bottom left intersection
//     bool case4 = (x1 < x4 && x3 < x2 && y3 < y2 && y4 < y1); //bottom right intersection
    
//     if you look carefully in all cases we have same 4 comparisons

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) 
    {
        if(rec1.size()==0 || rec2.size()==0)    return false;
        
        return (rec1[0]<rec2[2] && rec2[0]<rec1[2] && rec2[1]<rec1[3] && rec1[1]<rec2[3]);
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

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> rec1 = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> rec2 = stringToIntegerVector(line);
        
        bool ret = Solution().isRectangleOverlap(rec1, rec2);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}