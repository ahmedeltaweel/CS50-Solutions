/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

#include "dictionary.h"

// number of words.
int wordcount = 0;

// defining the root.
struct node *root = NULL;

struct node *getNode(void);

void createTrie(const char* word , struct node *root);

void freeNode(struct node* root);


/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    
    struct node* current = root;
    
    for ( int i = 0 , j = strlen(word) ; i < j ; i++ )
    {
        int position = 0;
            
        if (word[i]=='\'')
            position = 26;
        else
            position = tolower(word[i]) - 'a';
           
        if(!current->children[position])
        {
            return false;
        }   
        
        current = current->children[position];
    }
    
    return (current != NULL && current->is_word);;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    root = getNode();
    
    char word[LENGTH+1];
    int index = 0;
    
    FILE* fp = fopen(dictionary, "r");
    
    if (fp == NULL)
    {
        printf("Could not open bleh.\n");
        return false;
    }
    
    for (int c = fgetc(fp); c != EOF; c = fgetc(fp))
    {
        
        // Check to see if char is a
        if (isalpha(c) || c == '\'')
        {
            word[index] = c;
            index++;
        }
        else if (isalpha(c) == 0)
        {
            word[index] = '\0';
            createTrie(word , root);
            index = 0;
            wordcount++;
        }
        
        
    }
   
    fclose(fp);
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    
    return wordcount;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    for (int i = 0 ; i < ALPHABET_SIZE ; i++)            // can't just call freeNode(&root),this will cause free(&root),but
    {
        if (root->children[i] != NULL)  // root is not in heap(cause it's not allocated by malloc)
            freeNode(root->children[i]);
    }
    free(root);
    return true;
}


/**
 * create new node of trie.
 * 
 * @parm void.
 * 
 * @return node| new node.
 */
struct node *getNode(void)
{
    struct node *pNode = NULL;
 
    pNode = (struct node *)malloc(sizeof(struct node));
 
    if (pNode)
    {
        int i;
 
        pNode->is_word = false;
 
        for (i = 0; i < ALPHABET_SIZE; i++)
            pNode->children[i] = NULL;
    }
 
    return pNode;
}


/**
 * insert word to trie.
 * 
 * @parm string|word to insert.
 * 
 * @parm struct|root the root of trie.
 * 
 * @return void.
 */
void createTrie(const char* word , struct node* root)
{
    struct node *current = root;
    for ( int i = 0 , j = strlen(word) ; i < j ; i++ )
    {
        
        if(word[i] != '\0' ){
            
            int position = 0;
            
            if (word[i]=='\'')
                position = 26;
            else
                position = tolower(word[i]) - 'a';
        
            if(current->children[position] == NULL)
            {
                    current->children[position] = getNode();
            }   
        
            current = current->children[position];
        }else{
            break;
        }
    }
     
    //mark as word
    current->is_word = true;
}

/**
 * free all memeory in a tire.
 * 
 * @parm node root.
 * 
 * @return void.
 */
void freeNode(struct node* root)
{
    struct node *current = root;
    
    for (int i = 0 ; i < ALPHABET_SIZE ; i++){
        if(current->children[i] != NULL){
            freeNode(current->children[i]);
        }
    }
    free(current);
}