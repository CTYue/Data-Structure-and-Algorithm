//  main.cpp
//  Total_Hamming_Distance
//  Created by Zidong Yu on 6/6/18.
//  Copyright © 2018 Zidong Yu. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

vector<int> hammingCode = {4,14,2,7};
int high = hammingCode[hammingCode.size() - 1];
int low = hammingCode[0];

int partition(vector<int> &hammingCode,int low,int high)
{
    return 0;
}

void quickSort(vector<int> &hammingCode,int low,int high)
{
    int pi = 0;
    if(low < high)
    {
        pi = partition(hammingCode,low,high);
        
        quickSort(hammingCode, low, pi - 1);
        quickSort(hammingCode, pi + 1, high);
    }
}

int main(int argc, const char * argv[])
{
    int count = 0;

//    //Complexity analysis
//    //O(n^2)
//    for(int i = 0; i < hammingCode.size(); i++)
//    {
//        int result = 0;
//
//        for(int j = i+1; j < hammingCode.size(); j++)
//        {
//            std::cout << "hammingCode[" << i << "]: " << hammingCode[i] << std::endl;
//            std::cout << "hammingCode[" << j << "]: " << hammingCode[j] << std::endl;
//            result += (hammingCode[i] ^ hammingCode[j]);//异或
//            std::cout << "The result for this loop is: " << result << std::endl;
//            while (result != 0)
//            {
//                if((result & 1) == 1)
//                {
//                    count++;
//                }
//                result >>= 1;
//            }
//        }
//    }
    

    //  O(nlog(n)) implementation
//    int result = 0;
//    
//    int size = hammingCode.size();
//    if(size < 2) return 0;
//    int ans = 0;
//    int *zeroOne = new int[2];
//    while(true)
//    {
//        int zeroCount = 0;
//        zeroOne[0] = 0;
//        zeroOne[1] = 0;
//        for(int i = 0; i < hammingCode.size(); i++)
//        {
//            if(hammingCode[i] == 0) zeroCount++;
//            zeroOne[hammingCode[i] % 2]++;
//            hammingCode[i] = hammingCode[i] >> 1;
//        }
//        ans += zeroOne[0] * zeroOne[1];
//        if(zeroCount == hammingCode.size()) return ans;
//    }
//}
    
    
    
    
    std::cout << "count: "<< count << std::endl;
    return 0;
}

