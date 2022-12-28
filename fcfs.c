#include<stdio.h>
#include<string.h>

struct Process{
	char pname[5];
	int AT,BT,TAT,WT,CT;
	int tempbt;
}P[10];
int N;
int TQ;

void Input(){

int i ;
printf("\nEnter Number of process : ");
scanf("%d",&N);
for (i=0;i<N;i++){
	printf("\nEnter Details of Process %d",i+1);
	printf("\nEnter process name : ");
	scanf("%s",&P[i].pname);
	
	printf("\nEnter AT : ");
	scanf("%d",&P[i].AT);
	
	printf("\nEnter BT : ");
	scanf("%d",&P[i].BT);
	P[i].tempbt = P[i].BT;
}


}
void sortprocessat(){

	int i,j,tval;
	char tmp[5];
	for (i = 0; i < N; i += 1)
	{
		for (j = 0; j < N; j += 1)
		{
			if (P[i].AT<P[j].AT)
			{
				strcpy(tmp,P[i].pname);
				strcpy(P[i].pname,P[j].pname);
				strcpy(P[j].pname,tmp);
				
				tval = P[i].AT;
				P[i].AT =  P[j].AT;
				P[j].AT = tval;
				
				tval = P[i].BT;
				P[i].BT =  P[j].BT;
				P[j].BT = tval;
				
				tval = P[i].tempbt;
				P[i].tempbt =  P[j].tempbt;
				P[j].tempbt = tval;
			}
		}
	}

}


void output(){
	int i,totaltat=0,totalwt=0;

	for (i = 0; i < N; i += 1)
	{
		if (i==0)
		{
			P[i].CT=P[i].BT;
		}
		else {
			P[i].CT=P[i-1].CT+P[i].BT;
		}
		
		P[i].TAT=P[i].CT-P[i].AT;
		totaltat = totaltat+P[i].TAT;
		
		P[i].WT = P[i].TAT - P[i].BT;
		totalwt = totalwt + P[i].WT;
		
		
	}
	
	printf("\nProcess Details");
	printf("\n***********************************************");
	printf("\nPname \t AT \t BT \t TAT \t WT");
	printf("\n***********************************************");
	
	for (i = 0; i < N; i += 1)
	{
		printf("\n%s\t%d\t%d\t%d\t%d",P[i].pname,P[i].AT,P[i].BT,P[i].TAT,P[i].WT);
		printf("\n***********************************************");
		
	}
	
	
	printf("\n AVG TAT : %d / %d = %d",totaltat,N,totaltat/N);
	printf("AVG WT : %d / %d = %d ",totalwt,N,totalwt/N);
}

void FCFS(){
	int i,time=0,finish=0,flag=0;
	while (finish!=0)
	{
		flag = 0;
		for (i = 0; i < N; i += 1)
		{
			if(P[i].AT<=time && P[i].tempbt !=0){
				printf("|%d %s",time,P[i].pname);
				time = time+P[i].tempbt;
				printf("%d|",time);
				P[i].tempbt=0;
				P[i].CT = time;
				
				flag = 1;
			}
		}
		
		if (flag==0){
			printf("|%d #",time);
			time++;
			printf("%d|",time);
		}
		
		for (i = 0; i < N; i += 1)
		{
			if (P[i].tempbt==0){continue;}
			else{break;}
			
		}
		if(i==N){finish=0;}
	}

}

int main(){
Input();
sortprocessat();
FCFS();
output();
}

