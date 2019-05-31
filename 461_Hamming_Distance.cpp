//  main.cpp
//  Hamming_Distance
//  Created by Zidong Yu on 5/30/18.
//  Copyright © 2018 Zidong Yu. All rights reserved.
//  Description: Hamming distance

#include <iostream>
#include <math.h>

int main(int argc, const char * argv[])
{
  int x = 93;
  int y = 73;
  int result = 0;
  int count = 0;

  result = (x ^ y);
  //count bit 1
  //  while(result != 0)
  //  {
  //    if((result & 1) == 1)
  //        count ++;
  //    result >>= 1;
  //  }
    
  //count bit 2
  //for(;result != 0;result >>= 1)
  //{
  //      count += (result & 1);
  //  }
    
  //count bit 3
  //  for(;result != 0;count++)
  //  {
  //      result &= (result - 1);//it works
  //  }

  //count bit 4
  //查表法
  unsigned char BitsTable256[256] = {0};

  for(int i = 0;i < 256; i++)
  {
      BitsTable256[i] = (i &1) + BitsTable256[i / 2];//why?
  }

  //unsigned int count = 0;
  //inquire table
  unsigned char *p = (unsigned char*) &result;
    
//  std::cout << "p is:" << *p << std::endl;//
    
  count = BitsTable256[p[0]] +
          BitsTable256[p[1]] +
          BitsTable256[p[2]] +
          BitsTable256[p[3]];
    
  //count bit 5
  
    
    std::cout << count  << std::endl;
    return 0;
}
