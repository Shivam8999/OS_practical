#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){

int pid = fork();
if (pid>0){
	printf ("parent process id = %d \n ",getpid()); 
	}
else if (pid ==0){
	printf ("child process id = %d \n ",getpid()) ;
	sleep(5);
	printf ("child process id = %d \n ",getpid()) ;
	printf("parent terminated then P-ID : %d \n",getpid());
	}
else {
	printf("Failed to create child process");
	}
	waitpid(pid,NULL,0);
	//return 0;
}
