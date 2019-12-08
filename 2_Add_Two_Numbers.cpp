

#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;

struct ListNode {
     int val;
      ListNode *next;
      ListNode(int x) : val(x), next(nullptr) {}
  };
  
class Solution {
public:
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {   
        //Time complexity:?
        //Space complexity:?
        //应采用进位的思维解题
        //应当考虑以一个或几个0开头，而后面的元素不为0的情况
        //e.g.[0,8,6,5,6,8,3,5,7] and [6,7,8,0,8,5,8,9,7]
        //其中input为nullptr时候
        //将其视作[0]
        ListNode* dummy = new ListNode(0);
        ListNode* p = l1, *q = l2, *curr = dummy;//注意指针型变量的多重声明格式
        int carry = 0;//进位标记位
        while (p != nullptr || q != nullptr) 
        {
             int x = (p!=nullptr)?p->val:0;
             int y = (q!=nullptr)?q->val:0;
             int sum=carry+x+y;
            //不应该只考虑sum是否大于等于10
            //因为每个位不一定全是one digit
            //e.g. [11,11,11]+[9,9,9]
            carry=sum/10;
            //前插法or后插法?
            //还得思考下！
            curr->next = new ListNode(sum % 10);//取位
            curr = curr->next;
            if (p != nullptr) p = p->next;
            if (q != nullptr) q = q->next;
        }
        //If carry still left
        //append to tail
        //最终的进位，应体现在整数的最高位，即链表的tail
        if (carry > 0) 
            curr->next = new ListNode(carry);
        
        return dummy->next;
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

ListNode* stringToListNode(string input) {
    // Generate list from the input
    vector<int> list = stringToIntegerVector(input);

    // Now convert that list into linked list
    ListNode* dummyRoot = new ListNode(0);
    ListNode* ptr = dummyRoot;
    for(int item : list) {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

string listNodeToString(ListNode* node) {
    if (node == nullptr) {
        return "[]";
    }

    string result;
    while (node) {
        result += to_string(node->val) + ", ";
        node = node->next;
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        ListNode* l1 = stringToListNode(line);
        getline(cin, line);
        ListNode* l2 = stringToListNode(line);
        
        ListNode* ret = Solution().addTwoNumbers(l1, l2);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}