#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
void childprocess();
void parentprocess();
int main(){
	pid_t pid;
	pid = fork();
	if(pid ==0)  {
		parentprocess();
	}
	else {
		childprocess();
	}
	return 0;

}

void parentprocess(){ printf("I am parent process \n");}
void childprocess(){printf("I am child Process \n");}
