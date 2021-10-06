<div align="center">
  <h1 align="center">Arm path planner</h1>
  <h3 align="center">
    A manipulator path planner with IK solver for Acme Robotics
  </h3>
</div>
</hr>

[![Build Status](https://app.travis-ci.com/kavyadevd/AcmeRoboticsPathPlanner.svg?branch=main)](https://app.travis-ci.com/kavyadevd/AcmeRoboticsPathPlanner)
[![Coverage Status](https://coveralls.io/repos/github/kavyadevd/AcmeRoboticsPathPlanner/badge.svg?branch=main)](https://coveralls.io/github/kavyadevd/AcmeRoboticsPathPlanner?branch=main)

</hr>
This is a C++ project for motion planning of a robotic arm manipulator. The work was proposed and developed for Acme Robotics. The project was developed using standard software development practices.
</br>

## Installation

The project requires a C++ environment, coppeliasim application for execution.

```bash
git clone --recursive https://github.com/kavyadevd/AcmeRoboticsPathPlanner.git
cd AcmeRoboticsPathPlanner
mkdir -p build
cd build
cmake ..
make
```

Fet Eigen for matrix computations
```bash
git clone https://gitlab.com/libeigen/eigen.git
```

MoveIt

For complete MoveIt installation refer to official documentation [here](https://ros-planning.github.io/moveit_tutorials/doc/getting_started/getting_started.html).
On Ubuntu 18.04 and above MoveIt can be installed using following commands:
    
   ```bash
   mkdir -p ~/ws_moveit/src
   cd ~/ws_moveit/src

   wstool init .
   wstool merge -t . https://raw.githubusercontent.com/ros-planning/moveit/master/moveit.rosinstall
   wstool update -t .
  ```
 
 Coppeliasim
  [Download Coppeliasim](https://www.coppeliarobotics.com/files/CoppeliaSim_Player_V4_2_0_Ubuntu20_04.tar.xz) unpack the compressed file.
  Run the simulator script by running the following command on cmd:
  ```bash
  ./coppeliasim.sh
  ```


## Building for code coverage

```bash
sudo apt-get install lcov
cmake -D COVERAGE=ON -D CMAKE_BUILD_TYPE=Debug ../
make
make code_coverage
```


## Plugins


- CppCheckEclipse

    To install and run cppcheck in Eclipse

    1. In Eclipse, go to Window -> Preferences -> C/C++ -> cppcheclipse.
    Set cppcheck binary path to "/usr/bin/cppcheck".

    2. To run CPPCheck on a project, right-click on the project name in the Project Explorer 
    and choose cppcheck -> Run cppcheck.


- Google C++ Style

    To include and use Google C++ Style formatter in Eclipse

    1. In Eclipse, go to Window -> Preferences -> C/C++ -> Code Style -> Formatter. 
    Import [eclipse-cpp-google-style][reference-id-for-eclipse-cpp-google-style] and apply.

    2. To use Google C++ style formatter, right-click on the source code or folder in 
    Project Explorer and choose Source -> Format

[reference-id-for-eclipse-cpp-google-style]: https://raw.githubusercontent.com/google/styleguide/gh-pages/eclipse-cpp-google-style.xml

- Git

    It is possible to manage version control through Eclipse and the git plugin, but it typically requires creating another project. If you're interested in this, try it out yourself and contact me on Canvas.

- Doxygen

    The HTML page for project outlines can be generated using the following commands

    1.  doxygen -g
    2.  doxygen Doxyfile
