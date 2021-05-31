cmake_minimum_required(VERSION 3.18)

project(wish)

### Compiler and linker flags.
set (
	CMAKE_CXX_FLAGS 
	"-Wall -Wextra -Winit-self -Wold-style-cast -Woverloaded-virtual -Wuninitialized -Wmissing-declarations -ansi -pedantic"
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

### Export shell as a static library.
set(
	WISH_SRC
	src/wish.cpp
)
add_library(
	wishlib 
	STATIC 
	${WISH_SRC}
)
target_include_directories(
	wishlib
	PUBLIC
	"${CMAKE_SOURCE_DIR}/inc"
)

### Create executable to drive the shell.
set(
	MAIN_SRC
	src/main.cpp
)

add_executable(
	wish
	${MAIN_SRC}
)
target_link_libraries(
	wish
	PUBLIC
	wishlib
)

