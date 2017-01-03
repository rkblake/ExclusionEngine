#ExclusionEngine
Exclusion is the bestest game engine that will never be done.


## Dependencies 
- glm, math lib based on GLSL
- bullet, 3D collision detection and rigid body dynamics lib
- assimp, 3D model importing lib
- lua (prefer latest)


## Building
The build system is not complex.

### Arch Linux
To build using pacman:
<pre>
$ sudo pacman -S glm bullet assimp
$ make
</pre>


## Design Goals
* first, third, and free look camera
* lua scripting for game designers
* pathfinding AI
* particle system
* physics
* shaders
* decals
* different lighting types
