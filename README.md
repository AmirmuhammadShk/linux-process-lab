# Linux Process Lab (Systems Programming in C)

This repository explores how Linux manages processes, threads, signals, and system calls — from doing things correctly, to observing behavior with tracing tools, to understanding how the OS actually runs your programs.

Tested on Linux with gcc and strace.

Check:

gcc --version  
strace --version  
gdb --version

---


# Process + Thread Demo

## What it shows

- Difference between processes and threads  
- fork() creates a new process with a new address space  
- Threads share memory inside a process  
- Parent and child run concurrently  
- How Linux schedules processes and threads  

## Build & run

cd process_thread_demo  
make  
./process_thread_demo  

## What happens

- Parent process starts  
- fork() creates a child process  
- Both parent and child create multiple threads  
- Each thread prints process PID, thread ID, and role  

You’ll see:  
- Parent and child have different PIDs  
- Threads inside each process share the same PID  
- Thread IDs differ  

This demonstrates the Linux process model and thread behavior.

---

# Graceful Signal Shutdown

## What it shows

- Safe signal handling with sigaction  
- Handling SIGINT and SIGTERM  
- Async-signal-safe design  
- Graceful program shutdown  
- How to avoid crashes in signal handlers  

## Build & run

cd graceful_signal_shutdown  
make  
./graceful_signal_shutdown  

Stop the program with Ctrl+C or:

kill -TERM <pid>

## What happens

- Program runs in a loop  
- Signal handler sets a safe flag  
- Main loop exits cleanly  
- Cleanup happens before exit  

This demonstrates proper Linux signal handling patterns used in real servers and daemons.

---

# Syscall Trace Demo

## What it shows

- How user programs interact with the Linux kernel  
- Basic syscalls: open, read, write, close  
- Observing syscalls with strace  
- Understanding syscall behavior  

## Build & run

cd syscall_trace_demo  
make  
./syscall_trace_demo  

## Trace with strace

Trace all syscalls:  
strace ./syscall_trace_demo  

Trace file operations only:  
strace -e trace=openat,read,write,close ./syscall_trace_demo  

Follow forks/threads:  
strace -f ./process_thread_demo  

Add timestamps:  
strace -tt -T ./syscall_trace_demo  

Save output to file:  
strace -o log.txt ./syscall_trace_demo  

## What happens

- Program opens a file  
- Reads bytes  
- Writes to stdout  
- Closes file  
- strace shows every syscall made to the kernel  

This demonstrates how programs interact with the Linux kernel.

---

# Why this repo exists

- Understand Linux process model  
- Practice fork and threading  
- Learn safe signal handling  
- Observe syscalls using strace  
- Debug low-level runtime behavior  
- Build strong systems programming fundamentals  

This repository is about learning how Linux actually runs programs under the hood.
