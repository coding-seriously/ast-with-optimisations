CFG Visualiser

This repository contains a small Clang-based command-line tool that parses C/C++ source files and performs static optimisation of the give C/C++ code. it emits a Graphviz DOT representation of each function's control-flow graph.

The main executable is built from ast.cpp, and CMake defines the target name as ast-tool.
What It Does

The tool:

    uses Clang's AST and CFG APIs
    visits each function definition in the main input file
    builds a control-flow graph for the function body
    prints a digraph CFG { ... } description to standard output

The output can be redirected into a .dot file and rendered with Graphviz.
Repository Layout

    CMakeLists.txt: CMake configuration for the ast-tool executable
    ast.cpp: main Clang tool implementation
    test.cpp: standalone scratch/example source file, not currently part of the CMake target
    build/: local build directory and generated artifacts

Requirements

You need a C++17 compiler and a Clang/LLVM development environment with CMake support.

On Linux, the tool typically requires:

    CMake 3.10 or newer
    LLVM and Clang development packages
    a working compiler such as g++ or clang++
    Graphviz if you want to render the generated DOT output

Build

From the repository root:

cmake -S . -B build
cmake --build build

This produces the ast-tool executable inside build/.
Run

Pass one or more source files through the Clang tool. A typical workflow is:

cd build
./ast-tool ../test.cpp > program_cfg.dot
dot -Tpng program_cfg.dot -o graph.png

The repository already includes those example outputs in build/:

    program_cfg.dot
    graph.png

Output Format

The generated DOT output groups each function into a separate subgraph and labels basic blocks with the statements they contain. The result is intended for Graphviz visualization.
Notes

`

    The current CMake target only builds ast.cpp.
    The test.cpp file looks like an unrelated scratch program and is not compiled by default.
    The repository already contains a local build/ directory; it is safe to regenerate it with CMake if needed.
