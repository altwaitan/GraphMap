# Author: Abdullah Altawaitan
# Date: 8 December 2014

# The following file GLOB command will search for all files within the current directory
# that match the specified expressions (*.cpp and *.h), and assign the resulting files
# to the variable SRCS. Thus, SRCS is a list a all C source and header files in the 
# current directory.

file( GLOB SRCS *.cpp *.h )

# Define the target application executable and the list of CPP source
# and header files needed for the executable.

add_executable( weighs ${SRCS} )
