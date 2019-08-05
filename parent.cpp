/* parent.cpp */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
    int exit_status;
    pid_t PID = fork();
    

    switch(PID){
        case -1:
            perror("fork()");
            exit(-1);
        case 0:
            printf("[Child] Child's PID is %d\n", getpid());
            execlp("/Users/mouzhanyou/Documents/open_source_city/bug","bug",NULL);
        default:
            //printf("[Parent] Parent's PID is %d\n", getpid());
            wait(&exit_status);
            //printf("[Parent] Child's exit status is [%d]\n", WEXITSTATUS(exit_status));
            printf("關卡想要的拋錯訊息？");
    }

    return 0;
}
