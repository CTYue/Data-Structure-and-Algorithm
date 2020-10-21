#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(int argc, char** argv)
{
  vector<int> test={0,1,2,3,4,5,6};
  std::sort(test.begin(), test.end());
  auto low=std::lower_bound(test.begin(), test.end(),3);
  auto up=std::upper_bound(test.begin(), test.end(),5);
  //for lower_bound, the iterator contain the position which 
  //has equal value
  //for upper_bound, it only returns which has greater value
  std::cout << "low pos =  " << low-test.begin()<<endl;
  std::cout << "up pos = " << up-test.begin()<<endl; 
}
