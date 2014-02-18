/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include <stdio.h>
#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // Implements a searching algorithm
    // only works with sorted lists
    int middle = n / 2;
    int prevMiddle = 0;
    while ( n > 0)
    {
    
        if (value == values[middle])
        {
            return true;
            break;
        }
        else if (value > values[middle])
        {
            n = middle;
            middle = (prevMiddle + middle) / 2;
            
        }
        else if (value < values[middle])
        {
            prevMiddle = middle;
            middle = (n + middle) / 2;
            
        }
        return false;
    
    }
}
    
    
    
    
/*
    // I'M SAVING THIS ANYWAY
    if ( n < 0 )
    {
        printf("You used a negative number silly");
        return false;
    }
    else
    {
        bool checker = false;
        // default set as false just in case
        
        for (int i = 0; i < n; i++)
        {
            if ( value == values[i])
            {
                checker = true;
                break;
            }
        }
        // checker is true if found, false if not found
        return checker;
    }
}
 */
/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // Implements an O(n^2) sorting algorithm
    // selection sort
    int buffer;
    for ( int i = 0; i < n - 1; i++) 
    {
        int min = i;
        for ( int j = i + 1; j < n; j++)
        {
            if (values[j] < values[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            buffer = values[min];
            values[min] = values[i];
            values[i] = buffer;
        }
    
    
    }
    return;
}
