#include <iostream>
#include <string>
#include <functional>

using namespace std;

int main(int argc, char* argv[])
{
    std::hash<char> hash;
    std::hash<string> str_hash;
    char ch='a';
    //
    for(int i=0;i<25;i++)
    {
        std::cout << "hash(a): " << hash(ch+i) << std::endl;
    }

    std::cout << std::endl;
   
    std::cout << "str_hash(aaa) " << str_hash("aaa") << std::endl;
    std::cout << "str_hash(aab) " << str_hash("aab") << std::endl;
    std::cout << "str_hash(aab) " << str_hash("aac") << std::endl;

    return 0;
}