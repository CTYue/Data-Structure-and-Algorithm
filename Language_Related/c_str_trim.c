/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2020-03-16 11:08:54
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2020-03-16 12:39:38
 * @Description: To be added.
 */

#include <stdio.h>
#include <ctype.h>

char* str_trim(char* str)
{
    char* head, *tail;
    head=str;
    tail=head+strlen(str)-1;
    char* end=tail;

    while(head<=end && isspace(*head))
    {
        head++;
    }

    while(tail>=head && isspace(*tail))
    {
        tail--;
    }

    //Update len
    int len=0;
    if(head<tail)
    {
        len=(tail-head+1);
    }
    else
    {
        len=0;
    }
    head[len]='\0';

    return head;
}


int main()
{
    // char arr[]={" HelloWorld ", NULL};
    char arr[]={" HelloWorld "};
    // char arr[]=" HelloWorld ";
    char* str=arr;
    char* res=str_trim(str);

    printf("Input: (%s)\n", arr);
    printf("Output: (%s)\n", res);

    float x=11e1;

    printf("%f\n", x);

    return 1;
}