# The places to look for the phro folders
set(FIND_PHRO_PATHS
    ~/Libary/Frameworks/phro              # On Mac, this is where my phro folder is
    C:/Users/Phili/Bibliotek/phro         # On Windows, this is where my phro folder is
)

# The location of the include folder (and thus the header files)
# find_path uses the paths we defined above as places to look
# Saves the location of the header files in a variable called phro_INCLUDE_DIR
find_path(PHRO_INCLUDE_DIR phro.h   # The variable to store the path in and the name of the header files
    PATH_SUFFIXES include               # The folder name containing the header files
    PATHS ${FIND_PHRO_PATHS})       # Where to look (defined above)

# The location of the lib folder (and thus the .a file)
# find_library uses the paths we defined above as places to look
# Saves the location of the .a file in a variable called phro_LIBRARY
find_library(PHRO_LIBRARY               # The variable to store where it found the .a files
    NAMES phro                      # The name of the .a file (without the extension and without the 'lib')
    PATH_SUFFIXES lib                   # The folder the .a file is in
    PATHS ${FIND_PHRO_PATHS})