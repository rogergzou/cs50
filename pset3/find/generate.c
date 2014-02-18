/**
 * generate.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Generates pseudorandom numbers in [0,LIMIT), one per line.
 *
 * Usage: generate n [s]
 *
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 */
       
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LIMIT 65536

int main(int argc, string argv[])
{
    // prints instructions if argument count isn't equal to 2 or 3
    if (argc != 2 && argc != 3)
    {
        printf("Usage: ./generate n [s]\n");
        return 1;
    }

    // initializes n as the int (conv from string) of 1st argument
    int n = atoi(argv[1]);

    // if 2nd argument, convert it to int and use as seed of rand()
    // (unsigned int) means will be a positive or zero integer
    if (argc == 3)
    {
        srand((unsigned int) atoi(argv[2]));
    }
        // else if no 2nd argument, use time to get random seed for rand()
        // (unsigned int) means will be a positive or zero integer
    else
    {
        srand((unsigned int) time(NULL));
    }

    // print n random numbers using rand less than the LIMIT (65536)
    // n is the number inputted as the second arg on the cmd line
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", rand() % LIMIT);
    }

    // that's all folks
    return 0;
}
