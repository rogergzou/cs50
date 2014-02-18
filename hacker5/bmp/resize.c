/**
 * resize.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Resizes a BMP piece by piece, just because it's the homework.
 */
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

#define NUMOFDECIMALS 1
int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: ./copy f infile outfile\n");
        return 1;
    }

    // remember filenames
    char* fStr = argv[1];
    float f = atof(fStr);
    int a = f;
    char* infile = argv[2];
    char* outfile = argv[3];
    int ten = f * 10 * NUMOFDECIMALS;
    ten = a;
    if (!(ten >= 0 && ten < 100) || fStr == NULL)
    {
        printf("Please input a float number between 0.0 and 100.0 for f.");
        return 5;
    }
    
    // open input file 
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }
    int oldpadding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    // modify BITMAPINFOHEADER to be 10 * f big
    bi.biHeight *= ten;
    bi.biWidth *= ten;
    int padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int realheight = abs(bi.biHeight);
    bi.biSizeImage = (sizeof(RGBTRIPLE) * bi.biWidth + padding) * realheight;
    // change size
    int otherstuff = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
    bf.bfSize = bi.biSizeImage + otherstuff;    
    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // bi.biHeight *= 10 * NUMOFDECIMALS;
    // bi.biWidth *= 10 * NUMOFDECIMALS;    
    
    // determine padding for scanlines
    

    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight) / ten; i < biHeight; i++)
    {
        // reading part
        
        
        int biWidth = bi.biWidth / ten;
        // storage
        RGBTRIPLE triple[biWidth];
        
        // iterate over pixels in scanline
        for (int j = 0; j < biWidth; j++)
        {
            // temporary storage
            // RGBTRIPLE triple;

            // read RGB triple from infile
            fread(&triple[j], sizeof(RGBTRIPLE), 1, inptr);
            
            /*for (int k = 0; k < ten; k++)
            {
                // write RGB triple to outfile
                fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
            }*/
        }

        // skip over padding, if any
        fseek(inptr, oldpadding, SEEK_CUR);
        
        
        // writing part
        
        for (int h = 0; h < ten; h++)
        {
            
            for (int k = 0; k < biWidth; k++)
            {
                for (int l = 0; l < ten; l++)
                {
                    // write RGB triple to outfile
                    fwrite(&triple[k], sizeof(RGBTRIPLE), 1, outptr);
                }
            }
            // padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE) * ten) % 4) % 4;
            
            // then add it back (to demonstrate how)
            for (int k = 0; k < padding; k++)
            {
                fputc(0x00, outptr);
            }
        }
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}
