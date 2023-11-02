#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<string.h>
#include<unistd.h>
#include<dirent.h>
#include<fcntl.h>
void count(char c,char *fn)
{
	int lc=0,wc=0,cc=0,handle;
	char ch;
	if((handle=open(fn,O_RDONLY))==-1)
	{
		printf("%s file not found\n",fn);
		return;
	}
	while(read(handle,&ch,1)!=0)
	{
		if(ch==' ') 
		{
			wc++;
		}
		else if(ch=='\n')
		{
			lc++;
			wc++;
		}
		else
		{
			cc++;
		}
	}
	close(handle);
	switch(c)
	{
		case 'c':printf("total number of  characters=%d\n",cc);
			 break;
		case 'w':printf("total number of words=%d\n",wc);
			 break;
		case 'l':printf("total number of line=%d\n",lc);
			 break;
	}
}
int main()
{
	char  t1[20],t2[20],t3[20],t4[20],command[100];
	int n;
	while(1)
	{
		printf("\n $myshell");
		fflush (stdin);
		fgets(command,80,stdin);
		n=sscanf(command,"%s %s %s %s",t1,t2,t3,t4);
		switch(n)
		{
			case 1:if(fork()==0)
			       {
				       execlp(t1,t1,NULL);
				       perror(t1);
			               break;
			       }
			case 2:if(fork()==0)
			       {
				       execlp(t1,t1,t2,NULL);
				       perror(t1);
			       	       break;
			       }
			case 3:if(strcmp(t1,"count")==0)
			       {
				       count(t2[0],t3);
			       }
				       else
			       {
				       execlp(t1,t1,t2,t3,NULL);
				       perror(t1);
			       }
				       break;
			case 4:if(fork()==0)
			       {
				       execlp(t1,t1,t2,t3,t4,NULL);
				       perror(t1);
			       }
		}
	}
}


