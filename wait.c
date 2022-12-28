#include<unistd.h>
#include<sys/types.h>
#include<stdio.h>
#include<sys/wait.h>

int main(){
int p;
printf("before fork \n");
p = fork();
if (p==0){printf("my child'd id is %d \n",getpid()); }
else { wait(NULL);
printf("I am parent having id %d \n",getpid());
}
printf("END \n");


}
