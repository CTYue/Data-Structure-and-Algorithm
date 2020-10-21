#include <iostream>
#include <vector>

using namespace std;

int main()
{
 vector<int> vec={1,2,3,4,5};
 for(auto item: vec) cout<<item<<" ";
cout<<endl;

vec.erase(vec.begin()+1,vec.begin()+3);
for(auto item: vec) cout<<item<<" ";
cout<<endl;

return 1;

}
