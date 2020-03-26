/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2020-02-23 00:25:07
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2020-02-23 23:49:07
 * @Description: To be added.
 */
#include<iostream>
#include<string>

using namespace std;
//Practice C++ String
class insert_string
{
public:
    insert_string(string& A, string& B, int x)
    {
        A.insert(x,B);
        cout<<A<<endl;
    }

};

class find_index
{
private:
    string A="";
    string pattern="";
public:
    find_index(const string A, const string pattern)
    {
        this->A=A;
        this->pattern=pattern;

        find_last_index(A, pattern);
        find_first_index(A, pattern);
        find_first_not_index(A, pattern);
        find_last_not_of_index(A, pattern);
        find_last_of_index(A, pattern);
    }

    int find_last_index(const string A, const string pattern)
    {
        //Find last of
        int pos=A.find_last_of(pattern);
        cout<<"Last index of "<<pattern<<" is "<<pos<<endl;
        return pos;
    }

    int find_first_index(const string A, const string pattern)
    {
        int pos=A.find_first_of(pattern);
        cout<<"First index of "<<pattern<<" is "<<pos<<endl;
        return pos;
    }

    int find_first_not_index(const string A, const string pattern)
    {
        int pos=A.find_first_not_of(pattern);
        cout<<"First index not of "<<pattern<<" is "<<pos<<endl;
        return pos;
    }

    int find_last_not_of_index(const string A, const string pattern)
    {
        int pos=A.find_last_not_of(pattern);
        cout<<"Last index not of "<<pattern<<" is "<<endl;
        return pos;
    }

    int find_last_of_index(const string A, const string pattern)
    {
        int pos=A.find_last_of(pattern);
        cout<<"Last index of "<<pattern<<" is "<<endl;
        return pos;
    }

};

int main()
{
  string A("Hllo"), B("e");
  insert_string s(A,B,1);
  cout<<"A = "<<A<<endl;
  string pattern="l";

  //Demo find index of a given pattern in a string
  find_index findIndex(A, pattern);

  return 1;
}
