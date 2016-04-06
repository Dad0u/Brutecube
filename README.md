# Brutecube

This project is not fonctionnal yet. It implements a class representing a X by Y by Z Rubik's cube.

The final goal would be to implement bruteforce solving to discover interesting algorithms to make my own resolution method, depending on the size and shape of the cube.

Once the representation is implemented, it will be possible to manually edit and move the cube, also adding a 'neutral' color which is ignored when testing if the cube is solved. It is meant to represent the parts I am not interested in placing at this stage of the resolution.

This is actually a rewrite of a C program I made in 2009 (it was functionnal but I was just learning C so the code is terrible and not optimal AT ALL).

Also, depending on my motivation, I could implement a CUDA bruteforce solver which would be much faster than a CPU solver.
