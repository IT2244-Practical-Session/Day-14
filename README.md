# Day-14

# Process Creation in C Using `fork()`

Welcome to this repository demonstrating **process creation** and management in C using the `fork()` system call on Unix/Linux systems.

---

## Overview

This repository contains sample C programs that illustrate:

- How to create **child processes** using `fork()`.
- Differentiating between parent and child processes.
- Using multiple `fork()` calls to create several processes.
- Understanding process IDs (PIDs) and their relationship.
- Basic process control flow with `fork()`.

---

## Why `fork()`?

- `fork()` is a fundamental system call in Unix-like OS that creates a new process by duplicating the current process.
- The new process is called the **child process**, while the original is the **parent**.
- Both processes run independently after the fork.
- Distinguishing between parent and child is done by checking the return value of `fork()`:
  - Returns **0** in the child process.
  - Returns **child's PID** in the parent process.

---

## Code Examples

### 1. Simple Fork Example

```c
#include <stdio.h>
#include <unistd.h>

int main() {
    printf("\nHello World");

    int f = fork();
    int p = getpid();

    printf("\nthe pid is %d", p);
    printf("\nthe f is: %d\n", f);

    return 0;
}
