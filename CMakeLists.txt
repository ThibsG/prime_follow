cmake_minimum_required(VERSION 2.6)

project(PrimeDistribution)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Qt
# find_package(Qt5Core)

# Sources
file(GLOB CHEADERS *.hpp)
file(GLOB CSOURCES *.cpp)

# Flags
set(CMAKE_BUILD_TYPE "RELEASE")

## C++11 flag
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
## Optimizations
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -Wall -Werror")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -s")

# Executable
add_executable(prime_distribution ${CHEADERS} ${CSOURCES})
target_link_libraries(prime_distribution)
# target_link_libraries(prime_distribution Qt5::Core)