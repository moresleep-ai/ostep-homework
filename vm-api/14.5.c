#include <stdlib.h>
#include <stdio.h>

int main(){
    int *data = (int *)malloc(sizeof(int) * 100);
    data[50] = 99;
    free(data+50);
    printf("%d\n", data[50]);
    return 0;
}