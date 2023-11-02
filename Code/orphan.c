#include<stdio.h>
#include<stdlib.h>
void ChildProcess();
void ParentProcess();

int my_pid,my_ppid;

int main()
{
   pid_t pid;
   pid=fork();
   if(pid==0)
   ChildProcess();
   else
   ParentProcess();
   return 0;
}
void ChildProcess()
{
   printf("\nI am Child Process...");
   my_pid=getpid();
   printf("\nMy PID=%d",my_pid);
   my_ppid=getppid();
   printf("\nParent ID=%d",my_ppid);
   sleep(5);
   my_pid=getpid();
   printf("\nMy PID=%d",my_pid);
   my_ppid=getppid();
   printf("\nParent ID=%d",my_ppid);
}
void ParentProcess()
{
   printf("\nI am Parent Process...");
   my_pid=getpid();
   printf("\nMY PID=%d",my_pid);
   my_ppid=getppid();
   printf("\nParent I=%d\n",my_ppid);
}