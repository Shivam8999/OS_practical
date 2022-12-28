#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(){

int pid;
pid = fork();
if (pid<0){
	printf("failed to Fork \n");
	exit(1);
}
else if(pid>0){
	printf("\n Prent executed : %d ", getpid());
	sleep(7);
}
else {
	printf("\n Child Executed : %d \n",getpid());
	sleep(10); }
	
printf("\n\n Parent Terminated: %d \n", getpid());
exit(1);
}
