/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2020-02-23 00:25:07
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2020-03-14 12:33:51
 * @Description: To be added.
 */
#include<iostream>
#include<string>
#include <typeinfo>
#include <limits>
#include <float.h>

using namespace std;

int main()
{
<<<<<<< HEAD
public:
    insert_string(string& A, string& B, int x)
    {
        A.insert(x,B);
        cout<<A<<endl;
    }
=======
  //cctype functions
  //处理单个char
  // string A="HelloCTY0503\n";
  // string B=" ";
  // string C="ccc";
  // string D=",.;'/[]-0";
  // size_t A_len=A.length();
  
  // if(isalnum(A[0]))  cout<<"Yes, it's digit or alphabet"<<endl;//check if it's number or alphabet
  // if(isalpha(A[0]))  cout<<"Yes, it's alphabet"<<endl;//check if it's alphabet
  // if(iscntrl(A[A_len-1]))  cout<<"Yes, it's a control character"<<endl;//什么是控制字符？
  // if(isgraph(B[0])) cout<<"Yes, it's NOT a space."<<endl;
  // if(islower(C[0])) cout<<"Yes, it's lower alphabet"<<endl;
  // if(isprint(B[0])) cout<<"Yes, it's printable"<<endl;
  // if(ispunct(*(D.end()-2))) cout<<"Yes, it's puncture!"<<endl;
  // cout<<toupper(D[0])<<endl;
  
  // const char* ch=A.c_str();
  // // cout<<"ch = "<<ch<<endl;
  // cout<<"A.length() == "<<A.length()<<endl;
  // // A.replace(0, 2, "REPLACE");//
  // A.replace(A.begin(),A.begin()+13, "ABCDEFGHIJKLMNOPQRST");
>>>>>>> c121d290968b3fcdc369c194b76eefeaff22d954

  // cout<<A<<endl;
  // cout<<"New A.length() == "<<A.length()<<endl;
  
  // cout<<"A.find(\"Q\") == "<<A.find("Q")<<endl;
  // cout<<"A.find_first_of(\"C\") == "<<A.find_first_of(C)<<endl;
  // cout<<"A.find_last_of(\"Q\") == "<<A.find_last_of("Q")<<endl;
  // size_t res=A.find_first_of("A",1);//第二个参数指定了查找的起点
  // if(res!=string::npos) cout<<"A.find_first_of(\"A\") == "<<res<<endl;
  // else cout<<"Not Found!"<<endl;
  
  // string E="I am CTYCTY";
  // res=E.rfind("CTY");
  // if(res!=string::npos) cout<<"E.rfind(\"CTY\") == "<<res<<endl;//从右往左找，返回找到的第一个match pattern的pos
  // else cout<<"Not Found!"<<endl;
  // res=E.find("CTY");
  // if(res!=string::npos) cout<<"E.find(\"CTY\") == "<<res<<endl;//从左往右找，返回找到的第一个match pattern的pos
  // else cout<<"Not Found!"<<endl;
  
  //Demo string compare
  //str1.compare(s2): 
  //returns >0: 按照字典顺序返回结果(靠后的字母大于靠前的字母), 回忆下字典顺序...
  //returns =0: 两个字符串完全相同
  //returns <0: 反之
  // string str1="abCDc";
  // string str2="abCDe";
  // string str1="ca";
  // string str2="cb";
  // cout<<"str1.compare(str2) == "<<str1.compare(str2)<<endl;
  // cout<<"str1.compare(0, 2, str2, 2) == "<<str1.compare(0, 2, str2, 2)<<endl;

<<<<<<< HEAD
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
=======
  // string F=" Sound Hound";
  // cout<<"F before:"<<F<<endl;
  // if(F.find(" ")==string::npos) 
  // {
  //     cout<<"No place in the string!"<<endl;
  // }
  // else 
  // {
  // cout<<"Yes, there're spaces in the string"<<endl;
  // }
  
  // F.erase(F.begin());
  // F.erase(F.end()-1);//这里可以-1，map不能这样用!
  // F.erase(F.find_last_of(" "),1);//这里要注意, 如果不指定第二个参数，那么就删除从指定位置开始的所有char
  // F.erase(F.find_first_of(" "),1);
  // //写点验证？？？

  // cout<<"F after:"<<F<<endl;
  // if(F.find(" ")==string::npos) cout<<"No place in the string!"<<endl;

  // cout<<endl<<endl<<endl;
>>>>>>> c121d290968b3fcdc369c194b76eefeaff22d954

  // try
  // {
  //   // string float_str="3.1415926";
  //   string float_str="2.4791E2";
  //   auto res=std::stof(float_str);//如何设置精度？
    
  //   cout<<res<<endl;
  // }
  
  // //catch这里一定要传引用，否则不会显示错误详情.
  // catch(std::exception& e)
  // {
  //   cerr<<e.what()<<endl;
  // }
  
  //C++ doesn't have "finally" keyword, but anything we put behind the catch
  //block will be executed, this is like how finnaly works.
  // cout<<"Finally"<<endl;
  // cout<<endl;
}
