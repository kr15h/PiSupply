#include <unistd.h>
#include <iostream>
#include <stdlib.h>
#include "wiringPi.h"

using namespace std;

int main( )
{
    if(wiringPiSetup() == -1){
        cout << "Error on wiringPi setup." << endl;
    }
    
    pinMode(7, INPUT);
    
    while(1)
    {
        if(digitalRead(7) != 0){
            cout << "Attempting to shutdown the system..." << endl;
            system("sudo halt");
        }
        
        usleep(16666); // 16666 = 60fps
    }
}
