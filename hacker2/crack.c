#include <stdio.h>
#include <cs50.h>
#include <string.h>
#define _XOPEN_SOURCE
#include <unistd.h>

// salt (first 2 chars?) can be [a-zA-Z0-9./], which is 26+26+10+2=64
int main(int argc, string argv[])
{
    string code = GetString();
    string a[8];
    a[1,3] = &code[2,4];
    printf("%s", a[1]);
    /*
    printf("%s", code);
    string key = NULL;
    for (int i = 0;  i < strlen(argv[1]); i++)
    {
        if (i < 2)
        {
            key[i] = argv[1][i];
        }
    } 
    printf("%s", key);
*/



return 0;
}
