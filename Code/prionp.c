#include<stdio.h>
#include<stdlib.h>

struct process
{
	int f_bt,t_bt,n_bt,at,tat,wt,ft,prio;
}p[100];
struct schedule
{
	int pid,endtime;
}sch[100];
int sch_cnt,ct,np,i;
void main()
{
	accept();
	while(1)
	{
		int x=getProcessByprioNP();
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
		int x=getProcessByprioNP1();
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
	showGanttChart();
	showPT();
}
accept()
{
	printf("enter n of processors:");
	scanf("%d",&np);
	for(i=0;i<np;i++)
	{
		printf("enter Arival time");
		scanf("%d",&p[i].at);
		printf("enter first burst time");
		scanf("%d",&p[i].f_bt);
		printf("Enter priority:");
		scanf("%d",&p[i].prio);
		p[i].t_bt=p[i].f_bt;
		p[i].n_bt=rand()%5+1;
	}
}
int getProcessByprioNP()
{
	int minp=-1;
	int minat=32768;
	for(i=0;i<np;i++)
	{
		if(p[i].at<=ct && p[i].t_bt>0 && p[i].prio<minat)
		{
			minp=i;
			minat=p[i].prio;
		}
	}
	return minp;
}
int getProcessByprioNP1()
{
	int minp=-1;
	int minat=32768;
	for(i=0;i<np;i++)
	{
		if(p[i].at<=ct && p[i].t_bt>0 && p[i].prio<minat && (ct-p[i].at)>=2)
		{
			minp=i;
			minat=p[i].prio;
		}
	}
	return minp;
}
showGanttChart()
{
	for(i=0;i<sch_cnt*5;i++)
	printf("-");
	printf("\n|");
	for(i=0;i<sch_cnt;i++)
	printf(" p%d |",sch[i].pid);
	printf("\n");
	for(i=0;i<sch_cnt*5;i++)
	printf("-");
	printf("\n0");
	for(i=0;i<sch_cnt;i++)
	printf("%5d",sch[i].endtime);
}
showPT()
{
	float avgtat=0,avgwt=0;
	printf("\n");
	printf("\nPID\tFBT\tNBT\tAT\tFT\tTAT\tWT\tprio\n");
	for(i=0;i<np;i++)
	{
		printf("\n%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",i,p[i].f_bt,p[i].n_bt,p[i].at,p[i].ft,p[i].tat,p[i].wt,p[i].prio);
		avgtat+=p[i].tat;
		avgwt+=p[i].wt;
	}
	avgtat=avgtat/np;
	avgwt=avgwt/np;

	printf("average turn around time:%f",avgtat);
	printf("\n average waiting time:%f\n",avgwt);
}

