#include "ppmformatter.h"

int maxColor = 255;

// write to file in p3 format
void write_p3(FILE* fp, Pixel* pixMap, int width, int height)
{
    // write in the header
    fprintf(fp, "P3\n%d %d\n%d\n", width, height,maxColor);
	// set current to the head of the linked list
    // current will then be used to loop through the entire list until the end, where the last node's next is NULL
    // for all the nodes in between the pixel will be written into the file.
    for(int i =0; i < width*height; i++) 
    {
        fprintf(fp, "%d %d %d\n", (int) pixMap[i].R*maxColor, (int) pixMap[i].G*maxColor, (int) pixMap[i].B*maxColor);
    }
}