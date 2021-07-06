#include "../include/timer.h"

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

struct tm* getCurrentTime(){
    time_t current;
    time(&current);
    struct tm * info = localtime(&current);
    return info;
}

