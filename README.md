# Matrix Calculator

This project is a simple matrix calculator library implemented in C++ with a CLI demonstration. It supports matrix creation, addition, multiplication, transposition, and computing the sum of all elements. The library is fully documented using Doxygen and is tested with Google Test. A Dockerfile and GitHub Actions workflow are provided for containerization and continuous integration.

## Building

Requirements: CMake and a C++17 compiler.

```bash
git clone https://github.com/gregkorneev/matrix-calculator-ver1.git
cd matrix-calculator-ver1
mkdir build && cd build
cmake ..
make
```

This will build the library and the CLI application.

## Running the CLI

After building, run the CLI application to see a demonstration of the matrix calculator:

```bash
./build/matrix_calculator_cli
```

## Running Tests

To run the unit tests using Google Test, execute:

```bash
cd build
ctest --output-on-failure
```

## Generating Documentation

To generate API documentation using Doxygen, install Doxygen and run:

```bash
doxygen Doxyfile
```

The documentation will be generated in the `docs` directory.

## Docker

A Dockerfile is included. To build and run the Docker container:

```bash
docker build -t matrix-calculator .
docker run matrix-calculator
```

## CI/CD

A GitHub Actions workflow is configured to build the project, run the tests, and generate documentation automatically on each push or pull request.
