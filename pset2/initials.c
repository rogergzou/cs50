#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    string name = GetString();
    bool isFirst = true;
    
        for (int i = 0, n = strlen(name); i < n; i++)
        {
            if (name[i] == ' ')
            {
                isFirst = true;
            }
            else 
            {
                if (isFirst)
                {
                    if (name[i] >= 'A' && name[i] <= 'Z')
                    {
                        printf("%c", name[i]);
                    }
                    else if (name[i] >= 'a' && name[i] <= 'z')
                    {
                        printf("%c", name[i] - 'a' + 'A');
                    }
                    isFirst = false;
                }
            }
            
        }
    
    printf("\n");
}

