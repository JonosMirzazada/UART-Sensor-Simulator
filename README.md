# UART-Sensor-Simulator

UART Sensor Simulator written in C that generates sensor data, simulates UART communication, and logs activity for testing and debugging


---

## Purpose

The purpose of this project is to simulate sensor data and UART communication in C, providing a simple platform for learning, testing, and experimenting with embedded systems concepts such as data generation, communication, parsing, and logging.

---


## Features

- Simulates temperature and humidity sensors
- UART-like communication (send & receive)
- Parses received sensor data
- Logging system (info and error messages)
- Randomized sensor readings for more realistic testing

---

## Getting Started

### Prerequisites

- GCC (C compiler)
- Make
- VS Code or any text editor (optional)
- WSL on Windows or Linux/macOS terminal

---


### Build and Run

1. Clone the repo:

git clone https://github.com/JonosMirzazada/UART-Sensor-Simulator.git
cd UART-Sensor-Simulator

---


### Run with Docker

```bash
# Build the image
docker build -t uart-sensor-sim .

# Run the simulator
docker run --rm uart-sensor-sim
```

### Example Output

```bash
UART Sensor Simulator starting...
[SENSOR] Init
[UART] Init
[SENSOR] Sensor data generated
[UART] Data sent
[UART] Data received
[PARSER] Temp = 25 C
[PARSER] Humidity = 40 %
Simulator finished!

