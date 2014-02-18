#include <cs50.h>
#include <stdio.h>
#include "helpers.h"
#include "helpers.c"

int main(void)
{
    int array[] = {6,4,2,8,1};
    sort(array, 5);
    for (int i = 0; i < 5; i++)
        printf("%d\n", array[i]);
    





    return 0;
}
