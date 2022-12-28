#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>

int main(){
	pid_t pid;
	pid = fork();

	if(pid<0){ fprintf(stderr,"Fork Failed");}
	else if(pid ==0){
		execlp("file001.txt","wc",NULL);

	}
	else{
		wait(NULL);
		printf("Child Complete \n");	
	}
return 0;
		



}
