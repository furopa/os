#include<stdio.h>
int frame[20];
int page[20];
int i,j,np,nf,x,frametravel=0,pf=0;

void accept();
int search(int);
void display();

int main()
{
	accept();

	for(i=0;i<np;i++)
	{
		x=search(page[i]);
		if(x==-1)
		{
			pf++;
			frame[(frametravel%nf)]=page[i];
			frametravel++;
		}
		else
		{
			frametravel++;
		}
		display();
	}
 printf("No of page fault occured are :%d\n",pf);
}
void display()
{
	int i;
 for(i=0;i<nf;i++)
 {
	 printf("-------\n");
	 printf("|%d|\n",frame[i]);
	 if(i==nf-1)
	 printf	("-----");
 }
 printf("\n\n");
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
void accept()
{
	printf("Enter no of frames:");
	scanf("%d",&nf);
	printf("Enter no fo pages:");
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




				
