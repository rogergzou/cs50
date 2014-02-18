#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    string codeword;
    if (argc == 2)
    {
        codeword = argv[1];
        // stores the string (really a number) in codeword
    }
    else
    {   
        printf("Enter a word with the command line argument\n");
        return  1;
        // fails if there are not two arguments
    }
    
    char buffer;
    int ascii;
    int key;
    bool isUpper;
    int skip = 0;
    int repeater;
    for ( int j = 0, s = strlen(codeword); j < s; j++)
        // for pete's sake style50, s is just a loop variable
        // goes through whole of the command line word
    {
        ascii = codeword[j];
        // ascii is an integer, codeword[j] is a character
        // so ascii becomes the ascii integer of codeword[j]
        if (!isalpha(ascii))
            // !isalpha(ascii) returns true when ascii is not a letter
        {
            printf("Enter only letters please on the command line\n");
            return 1;
            // if keyword isn't letter, fails and returns 1
        }
    }
    string code = GetString();
    // asks for the string to encode
    for ( int i = 0, n = strlen(code); i < n; i++)
        // goes through whole of the inputted word
    {
        repeater = (i - skip) % strlen(codeword);
        // repeater confined to length of the codeword used to encode
        // also adjusts letter used if skip needed for non-letter in code
        buffer = codeword[repeater];
        // converts codeword[repeater], a character, to int and stores in buffer
        key = buffer;
        // I decided I liked the word key better
        /* if (!((key >= 'a' && key <= 'z') || (key >= 'A' && key <= 'Z')))
            
        {
            printf("Enter only letters please on the command line\n");
            return 2;
        } */
        // outdated code
        if (key >= 'A' && key <= 'Z')
        {
            key -= 65;
            // if capital letter, reduces to a number 0-25
        }
        else if (key >= 'a' && key <= 'z')
        {
            key -= 97;
            // if lowercase letter, reduces to a numbe 0-25
        }
        else
        {
            printf("Enter only letters please on the command line\n");
            return 2;
            // if command line not a letter, exits
            // should be unnecessary, but extra redundancy in case
        }
        
        buffer = code[i];
        ascii = buffer;
        // ascii is an integer, code[i] is a character
        // so ascii becomes the ascii integer of code[i]
        if (ascii >= 'a' && ascii <= 'z')
        {
            isUpper = false;
        }
        else
        {
            isUpper = true;
        }
        // checks to see if ascii is uppercase or lowercase intitially
        if (!isalpha(ascii))
        {
            printf("%c", buffer);
            skip += 1;
        }
            // !isalpha(ascii) true when not a letter
            // If so, prints unchanged character and skips to next character
        else 
        {
            ascii += key;
            // adjusts ascii # by the key/character
            if (ascii > 'Z' && ascii < 'a')
            {
                ascii -= 26;
            }
                // adjusts ascii from non-letter back to letter #
            else if (ascii > 'z')
            {
                ascii -= 26;
            }
                // adjusts ascii from non-letter back to letter #
            else if (ascii >= 'a' && (isUpper == true))
            {
                ascii -= 26;
            }
            // adjusts ascii to move back to uppercase if was uppercase before
            buffer = ascii;
            // reassigns ascii # back to buffer character
            printf("%c", buffer);
            // prints character
        }
    
    }
    printf("\n");
    // prints another line


    
    
    return 0;
}
