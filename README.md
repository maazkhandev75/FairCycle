# FairCycle 🔄
A C++-implemented scheduling simulator for fair process execution using a queue-based approach 📈.

## Overview 🌟
**FairCycle** is designed to evenly distribute instruction execution among multiple processes, ensuring efficient task management and resource allocation 💻.

## Features 🎯
- **Queue-Based Scheduling**: Utilizes a queue data structure to manage processes efficiently.
- **Round Robin Approach**: Implements a round robin-like scheduling algorithm for fairness.
- **Dynamic Process Handling**: Supports adding and removing processes dynamically.

## How It Works 🔍
1. **Process Creation**: Create `Process` objects with unique IDs and instruction counts.
2. **Scheduling Simulation**: Use the `Scheduler` class to simulate process execution, ensuring each process gets an equal share of CPU time ⏰.
3. **Output Analysis**: Observe the output to see how instructions are executed across different processes.

## Getting Started 🚀

### Installation

1. Clone this repository:
```bash
git clone https://github.com/maazkhandev75/FairCycle.git
```

2. Build the project using your preferred C++ compiler (e.g., GCC).

### Usage

1. Run the program with an input file specifying process details (e.g., `processesInfo.txt`).
2. The program will display how instructions are executed across each process.

---

Feel free to modify it as needed! 😊 
