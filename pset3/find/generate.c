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
 
#define _XOPEN_SOURCE

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// constant
#define LIMIT 65536

int main(int argc, string argv[])
{
    // check if there are command line arguments or not 
    // print the usage if not provided 
    if (argc != 2 && argc != 3)
    {
        printf("Usage: generate n [s]\n");
        return 1;
    }

    // convert the first argument to int
    int n = atoi(argv[1]);

    // check for the second argument 
    if (argc == 3)
    {
        // seed with second argument as intialization seeds
        srand48((long int) atoi(argv[2]));
    }
    else
    {
        // seed with number of seconds from 1970
        srand48((long int) time(NULL));
    }

    // print n random numbers
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", (int) (drand48() * LIMIT));
    }

    // success
    return 0;
}