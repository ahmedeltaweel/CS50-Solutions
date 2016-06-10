#include <stdio.h>
#include <cs50.h>
#include <math.h>

#define quarters 25
#define dimes 10
#define nickels 5
#define pennies 1

int main(void)
{
    float amount;
    int counter = 0;
    do{
        printf("How much change is owed? ");
        amount = GetFloat();
    }while(amount < 0);
    
    int realAmount = (int) round(amount*100);
    
    while(realAmount - quarters >= 0)
    {
        realAmount -= quarters;
        counter++;
    }
    
    while(realAmount - dimes >= 0)
    {
        realAmount -= dimes;
        counter++;
    }
    
    while(realAmount - nickels >= 0)
    {
        realAmount -= nickels;
        counter++;
    }
    
    while(realAmount - pennies >= 0)
    {
        realAmount -= pennies;
        counter++;
    }
    
    printf("%d\n",counter);
    
}