#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

#define M_LENGTH 25
#define R 0
#define W 1



int main() {
    int fd_1[2];
    int fd_2[2];
    char message[M_LENGTH] = "Hello World @123";
    char m_recieved_child[M_LENGTH];
    char m_recieved_parent[M_LENGTH];

    int pipe1_created = pipe(fd_1);
    int pipe2_created = pipe(fd_2);
    if (pipe1_created == -1 || pipe2_created == -1){
        printf("Error creating the pipe \n"); 
        exit(1);
    }

    int rc = fork();
    if (rc  < 0){
        printf("Error forking a child \n");
        exit(1);
    }

    if (rc>0){
        printf("Parent Process writing message \n");
        close(fd_1[R]);
        close(fd_2[W]);
        write(fd_1[W], message, M_LENGTH);
        close(fd_1[W]);

        read(fd_2[R], m_recieved_parent, M_LENGTH);
        close(fd_2[R]);
        printf("Message Received by Parent: %s \n", m_recieved_parent);
        wait(NULL);
    }
    else {
        close(fd_1[W]);
        close(fd_2[R]);
        read(fd_1[R], m_recieved_child, M_LENGTH);
        close(fd_1[R]);
        printf("Message Received by Child: %s \n", m_recieved_child);
        
        int i=0;
        for (i=0; i<M_LENGTH; i++){
            if(m_recieved_child[i]>='A' && m_recieved_child[i]<='Z') m_recieved_child[i] += 32;
            else if (m_recieved_child[i]>='a' && m_recieved_child[i]<='z') m_recieved_child[i] -= 32;
        }
        printf("Child Process transformed and sent the message \n");
        
        write(fd_2[W], m_recieved_child, M_LENGTH);
        close(fd_2[W]);
    }
}
