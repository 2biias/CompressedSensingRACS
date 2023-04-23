
# This project is a C++ project which uses Google's or-tools for solving an optimisation problem.
# For the following guide a Linux or Mac system is required, although should be possible on Windows
# if certain measures are taken.

# To build and execute thee project, some prerequisits needs to be fulfilled:

* Standard build tools for C++ development, e.g. in Ubnuntu the apt-package "build-essential" which installs:
    - make
    - GCC
    - G++
    - C compiler

* Using a packet manager, e.g. apt (linux) or homebrew (mac), get the packets
    - cmake
    - wget
    - pkg-config.

# To build the project from the project root directory execute:

cmake -S . -B build -DBUILD_DEPS=ON
# cmake -S . -B build -DCMAKE_BUILD_TYPE=Release -DBUILD_re2=ON -DBUILD_Eigen3=ON -DBUILD_CoinUtils=ON -DBUILD_Osi=ON -DBUILD_Clp=ON -DBUILD_Cgl=ON -DBUILD_Cbc=ON -DBUILD_SCIP=OFF
cmake --build build -j -v

# The build will take a while. After fininishing run the program by

./CSapp <path_to_executable>

# Here <path_to_executable> is the path from which you run the program.

# To uninstall 