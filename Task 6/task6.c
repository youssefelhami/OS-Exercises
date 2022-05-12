#include <stdio.h>
#include <stdlib.h>


// a page is 4kb => 4096 bytes
#define PG_BYTE 4096

int main(int argc, char *argv[]) 
{

    int address;
    char *ptr;
    
    if (argc != 2) {
        printf("Error: Invalid number of arguments \n");
        return -1;
    }
    // gets first element in command line and transforms it into a long of base 10
    address = (int)strtol(argv[1],&ptr ,10);
    
    if (address < 0){
        printf("Error: Address cannot be a negaitve number \n");
        return -1;
    }
    
    
    printf("The address %d contains:\n",address);

    int pg =  address/PG_BYTE;
    int ofst = address%PG_BYTE;

    printf("page number = %d\n",pg);
    printf("offset = %d\n",ofst);

    return 0;
}