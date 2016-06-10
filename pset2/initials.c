#include<stdio.h>
#include<cs50.h>
#include<ctype.h>
#include <string.h>

int main()
{
    
    string name = GetString();
    
    for(int i = 0 , j = strlen(name) ; i<j ; i++){
    
        if(i == 0){
            name[i] = toupper(name[i]);
            continue;
        }
        
        if(name[i] == ' '){
             name[i+1] = toupper(name[i+1]);
             continue;  
        }
        
    }
    
    for(int i = 0 , j = strlen(name) ; i<j ; i++){
        if(i == 0){
            printf("%c" , name[i]);
        }
        
         if(name[i] == ' '){
            printf("%c" , name[i+1]);
         }
    }
    
    printf("\n");
    
    return 0;
}