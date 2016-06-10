/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    if(n <= 0)
    {
        return false;
    }
    
    int upper = n;
    int lower = 0;
    int mid = n / 2;
    while(upper >= lower)
    {
        if(values[mid] == value){
            return true;
        }
        else if(values[mid] > value)
        {
            upper = mid - 1;;
        }
        else if(values[mid] < value)
        {
            lower = mid + 1;;
        }
        
        mid = (upper + lower) / 2;
    }
    
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
    for(int i = 0 ; i < n-1 ; i++)
    {
        int min = i;
        for(int j = i+1 ; j < n ; j++)
        {
            if(values[j] < values[min])
            {
                min = j;
            }
        }
        if(min != i)
        {
            int tmp = values[i];
            values[i] = values[min];
            values[min] = tmp;
        }
    }
}
