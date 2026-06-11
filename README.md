# shell-clone

A Unix shell implementation written in C. Built from scratch to explore how shells actually work under the hood — process management, signal handling, command parsing, and history tracking.

## Features

- **Command execution** — runs any program on your `PATH`, in both foreground and background (`&`)
- **Built-in commands** — `cd`, `pwd`, `exit`, `help`, `history`
- **Command history** — tracks the last 10 commands; replay them with `!!` or `!n`
- **Signal handling** — gracefully handles `CTRL-C` (`SIGINT`) without terminating the shell
- **Zombie process cleanup** — background processes are properly reaped
- **Smart `cd`** — supports `~` (home), `-` (previous directory), and no-arg (home)

## Project Structure

```
shell-clone/
├── CMakeLists.txt
├── include/
│   ├── cmd_exe.h          # Command execution interface
│   ├── hlpfuncs.h         # Helper/utility functions
│   ├── internal_commands.h # Built-in command handlers
│   └── msgs.h             # Output formatting macros
├── src/
│   └── shell.c            # Main shell implementation
└── gtest/                 # Google Test suite
```

## Build & Run

Requires `clang` and `cmake`.

```bash
# Configure
cmake -S . -B build

# Build
cmake --build build

# Run
./build/shell
```

## Usage

```bash
/home/user$ ls -la
/home/user$ sleep 5 &          # background execution
/home/user$ cd ~/projects
/home/user$ history            # show last 10 commands
/home/user$ !!                 # re-run last command
/home/user$ !3                 # re-run command #3
/home/user$ help               # list built-in commands
/home/user$ exit
```

## Implementation Details

- Uses `fork()` + `execvp()` for external command execution
- Uses `waitpid()` with `WNOHANG` to clean up zombie background processes
- Uses `read()` / `write()` for I/O to stay signal-safe
- SIGINT handler re-displays the prompt and prints help info
- History is stored as a fixed-size circular buffer (capacity: 10)

## Tech Stack

- **Language**: C
- **Build system**: CMake
- **Testing**: Google Test (gtest)
- **Compiler**: clang
