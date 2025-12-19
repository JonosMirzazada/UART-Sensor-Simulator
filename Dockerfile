# Base image
FROM ubuntu:22.04

# Install build tools
RUN apt-get update && \
    apt-get install -y build-essential make && \
    rm -rf /var/lib/apt/lists/*

# Set working directory
WORKDIR /app

# Copy project files
COPY . .

# Build the project
RUN make

# Default command
CMD ["./sensor_sim"]
