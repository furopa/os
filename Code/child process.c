#include<stdio.h>
#include<sys/types.h>
void ChildProcess();
void ParentProcess();
int fork();
int getpid();
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
	pid_t pid1;
	pid1=getpid();
	printf(" \n I am child process \n");
	printf("\n %d",pid1);
}
void ParentProcess()
{
	pid_t pid1;
	pid1=getpid();
	printf(" I am parent process \n");
	printf("\n %d",pid1);
}
