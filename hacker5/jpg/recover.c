/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Recovers JPEGs from a forensic image.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
int main(int argc, char* argv[])
{
    
    
    
    FILE* file = fopen("card.raw", "r");
    // FILE* file = fopen("test.txt", "r");
    if (file == NULL)
    {
        fclose(file);
        fprintf(stderr, "Could not get card.raw.\n");
        return 1;
    }
    // while ( end of file
    // for (int e = 0; e < 50; e++)
    // {
    unsigned char addr[512];
    int count = 0;
    int dor = 0;
            
    fread(&addr, sizeof(char), 512, file);
    do
    {
        int y = 0;
        int fuuuu = 0;
        if (addr[3] == 0xe0 || addr[3] == 0xe1)
        {
            y = 1;
        }
        if (addr[0] == 0xff && addr[1] == 0xd8 && addr[2] == 0xff && y)
        {
            char name[10];
            sprintf(name, "0%.2i.jpg", dor);
            FILE* outp = fopen(name, "w");
            if (outp == NULL)
            {
                fclose(file);
                fprintf(stderr, "Could not create an outfile\n");
                return 2;
            }
            
            // printf("found%d\n", dor);
            dor++;
            
            do
            {
                fuuuu = 0;
                fwrite(&addr, sizeof(char), 512, outp);
                fread(&addr, sizeof(char), 512, file);
                
                // printf("writing%i ", count);
                count++;
                if (feof(file))
                {
                    fclose(file);
                    return 0;
                    break;
                }
                if (addr[0] == 0xff && addr[1] == 0xd8 && addr[2] == 0xff)
                {
                    fuuuu = 1;
                }
            } while (!(fuuuu && y));
            fclose(outp);
        }
        else if (feof(file)) 
        // reach end of file
        {
            fclose(file);
            return 0;
            break;
        }
        else
        {
            fread(&addr, sizeof(char), 512, file);
        }
        count++;
        // printf("reading%i ", count);
            // } while (!strncmp(addr, "xxxxxxxxxxxxxxxxx", sizeof(uint8_t)));
            } while(1);
    /*do
    {
        char name[10];
        int dor = 0 + e;
        sprintf(name, "0%.2i.jpg", dor);
        FILE* outp = fopen(name, "w");
        if (outp == NULL)
        {
            fclose(file);
            fprintf(stderr, "Could not create an outfile\n");
            return 2;
        }
        
        fread(&addr, sizeof(char), 512, file);
        {
            
            printf("alsofound\n");
            fwrite(&addr, sizeof(char), 512, file);
        
            break;
        }
        printf("writing");
    } while (e < 50); */
        // fclose(outp);
            // free(addr);
            // free(name);
        // }
    // }
    // fclose(file);
    // return 0;
}
