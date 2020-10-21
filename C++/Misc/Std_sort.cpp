


#include <iostream>
#include <algorithm>
#define ARR_LEN(array, len) {len=sizeof(array)/sizeof(array[0]);}
using namespace std;

int main(int argc, char* argv[])
{
    if(argc<1) return 1;

    int arr[]={1,5,4,3,6,7,8,5,23,5,11,0};
    int len;

    std::cout << "sizeof(array) = " << sizeof(arr) << std::endl;
    std::cout << "sizoeof(array[0]) = " << sizeof(arr[0]) << std::endl;
    // len=sizeof(arr)/sizeof(arr[0]);
    ARR_LEN(arr,len);

    std::cout << "len = " << len << std::endl;
    std::cout << "Before: " << std::endl; 
    for(int item: arr)
        std::cout << item << " ";
    std::cout << std::endl;

    std::cout << "After: " << std::endl;
    //By default, std::sort works in an ascending order.

    std::sort(arr,arr+len);
    for(int item: arr)
        std::cout << item << " ";
    std::cout << std::endl;


}