#include<iostream>
#include<string>
#include <algorithm>

using namespace std;
//Remove heading and ending spaces
//Spaces inside the string will NOT be removed
// string trim(std::string& str, char pattern)
// {
//     size_t first = str.find_first_not_of(' ');
//     if (first == std::string::npos)
//         return "";
//     std::cout << "first = " << first << std::endl;
//     string r_str=str;
//     reverse(r_str.begin(), r_str.end());
//     std::cout << "str = " << str << std::endl;
//     std::cout << "r_str = " << r_str << std::endl;

//     size_t last = r_str.find_first_not_of(' ');
//     std::cout << "r_str.first_not_of = " << last << std::endl;

//     last=str.length()-(last+1);
//     std::cout << "last = " << last << std::endl;

//     return str.substr(first, last - first + 1);
// }

//Remove heading and ending spaces
//Spaces inside the string will NOT be removed
string trim(string str)
{
    size_t first=str.find_first_not_of(' ');
    if(first==string::npos) return "";
    size_t last=str.find_last_not_of(' ');


    return str.substr(first, last-first+1);
}

int main(int argc, char* argv[])
{   
    string input=" h e ll o ";

    string res=trim(input);
    std::cout << input << std::endl;
   
    std::cout << res << std::endl;
    std::cout << "res.length() = " << res.length() << std::endl;

    return 1;
}