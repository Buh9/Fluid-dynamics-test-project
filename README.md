# Fluid Dynamics
**VERSION 0.1.0**
This is a fluid dynamics program using SPH(Smoothed Particle Hydrodynamics) created using glut/opengl 3d, it is very broken and very basic at it's current state but objects move in this version though I will probably need to tighten up the physics this version though only shows us the objects moving at a certain velocity. 

## How to run it
I am too lazy to run this on other operating systems(plus Apple has Depricated OpenGL for newer vesions of MacOS), you will need some version of linux(possibly you can use WSL?) and have installed all the prerequsites. 

**First:** clone the repository

```bash
git clone https://github.com/Buh9/Fluid-dynamic-stupid-thing.git
```

**Next:** Build the software (you may need superuser previlages & also the file location may need permissions)

```bash
make install
```

**PREREQUISITES**

![gcc/g++](git://gcc.gnu.org/git/gcc.git)

![freeglut](https://github.com/freeglut/freeglut.git)

![OpenGL](https://github.com/KhronosGroup/OpenGL-Registry.git)

**Resources**

Matthias Müller, David Charypar and Markus Gross,*Particle-Based Fluid Simulation for Interactive Applications*,Department of Computer Science, Federal Institute of Technology Zürich (ETHZ), Switzerland, 2003 ![link](https://matthias-research.github.io/pages/publications/sca03.pdf)

Projects that helped me:

![Bouncing balls simulation](https://github.com/AndreeaDraghici/Bouncing-Balls-3D)

![SPH Fluid Simulator](https://github.com/lijenicol/SPH-Fluid-Simulator)

video that inspired me:

![Coding Adventure: Simulating Fluids](https://www.youtube.com/watch?v=rSKMYc1CQHE&t=1687s)

