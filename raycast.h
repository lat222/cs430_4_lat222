#ifndef RAYCAST
#define RAYCAST

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define maxObjects 128

#define backgroundColorR 0
#define backgroundColorG 0
#define backgroundColorB 0

#define cameraX 0
#define cameraY 0
#define cameraZ 0

#define shininess 20

typedef double* V3;

typedef struct Pixel {

	// The is where the colors for a pixel are stored
    unsigned char R, G, B;

} Pixel;

// class to hold object information
typedef struct Object
{
	char type;
	V3 pix;
	V3 position;
	V3 normal;
	int radius;
	V3 diffuse_color;
	V3 specular_color;
	double radialA0;
	double radialA1;
	double radialA2;
	double theta;
	double angularA0;
	V3 direction;
} Object;

// Global variables
Object* objects[maxObjects];
int objectCount;

Object* lights[maxObjects];
int lightCount;

Pixel* pixMap;

V3 r0;
float worldWidth,worldHeight; // these will be the camera width and height

// calls all the following functions and returns a list of pixels
Pixel* raycast(FILE* fp, int width, int height);

// returns the int index of the nearest hit object from objects
int shoot(V3 rayVector);

// sets a pixel's color
void illuminate(int hitObjectIndex, V3 r0, V3 ur, int pixMapIndex);

double frad(double lightDistance, double a0, double a1, double a2);
double fang(double angularA0, double theta, V3 v0, V3 vl);

// returns the distance t if the ray vector intersected with the object
double ray_sphere_intersection(V3 rayVector, Object* object);
double ray_plane_intersection(V3 rayVector, Object* object);

int check_file_path(char* fp);

V3 v3_subtract(V3 a, V3 b);
V3 v3_add(V3 a, V3 b);
V3 v3_scale(V3 a, double b);
double v3_dot(V3 a, V3 b);
double v3_distance(V3 a, V3 b);
V3 v3_assign(double a, double b, double c);
V3 v3_unit(double a, double b, double c);
double to_degrees(double radians);

double clamp(double value);

void read_file(FILE* fp);
int count_char_in_string(char* inString, char charToCount);

#endif