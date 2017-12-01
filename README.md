Project 3 - Illumination
------------------------
Code to raycast mathematical primitives based on a scene input file into a pixel buffer where the pixels are colored based on a shading model and recursive raytracing to provide reflection.
Then pixel buffer is written to a PPM3 formatted file.

Usage
------------------------
To use this program, the JSON input file must be written with the camera object first, then any sphere, plane, or light objects thereafter. 
Then, go to the directory in command line and then call make.
Then execute the raytrace exectuable with arguments (int in pixels) height, (int in pixels) width, (string) input_file_name, (string) output_file_name.

Known Issues
------------------------
1) This is probably still a problem -- even though I haven't tested for it: does not show multiple spheres at the same time if they are on the same z coordinate. They override each other for some reason.
2) Accepts when files have something like ",]["; I might need to change the code to stop using strtok()
3) Segmentation fault when run. There is some problem within the Illumination function causing this. So the specular and diffuse color for the shading model does not work.


Date and Author
-----------------------
11/30/17
Leia Trice - lat222@nau.edu