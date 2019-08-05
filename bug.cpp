/* parent.cpp */
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

    for(int i=0; i<BUG_COUNT; i++)
    {
        printf("[parent]%d\n",i);
        pid_t fork_state = vfork(); 
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
    //printf("[parent]");
    char cstr[bugs[keep].size() + 1];
    switch(PID[keep])
    {
        case -1:
            perror("fork()");
            exit(-1);
        case 0:
            PID[keep] = getpid();
            printf("[Child] Child's PID is %d\n", getpid());
            printf("[Child] i is %d \n",keep);
            //for (int _=0; _<3; _++)
                printf("Bug HaHa Bug!!\n");
            //std::cout << bugs[keep];
            strcpy(cstr, bugs[keep].c_str());
            //std::cout << cstr;
            execlp(cstr,cstr,NULL);
            break;
        default:
            sleep(5);
            int status;
            //std::cout << PID[0];
            waitpid(PID[0], &status, 2);
            //std::cout << status;
            int exit_status = WEXITSTATUS(status);         
            printf("Waaa QAQ, I Hate U!! Here is  %d\n", exit_status); 
    }
    return 0;
}
