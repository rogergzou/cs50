#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>


int main(int argc, string argv[])
{
    /*int key = GetInt();
    if (key == NULL || key < 0)
    {
        return 1;
    }
    string text = GetString();
    key %= 26;
    */
    int key;
    if (argc == 2)
    {
        key = atoi(argv[1]);
        key %= 26;
    }
    else
    {   
        printf("Enter a number with the command line argument\n");
        return  1;
    }
    string code = GetString();
    char a;
    int ascii;
    bool isUpper;
    for (int i = 0, n = strlen(code); i < n; i++)
    {
        
        a = code[i];
        
        ascii = a;
        if (ascii >= 'a' && ascii <= 'z')
        {
            isUpper = false;
        }
        else
        {
            isUpper = true;
        }
        
        // bool isCharacter = isalpha(a)
        /* if (!((ascii >= 'a' && ascii <= 'z') || (ascii >= 'A' && ascii <= 'Z')))
        {
            if (!((ascii >= ' ' && ascii <= '@') || (ascii >= '[' && ascii <= 'a')))
            {
                if (!(ascii >= '{' && ascii <= '~'))
                {
                */
        // if (!isCharacter)
        // {
            // what do I even want to do here
        // }
                /*
            }
            // ascii unchanged
        }
        */
        
        if (isalpha(ascii) != 0)
        {
            ascii += key;
            
            if (ascii > 'Z' && ascii < 'a')
            {
                ascii -= 26;
            }
            else if (ascii > 'z')
            {
                ascii -=26;
            }
            else if (ascii >= 'a' && (isUpper == true))
            {
                ascii -= 26;
            }
        }
        a = ascii;
        printf("%c", a);
        }
    
    printf("\n");
    return 0;
}

