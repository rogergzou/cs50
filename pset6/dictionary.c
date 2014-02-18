/****************************************************************************
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 6
 *
 * Implements a dictionary's functionality.
 * Roger Zou
 ***************************************************************************/

#include <stdbool.h>

#include "dictionary.h"

/**
 * IMPORTANT
 * READ FIRST
 * 
 * global node, hashtable, dicsize declared in HEADER FILE dictionary.h
 *
 * stackoverflow.com/questions/4384359/quick-way-to-implement-dictionary-in-c
 */
 
 
// hash function based off first character, creates a number
unsigned hash(const char* word)
{
    
    unsigned hash = word[0] - 'A';
    if (hash)
    {
        
        return hash % SIZE;
    }
    else
    {
        return 0;
    }
}

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    // creates a lowercase copy of the word
    int len = strlen(word);
    char wordz[len + 1];
    for (int i = 0; i < len; i++)
    {
        wordz[i] = tolower(word[i]);
    }
    wordz[len] = '\0';
    
    // gets hash number
    int hashnumber = hash(wordz);
    
    // checks for NULL possibility
    if (hashtable[hashnumber] == NULL)
    {
        return false;
    }
    
    // goes through linked list, checks if lowercase word matches any dic word
    node *cursor = hashtable[hashnumber];
    while (cursor != NULL)
    {
       
        if ( strcmp(cursor->word, wordz) == 0)
        {
            return true;
        } 
        
        cursor = cursor->next;
    }
    
    // if not found, return false
    return false;
}


/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    
    // gets the dictionary into a file
    FILE* fp = fopen(dictionary, "r");
    
    // checks for NULL possibility
    if (fp == NULL)
    {
        return false;
    }
    
    // runs and reads until reaches dictionary end of file
    while(feof(fp) == 0)
    {
        // increase dictionary size (short syntax)
        dicsize++;
        
        // creates new node, gets/stores dictionary word into new node's word
        node* new_node = malloc(sizeof(node));
        fscanf(fp, "%s", new_node->word);
        
        // gets the hash for the word
        unsigned int hashnumber = hash(new_node->word);
        
        // if node doesn't exist, assigns hashtable to point to new node
        if (hashtable[hashnumber] == NULL)
        {
            hashtable[hashnumber] = new_node;
            new_node->next = NULL;
        }
        // node does exist, so assigns hashtable to point to new node
        // also assigns new node to point to w/e hashtable was pointing to
        else
        {
            new_node->next = hashtable[hashnumber];
            hashtable[hashnumber] = new_node;
        }
    }
    // just to make WORDS IN DICTIONARY equal the staff's solution o.o
    // dicsize--;
    // JK I don't even know what
    
    // closes the dictionary file
    fclose(fp);
    
    // says loaded correctly
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // gets dictionary size (global), returns. If not exist, returns 0.
    if (dicsize)
    {
        return dicsize;
    }
    else
    {
        return 0;
    }
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    // creates word elimination counter
    int words = 0;
    
    // runs unloading through every hashtable entry
    for (int i = 0; i < HASHPOSSIBILITIES; i++)
    {
        
        // node jaja created, assigned node in the hashtable
        node* jaja = hashtable[i];
        
        // only executes if hashtable's node not NULL
        // executes until linked list has nothing
        while (jaja != NULL)
        {
            // creates another node, assigned to jaja
            node* noderef = jaja;
            
            // reassigns jaja to point to the next node in the list
            jaja = noderef->next;
            
            // frees the node we just left
            free(noderef);
            
            // increments words destroyed count b/c just freed a node
            words++;

        }
    }
    
    // after loop/frees, checks to see if we destroyed
    // as many words as there were in the dictionary
    // if we did, returns true to show success
    if (words == dicsize)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}
