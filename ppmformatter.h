#ifndef PPMFORMATTER
#define PPMFORMATTER

#include <stdio.h>
#include <stdlib.h>

#include "raycast.h"

void write_p3(FILE* fp, Pixel* pixel, int width, int height);


#endif