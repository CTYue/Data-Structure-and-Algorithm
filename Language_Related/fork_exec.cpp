/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2020-03-13 22:53:12
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2020-03-13 23:03:39
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
      exit(EXIT_FAILURE); 
     } 
   //A child process is created successfully
   else if (pid == 0){ 

    //   printf("child process, pid = %u\n",getpid()); 
    //   char * argv_list[] = {"ls","-lart","/home",NULL}; 
    char** argv_list="-ali";
    
    execv("ls",argv_list); 
    exit(0); 
   } 
   else
   {
        printf("I am the parent process!\n");
        exit(0);   
   }
   return 0;
}