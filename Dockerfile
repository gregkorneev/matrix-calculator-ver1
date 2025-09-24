# Use an official Ubuntu base image
FROM ubuntu:22.04

# Install dependencies
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    doxygen \
    git \
    libgtest-dev \
    && rm -rf /var/lib/apt/lists/*

# Build Google Test
RUN cd /usr/src/gtest && cmake . && make && cp lib/*.a /usr/lib

# Set working directory
WORKDIR /app

# Copy source
COPY . /app

# Build project
RUN mkdir build && cd build && \
    cmake .. && \
    make && \
    ctest --output-on-failure && \
    doxygen ../Doxyfile

# Set the entrypoint to run the CLI
CMD ["./build/matrix_calculator_cli"]
