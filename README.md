# It's Terminal
[![build](https://github.com/claudemuller/its-terminal/actions/workflows/c.yml/badge.svg)](https://github.com/claudemuller/its-terminal/actions/workflows/c.yml)

A basic terminal emulator written in C with VTE and GTK+

# Requirements

- [gcc](https://gcc.gnu.org/)
- or [clang](https://clang.llvm.org/)
- [make](https://www.gnu.org/software/make/)
- [VTE](https://wiki.gnome.org/Apps/Terminal/VTE)
- [GTK+4](https://www.gtk.org/)

# Build

```bash
make build
```

# Run

```bash
make run
```

# Build a Debug Binary

```bash
make debug-build
```

# Start `lldb` or `gdb` With Debug Binary

```bash
make debug
```
