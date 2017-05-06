project(PrimeDistribution)

cmake_minimum_required(VERSION 2.6)

# Flags
set(CMAKE_BUILD_TYPE "RELEASE")

## C++14 flag
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -pthread")
## Optimizations
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -Wall -Werror")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -s")

# Sources
file(GLOB CHEADERS *.hpp)
file(GLOB CSOURCES Primes.cpp Repartition.cpp)

# Executable
add_executable(prime_distribution main.cpp ${CHEADERS} ${CSOURCES})
target_link_libraries(prime_distribution)

# Tests
enable_testing()

## Executable
add_executable(prime_tester prime_tester.cpp ${CHEADERS} ${CSOURCES})

## Add tests
add_test(PrimeTest_100   prime_tester -n 100)
add_test(PrimeTest_1000  prime_tester -n 1000)
add_test(PrimeTest_10003 prime_tester -n 10003)
add_test(PrimeTest_50001 prime_tester -n 50001)
add_test(PrimeTest_73895 prime_tester -n 73895)