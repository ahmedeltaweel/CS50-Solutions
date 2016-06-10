#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>


char newCharSmall(char c , char k)
{
    int index = (int)c - 97;
    int j;
    if(isupper(k))
        j = (index + (k - 65)) % 26;
    else
        j = (index + (k - 97)) % 26;
    char newc = j + 97;
    return newc;
}

char newCharCapital(char c , char k)
{
    int index = (int)c - 65;
    int j;
    if(isupper(k))
        j = (index + (k - 65)) % 26;
    else
        j = (index + (k - 97)) % 26;
    char newc = j + 65;
    return newc;
}

int main(int argc , string argv[])
{
    
    if(argc != 2){
        printf("Please, Enter positive number");
        return 1;
    }
    
    string k = argv[1];
    
    for(int i = 0 , j = strlen(k) ; i<j ; i++){
        if(!isalpha(k[i])){
            printf("PLease, enter a key od string");
            return 1;
        }
    }
    
    int counter = 0;
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
            counter %= strlen(k);
            encrypted [i]= newCharCapital(plain[i] , k[counter]);
            counter++;
        }
        
        if(islower(plain[i])){
            counter %= strlen(k);
            encrypted [i]= newCharSmall(plain[i] , k[counter]);
            counter++;
        }
    }
    
    printf("%s\n" , encrypted);
    
    return 0;
}