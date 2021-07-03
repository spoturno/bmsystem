#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void otherTime();

int main(){
    time_t rawtime;
    struct tm *timeinfo;
    time(&rawtime);
    timeinfo = localtime (&rawtime);
    printf("Current local time and date: %s\n", asctime(timeinfo));
    otherTime();
    return 0;
}

void otherTime(){
    //read gnu docs
    //the following is an example of what could be implemented
    time_t now = time(NULL);
    struct tm tm_now;
    localtime_r(&now, &tm_now);
    char buff[100];
    strftime(buff ,sizeof(buff), "%Y-%m-%d|%H:%M", &tm_now);
    printf("Time is '%s'\n", buff);

}

//Some ideas:
//  current time of the manager being active
//  current time of the user in the memory
//  current time of the user last being logeed in
