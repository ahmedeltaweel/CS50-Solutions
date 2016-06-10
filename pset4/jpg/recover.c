/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */
 
#include <stdio.h>
#include <stdint.h>
 
 
typedef uint8_t BYTE;

int main(int argc, char* argv[])
{
    // opening file to read data
    FILE* file = fopen("card.raw", "r");
    
    // check if file failed to open
    if ( file == NULL ){
        fclose(file);
        printf("unable to open file\n");
        return 2;
    }
    
    int counter = 0;
    
    BYTE buffer[512];
    
    char name[10];
    
    FILE* tmp = NULL;
    
    while ( ! feof(file) ){
        
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] == 0xe0 || buffer[3] == 0xe1)){
            
            if (tmp != NULL){
                fclose(tmp);
            }
            
            sprintf(  name , "%03d.jpg" , counter );
            
            tmp = fopen( name , "w" );
            
            fwrite(buffer , sizeof(buffer) , 1 , tmp);
            
            counter ++ ;
            
        } else if (counter > 0) {
            // put jpg into temp
            fwrite(buffer, sizeof(buffer), 1, tmp);            
        }
        
        fread(buffer, sizeof(buffer), 1, file);
    }
    
     // close the file
    fclose(file);

    // that's all folks
    return 0;
    
}
