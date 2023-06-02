cmake_minimum_required(VERSION 3.10)

project(CNF VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# For better debug info in debug builds.
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -D_GLIBCXX_DEBUG")

# Put all binary files into a "bin" directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Add an executable for the main program
add_executable(CNF 
    tests/simpleMain.cpp
    src/renderer.cpp
    src/dx12_renderer.cpp
    # src/triangle.cpp
)

target_include_directories(CNF PRIVATE 
    include/CNF
)

# Link against the DirectX 12 libraries
target_link_libraries(CNF d3d12 dxgi)

# Add an executable for the tests
# add_executable(CNFTests 
#     tests/renderer_tests.cpp)

# target_include_directories(CNFTests 
#     PRIVATE 
#         ${PROJECT_SOURCE_DIR}/include 
#         ${PROJECT_SOURCE_DIR}/tests)

# target_link_libraries(CNFTests PRIVATE CNF)