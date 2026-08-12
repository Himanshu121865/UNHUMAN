# Contributing to UNHUMAN Engine

Thank you for your interest in contributing! To keep the codebase clean, performant, and easy to maintain, please follow these core guidelines.

## Code Style & Standards

1. **Modern C++**: We strictly target **C++23**. Please utilize modern C++23 features where appropriate to write clean and efficient code.
2. **Formatting**: Always run `clang-format` on your changes before pushing. This ensures a consistent style across the entire engine.
3. **Static Analysis**: We use `clang-tidy` for linting. However, apply **common sense**—do not blindly follow linting rules if they degrade performance, create bloated workarounds, or make the code less readable.

## Headers and Includes

1. **Precompiled Headers**: Always include the precompiled header `uhepch.h` at the very top of your `.cpp` files.
2. **Minimize Header Bloat**: Do **not** include unnecessary headers in `.h` files. Use **forward declarations** (`class MyClass;`) whenever possible. This keeps compilation times fast and prevents massive dependency chains.

## Workflow

- Keep Pull Requests focused on a single feature or bug fix.
- Make sure your code builds successfully (both Windows and Linux if possible) before submitting a PR.


