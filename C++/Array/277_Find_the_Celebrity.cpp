/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-08-13 22:00:00
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-08-15 23:08:03
 * @Description: No playground code provided.
 */

// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n)
    {
        int celeb=0;
        for(int i=0;i<n;i++)
        {
            if(knows(celeb,i))  celeb=i;
        }
        
        for(int i=0;i<n;i++)
        {
            //celeb认识i或者i不认识celeb
            if(i!=celeb && (knows(celeb,i) || !knows(i,celeb)))   return -1;
        }
        
        return celeb;
    }
};

int main(int argc, char* argv[])
{

    return 1;
}