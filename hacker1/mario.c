#include <stdio.h>
#include <cs50.h>

int main(void)
{
    {
        bool ifInput = false;
        do
        {
            printf("Height: ");
            int height = GetInt();
            // asks user for height
            if (height > 23 || height < 0)
            {
                printf("Enter a non-negative integer height less than 24\n");  
            }
                // if height > 23 or negative, disqualifies.
            else
            {
                ifInput = true;
                int i;
                for ( i = 0 ; i < height; i++)
                    // for loop goes through every line
                {
                    int rowNumber = height - i;
                    // rowNumber - 1 is the number of spaces before the #'s
                    // current row is the 'rowNumber'th row
                    for ( int b = 0; b < rowNumber - 1; b++)
                        // b is only loop variable, why is style50 making a fuss
                    {
                        printf(" ");
                    }
                    // prints first spaces before the #'s
                    int hashtags = i + 1;
                    // number of #'s to print
                    for ( int a = 0; a < hashtags; a++)
                    {
                        printf("#");
                    }
                    // prints first #'s
                    printf("  ");
                    // prints the two spaces in between the #'s
                    for (int a = 0; a < hashtags; a++)
                        // a is just a loop variable, style50 stop making a fuss
                    {
                        printf("#");
                    }
                    // prints the second #'s
                    /* for (int b = 0; b < g-1; b++)
                    {
                        printf(" ");
                    }
                // prints the spaces after the #'s
                */
                    // nevermind there are no spaces after the second #'s
                    printf("\n");
                    // prints a line, next line ready
                }
            } 
        } while ( ifInput == false );
    }
    
    
    
    
        return 0;
}

