/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2020-03-13 22:53:12
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2020-03-13 23:22:16
 * @Description: To be added.
 */
#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h>  
#include <stdlib.h> 
#include <errno.h>   
#include <sys/wait.h> 

int main(){ 
   pid_t  pid; 
   int ret = 1; 
   int status; 
   pid = fork();
   //Failed to create a child process 
   if (pid < 0){ 
      printf("can't fork, error occured\n"); 
      exit(0);
     } 
   //A child process is created successfully
   else if (pid == 0){ 

    char *argv[]={"echo", "车胖子，少吃点。", NULL};

    char *envp[]={0,NULL}; 

    execve("/bin/echo",argv,envp);//注意execve的参数！

    exit(0); 
   } 
   else
   {
        printf("I am the parent process!\n");
        exit(0); 
   }
   return 0;
}