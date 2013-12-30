#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "wiringPi.h"

int main( )
{
    if(wiringPiSetup() == -1){
        printf("Failed to setup wiringPi\n", );
    }
    
    pinMode(7, INPUT);
    
    while(1)
    {
        if(digitalRead(7) != 0){
            printf("Attempting to shutdown the system...\n", );
            system("sudo halt");
        }
        
        usleep(100000); // 10fps
    }
}
