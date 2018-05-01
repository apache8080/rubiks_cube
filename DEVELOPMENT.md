# Development Status

So the goal of this project was to make a visualization of a Rubik's Cube that a user can play around with. 

### First 2 Weeks

I spent most of this time experimenting with the 3D modules in openFrameworks, and after many issues with certain customizations I needed and also build issues I decided to build this entire project  in OpenGL. After that decision, I spent the second week learning the basics of OpenGL and learning how to rotate and translate objects.

### Week 3 Status

Once I learned the basics of OpenGL I was able to build a working demo of a playable Rubik's Cube. One issue with this current working demo is the entire thing was written in a main file and I haven't quite figured out how to use OpenGL in an object oriented manner since it is a C API. I think the approach I am going to take is abstract out a lot of the state tracking and calculations done for translation and rotation to classes and then have the main file have all of the OpenGL code.