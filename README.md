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

## LICENSE

Copyright [2024] [username: Buh9]

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
