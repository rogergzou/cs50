/****************************************************************************
 * dictionary.h
 *
 * Computer Science 50
 * Problem Set 6
 *
 * Declares a dictionary's functionality.
 ***************************************************************************/

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>

// maximum length for a word
// (e.g., pneumonoultramicroscopicsilicovolcanoconiosis)
#define LENGTH 45
#define HASHPOSSIBILITIES 60
#define SIZE 60
// defines node as with array of characters and a child node for making the linked list
typedef struct node
{
    char word[LENGTH + 1];
    struct node* next;
} node; 

// creates hashtable of nodes with size HASHPOSSIBILITIES
node* hashtable[HASHPOSSIBILITIES];

// creates global variables needed later
int dicwords;
int dicsize;

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word);

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary);

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void);

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void);

/**
 * Implements hash bitches
 */
unsigned hash(const char* word);

#endif // DICTIONARY_H
