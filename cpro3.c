#include<stdio.h>
#include<unistd.h>

int main()
{
printf("\nHello World");
int f=fork();
int p=getpid();
printf("\nthe pid is %d",p);
printf("\nthe f is: %d\n",f);
return 0;
}

[2021ict10@fedora ~]$ vi uni.c
[2021ict10@fedora ~]$ gcc uni.c -o uni
[2021ict10@fedora ~]$ ./uni

Hello World
the pid is 12201
the f is: 12202
Hello World
the pid is 12202
the f is: 0

//in the process
/*In this code:

When fork() is called, it creates a child process that's 
a copy of the parent
The key difference is what fork() returns:

In the parent process: fork() returns the PID of the newly 
created child
In the child process: fork() returns 0



So when you see the output:

The process where f is 0 is the child process
The process where f is a non-zero value (a positive number) 
is the parent process

Both processes will show their own PID (via getpid()), 
but only the parent process's f value will match the child's 
PID.*/

[2021ict10@fedora ~]$ vi uni.c

#include<stdio.h>
#include<unistd.h>

int main() {
    printf("\nHello World");
    
    int f = fork();
    int p = getpid();
    
    if (f == 0) {
        printf("\nThis is the child process");
        printf("\nthe pid is %d", p);
        printf("\nthe f is: %d\n", f);
    } else {
        printf("\nThis is the parent process");
        printf("\nthe pid is %d", p);
        printf("\nthe f is: %d (child's PID)\n", f);
    }
    
    return 0;
}
/*[2021ict10@fedora ~]$ gcc uni.c -o uni
[2021ict10@fedora ~]$ ./uni

Hello World
This is the parent process
the pid is 13818
the f is: 13819 (child's PID)
Hello World
This is the child process
the pid is 13819
the f is: 0*/


#include <stdio.h>
#include <unistd.h>
int main(){
    int f=fork();

    if(f == 0){
        printf("\nI am child");
        printf("\n")
    }else {
        int f2=fork();

        if(f2 == 0){
            printf("\nI am child");
        }
        else
        {
            printf("\nI am Parent \n");
        }
    }
    printf("Hello");
    return 0;
}
