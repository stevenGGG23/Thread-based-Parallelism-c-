# Lab 11 – Thread-based Parallelism

A C program that uses **POSIX threads (pthreads)** to calculate the average, minimum, and maximum of a list of numbers passed via the command line. Each stat is computed concurrently in its own thread.

## How It Works

The program spawns three threads at the same time:
- **Thread 1** – calculates the average
- **Thread 2** – finds the minimum value
- **Thread 3** – finds the maximum value

The main thread waits for all three to finish using `pthread_join`, then prints the results.

## Build

```bash
gcc -o lab11Problem1 lab11Problem1.c -lpthread
```

> The `-lpthread` flag is required to link the POSIX threads library.

## Usage

```bash
./lab11Problem1 num1 num2 num3 ...
```

### Example

```bash
./lab11Problem1 10 30 20 12 64 33 9 21 23 15
```

**Output:**
```
The average value is 23.70
The minimum value is 9
The maximum value is 64
```

## Files

| File | Description |
|------|-------------|
| `lab11Problem1.c` | Main source file |
| `README.md` | This file |

## Notes

- Input numbers are passed as command-line arguments
- Global arrays are used so all threads can access the data without needing argument passing
- Each thread writes to a separate result variable, so there are no race conditions
- Tested on Linux with GCC
