cmake_minimum_required(VERSION 3.10)
project(ASTGenerator)

# 1. Find the LLVM and Clang packages
find_package(LLVM REQUIRED CONFIG)
find_package(Clang REQUIRED CONFIG)

# 2. Add LLVM definitions and include paths
include_directories(${LLVM_INCLUDE_DIRS} ${CLANG_INCLUDE_DIRS})
link_directories(${LLVM_LIBRARY_DIRS})
add_definitions(${LLVM_DEFINITIONS})

# 3. Create the executable
add_executable(ast-tool ast.cpp)

# 4. The "Magic" Link: This handles all dependencies and order
# Replace section 4 in your CMakeLists.txt with this:
target_link_libraries(ast-tool PRIVATE
  clang-cpp
  LLVM
)

# 5. Ensure we use the correct C++ standard
set_target_properties(ast-tool PROPERTIES
  CXX_STANDARD 17
  CXX_STANDARD_REQUIRED ON
)