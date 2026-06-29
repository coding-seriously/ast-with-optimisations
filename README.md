# CFG Visualiser

A **Clang-based Control Flow Graph (CFG) Visualiser** for C/C++ programs. This tool parses C/C++ source code, performs static analysis, constructs an **Abstract Syntax Tree (AST)** and **Control Flow Graph (CFG)** for each function, and generates a **Graphviz DOT** representation for visualization.

The project is built using **Clang's LibTooling**, **AST**, and **CFG APIs**, making it a useful utility for understanding program control flow, compiler internals, and static code analysis.

---

## Features

* Parses C and C++ source files using Clang.
* Traverses the Abstract Syntax Tree (AST).
* Builds a Control Flow Graph (CFG) for every function definition.
* Exports CFGs in **Graphviz DOT** format.
* Generates easy-to-read graphical representations of program execution paths.
* Supports visualization of multiple functions within a source file.

---

## Repository Structure

```
.
├── CMakeLists.txt      # Build configuration
├── ast.cpp             # Main Clang tool implementation
├── test.cpp            # Example input source file
├── build/              # Generated build files and output (not tracked)
└── README.md
```

---

## Requirements

To build the project, you will need:

* C++17 compatible compiler (`g++` or `clang++`)
* CMake 3.10 or later
* LLVM and Clang development libraries
* Graphviz (for rendering DOT files)

---

## Building the Project

Clone the repository and build the project using CMake:

```bash
cmake -S . -B build
cmake --build build
```

This generates the executable:

```
build/ast-tool
```

---

## Usage

Run the tool on a C/C++ source file and redirect the output to a DOT file:

```bash
cd build
./ast-tool ../test.cpp > program_cfg.dot
```

Generate a visual graph using Graphviz:

```bash
dot -Tpng program_cfg.dot -o graph.png
```

You can then open `graph.png` to view the generated Control Flow Graph.

---

## Output

The generated DOT file contains a separate subgraph for each function in the input source. Each node represents a **basic block** and is labeled with the statements contained within that block. The output is fully compatible with Graphviz for rendering.

Example workflow:

```
C/C++ Source
      │
      ▼
 Clang Parser
      │
      ▼
 AST Construction
      │
      ▼
 CFG Generation
      │
      ▼
 Graphviz DOT File
      │
      ▼
   PNG/SVG/PDF Graph
```

---

## Project Overview

The tool performs the following steps:

1. Parses the input source file using Clang.
2. Visits every function definition in the main source file.
3. Constructs a Control Flow Graph for each function.
4. Traverses CFG basic blocks.
5. Emits a Graphviz DOT representation to standard output.

---

## Notes

* Only `ast.cpp` is compiled into the executable.
* `test.cpp` is provided as an example input and is not part of the build target.
* The `build/` directory is generated automatically and can be safely recreated at any time.

---

## Technologies Used

* C++
* Clang LibTooling
* LLVM
* CMake
* Graphviz

---

## About

**CFG Visualiser** is a static analysis tool that leverages **Clang's compiler infrastructure** to construct Abstract Syntax Trees (ASTs) and visualize Control Flow Graphs (CFGs) for C/C++ programs. It is intended as an educational and research-oriented project for understanding compiler design, program analysis, and control flow visualization.
