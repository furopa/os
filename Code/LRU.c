#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int frame[20],page[20],stack[10];
int i,j,k,x,np,pf,nf,newpos,top=-1;
void accept();
void display();
int search(int);
int getLRU(int);
int push(int page);
int pop();
int main()
{
	accept();
	for(i=0;i<np;i++)
	{
		x=search(page[i]);
		if(x==-1)
		{
			pf++;
			newpos=getLRU(i);
			frame[newpos]=page[i];
		}
		display();
	}
	printf("No of page fault occured are:%d\n",pf);
}
void accept()
{
	printf("Enter no of frames:");
	scanf("%d",&nf);
	printf("Enter no of pages:");
	scanf("%d",&np);
	for(i=0;i<np;i++)
	{
		printf("Enter %d page:",i+1);
		scanf("%d",&page[i]);
	}
	for(i=0;i<nf;i++)
	{
		frame[i]=-1;
	}
}
void display()
{
	int i;
	for(i=0;i<nf;i++)
	{
		printf("-----\n");
		printf("|%d|\n",frame[i]);
		if(i==nf-1)
			printf("---------");
	}
	printf("\n\n");
}
int getLRU(int pos)
{
	int j,k,l,m,v=0;
	int pagefound=0,flag=0;
	top=-1;
	for(j=0;j<nf;j++)
		stack[j]=-1;
	for(j=0;j<nf;j++)
	{
		if(frame[j]==-1)
			return j;
	}
	for(j=pos-1;j>=0;j--)
	{
		flag=0;
		if(v!=nf)
		{
			for(l=0;l<nf;l++)
			{
				if(page[j]==stack[l])
				{
					flag=1;
					break;
				}
				if(flag==0)
				{
					push(page[j]);
					v++;
				}
 			}
		}
		else
			break;
	}
	pagefound=pop();
	for(m=0;m<nf;m++)
	{
		if(pagefound==frame[m])
			return m;
	}
}
int push(int p)
{
	top=top+1;
	stack[top]=p;
}
int pop()
{
	return stack[top];
}
int search(int no)
{
	for(j=0;j<nf;j++)
	{
		if(frame[j]==no)
			return j;
	}
	return -1;
}

