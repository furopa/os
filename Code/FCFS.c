#include<stdio.h>
#include<stdlib.h>

struct Process
{
	int f_bt,t_bt,n_bt,at,tat,wt,ft;
}p[100];

struct Schedule
{
	int pid,endtime;
}sch[100];
void accept();
void showGanttchart();
void showPT();
int getprocessbyfcfs();
int getprocessbyfcfs1();
int sch_cnt,ct,np,i;
void main()
{
	accept();
	while(1)
	{
		int x=getprocessbyfcfs();
		if(x==-1)
			break;
		sch[sch_cnt].pid=x;
		ct+=p[x].t_bt;
		p[x].t_bt=0;
		p[x].ft=ct;
		sch[sch_cnt].endtime=ct;
		sch_cnt++;
	}
	for(i=0;i<np;i++)
	{		
		p[i].t_bt=p[i].n_bt;
	}
	while(1)
        {
		int x=getprocessbyfcfs1();
		if(x==-1)
			break;
		sch[sch_cnt].pid=x;
		ct+=p[x].t_bt;
		p[x].t_bt=0;
		p[x].ft=ct;
		sch[sch_cnt].endtime=ct;
		sch_cnt++;
		p[x].tat=p[x].ft-p[x].at;
		p[x].wt=p[x].tat-p[x].f_bt-p[x].n_bt-2;
	}
	showGanttchart();
	showPT();
}
			
void accept()
{
	printf("Enter no. of processes");
	scanf("%d",&np);
	for(i=0;i<np;i++)
	{
		printf("Enter Arival Time");
		scanf("%d",&p[i].at);
		printf("Enter first burst time");
		scanf("%d",&p[i].f_bt);
		p[i].t_bt=p[i].f_bt;
		p[i].n_bt=rand()%5+1;
	}
}
int getprocessbyfcfs()
{
	int minp=-1;
	int minat=32767;
	for(i=0;i<np;i++)
	{
		if(p[i].at<=ct && p[i].t_bt>0 && p[i].at<minat)
		{
			minp=i;
			minat=p[i].at;
		}
	}
	return minp;
}
int getprocessbyfcfs1()
{
	int minp=-1;
	int minat=32767;
	for(i=0;i<np;i++)
	{
		if(p[i].at<=ct && p[i].t_bt>0 && p[i].at<minat && (ct-p[i].ft)>=2)
		{
			minp=i;
			minat=p[i].at;
		}
	}
	return minp;
}
void showGanttchart()
{
	for(i=0;i<sch_cnt*5;i++)
		printf("_");
	printf("\n|");
	for(i=0;i<sch_cnt;i++)
		printf(" P%d| ",sch[i].pid);
	printf("\n");
	for(i=0;i<sch_cnt*5;i++)
		printf("_");
	printf("\n0");
	for(i=0;i<sch_cnt;i++)
		printf("%5d",sch[i].endtime);
}
void showPT()
{
	float avgtat=0,avgwt=0;
	printf("\n");
	printf("\nPID\tFBT\tNBT\tAT\tFT\tTAT\tWT\n");
	for(i=0;i<np;i++)
	{
		printf("\n%d\t%d\t%d\t%d\t%d\t%d\t%d\n",i,p[i].f_bt,p[i].n_bt,p[i].at,p[i].ft,p[i].tat,p[i].wt);
	        avgtat+=p[i].tat;
		avgwt+=p[i].wt;
	}
	avgtat=avgtat/np;
	avgwt=avgwt/np;
	printf("Average turn around time:%f",avgtat);
	printf("\n Average waiting time:%f\n",avgwt);
}
