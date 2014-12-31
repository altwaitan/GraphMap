# Author: Abdullah Altawaitan
# Date: 8 December 2014

# CMake projects are forward compatible, but may not be backwards compatible. This
# commands defines the version of CMake used for the current setup.

cmake_minimum_required(VERSION 2.6)

# Define the project name. 

project (weighs_project)

# Add a subdirectory to the project. The CMakeLists.txt file in that subdirectory
# will be used for further setting up the project.

add_subdirectory( src )
