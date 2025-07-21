# Conway's Game Of Life C++ & OpenGL

Implementation of Conway's Game of Life in C++ using OpenGL and GLUT libraries.

## Dependencies

```
$ sudo apt install libopengl-dev libglut-dev
```

To build the project, from the root folder:

```
$ mkdir build; cd build;

$ cmake ../

$ cmake --build .

$ ./Conway
```

The program asks the user to input a population number and a timestep refresh (in milliseconds)

