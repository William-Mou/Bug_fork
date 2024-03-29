/* bug.cpp */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string>
#include <cstring>
#include <iostream>
#define BUG_COUNT 6

int main(){
    int exit_status;
    int keep = -1;
    pid_t PID[6];
     pid_t fork_state; 
    for(int i=0; i<BUG_COUNT; i++)
    {
        fork_state = vfork(); 
        keep = i;
        if (fork_state ==0)
            break;
    }
    std::string bugs[BUG_COUNT] = {
    "Lymantria dispar",
    "Tenebrio molitor",
    "Tessaratoma papillosa",
    "Lampyridae",
    "Siphonaptera",
    "Chironomidae"
    };
    char cstr[bugs[keep].size() + 1];
    switch(fork_state)
    {
        case -1:
            perror("fork()");
            exit(-1);
        case 0:
            PID[keep] = getpid();
            //printf("[Child] Child's PID is %d\n", getpid());
            //printf("[Child] i is %d \n",keep);
            for (int _=0; _<3; _++)
                printf("Bug HaHa Bug!!\n");
            strcpy(cstr, bugs[keep].c_str());
            execlp(cstr,cstr,NULL);
            break;
        default:
            int status;
            waitpid(PID[0], &status, 2);
            int exit_status = WEXITSTATUS(status);         
            printf("[PID=%d]Waaa QAQ, I Hate U!! Here is  %d\n",getpid(), exit_status); 
    }
    return 0;
}
