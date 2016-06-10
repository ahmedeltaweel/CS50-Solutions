#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>


char newCharSmall(char c , int k)
{
    int index = (int)c - 97;
    int j = (index + k) % 26;
    char newc = j + 97;
    return newc;
}

char newCharCapital(char c , int k)
{
    int index = (int)c - 65;
    int j = (index + k) % 26;
    char newc = j + 65;
    return newc;
}

int main(int argc , string argv[])
{
    
    if(argc != 2){
        printf("Please, Enter positive number");
        return 1;
    }
    
    int k = atoi(argv[1]);
    
    if(k <= 0){
        return 1;
    }
    
    string plain = GetString();
    int length = strlen(plain);
    string encrypted = plain;
    
    for(int i = 0 ; i < length ; i++){
        if(plain[i] == ' '){
            encrypted[i] = ' ';
            continue;
        }
        
        if(isupper(plain[i]))
        {
            encrypted [i]= newCharCapital(plain[i] , k);
        }
        
        if(islower(plain[i])){
            encrypted [i]= newCharSmall(plain[i] , k);
        }
    }
    
    printf("%s\n" , encrypted);
    
    return 0;
}