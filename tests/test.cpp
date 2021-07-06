#include <stdio.h>
#include <time.h>

int main(){
    time_t current;
    time(&current);
    struct tm *info = localtime(&current);
    printf("%s", asctime(info));
    printf("%d/%d/%d\n", info->tm_mday, info->tm_mon, info->tm_year);
    return 0;
}
