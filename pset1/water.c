#include <stdio.h>
#include <cs50.h>
int main(void)
{
	printf("minutes: ");
	int x = GetInt();
	
	//implement the alogrithm
   int answer = 192/16;
   answer *= x;
   
   printf("bottles: %d\n" , answer);
   
   return 0;
}