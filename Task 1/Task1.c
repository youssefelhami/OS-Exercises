#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MIN_PID 100
#define MAX_PID 1000

static int size = MAX_PID - MIN_PID + 1;


int allocate_map(void);
int allocate_pid(void);
void release_pid(int pid);

bool* pid_map = NULL;

int main() {
    
    ///////////////////////////////Test Case 1/////////////////////////////
    
    printf("Test Case 1: allocate PID map and check if any PID is unavailable\n");
    if(allocate_map() == -1){
        printf("unable to create the pid map\n");
        return 0;
    }
    
    bool unavailable = false;
    for (int i =0; i<size; i++){
        if (pid_map == false)
        {
            printf("Unavailable PID found\n");
            unavailable = true;
            break;
        }
    }
    if (unavailable == false)
        printf("No unavailable PID found\n");
    
    ////////////////////////////Test Case 2////////////////////////////////

    int pid = 0;
    printf("\nTest Case 2: allocate PID then release it twice\n");
    pid = allocate_pid();
    printf("PID: %d\n", pid);
    release_pid(pid);
    release_pid(pid);

    ///////////////////////////Test Case 3/////////////////////////////////
    
    printf("\nTest Case 3: allocate PID without an available place in array\n");
    for(int i = 0; i < size; i ++){
        pid = allocate_pid();
        if (pid == 1)
            printf("PID map is full during original allocation, cannot allocate PID for process\n");
    }
    pid = allocate_pid();
    if (pid == 1)
        printf("PID map is full, cannot allocate PID for process\n");
   
    //////////////////////////Test Case 4//////////////////////////////////
    
    printf("\nTest Case 4: release PID outside of the domain\n");
    release_pid(MAX_PID+1);
    release_pid(MIN_PID-1);
  
    /////////////////////////Test Case 5///////////////////////////////////
    
    printf("\nTest Case 5: reallocate PID map and check if any PID is unavailable\n");
    if(allocate_map() == -1){
        printf("unable to create the pid map\n");
        return 0;
    }
    
    unavailable = false;
    for (int i =0; i<size; i++){
        if (pid_map == false)
        {
            printf("Unavailable PID found\n");
            unavailable = true;
            break;
        }
    }
    if (unavailable == false)
        printf("No unavailable PID found\n");
        
    /////////////////////////// END /////////////////////////////////

}

int allocate_map(void){
    if (pid_map != NULL){
        free(pid_map);
    }
    pid_map = malloc(sizeof(bool) * size);
    if (pid_map == NULL){
        return -1;
    }
    for (int i = 0; i< size; i++){
        pid_map[i] = false;
    }
    return 1;
}

int allocate_pid(void){
    
    for (int i = 0; i< size; i++){
        if (pid_map[i] == false){
            pid_map[i] = true;
            return MIN_PID+ i;
        }
    }
    return 1;
}


void release_pid(int pid){
    int origPid = pid;
    pid = pid - MIN_PID;
    if (origPid < MIN_PID || origPid >= MAX_PID){
        printf("Invalid PID: %d \n", origPid);
        return;
    }
    if(pid_map[pid] == true){
        pid_map[pid] = false;
        printf("PID %d is released \n", origPid);
    } else {
        printf("PID %d is already free \n", origPid);
    }
}