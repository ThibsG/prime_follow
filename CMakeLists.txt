project(PrimeDistribution)

cmake_minimum_required(VERSION 2.6)

# Flags
set(CMAKE_BUILD_TYPE "RELEASE")

## C++14 flag
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
## Optimizations
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -Wall -Werror")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -s")

# Sources
file(GLOB CHEADERS *.hpp)
file(GLOB CSOURCES *.cpp)

# Executable
add_executable(prime_distribution ${CHEADERS} ${CSOURCES})
target_link_libraries(prime_distribution)