# Contributing to UNHUMAN Engine

Thank you for your interest in contributing! To keep the codebase clean, performant, and easy to maintain, please follow these core guidelines.

## Code Style & Standards

1. **Modern C++**: We strictly target **C++23**. Please utilize modern C++23 features where appropriate to write clean and efficient code.
2. **Formatting**: Always run `clang-format` on your changes before pushing. This ensures a consistent style across the entire engine.
3. **Static Analysis**: We use `clang-tidy` for linting. However, apply **common sense**—do not blindly follow linting rules if they degrade performance, create bloated workarounds, or make the code less readable.

## Headers and Includes

1. **Precompiled Headers**: Always include the precompiled header `uhepch.h` at the very top of your `.cpp` files.
2. **Minimize Header Bloat**: Do **not** include unnecessary headers in `.h` files. Use **forward declarations** (`class MyClass;`) whenever possible. This keeps compilation times fast and prevents massive dependency chains.

## Workflow & Stability

1. **Focused Pull Requests**: Keep Pull Requests focused on a single feature or bug fix. Do not mix unrelated changes.
2. **Never Break the Build**: Always ensure your code compiles locally (both Windows and Linux if possible) before submitting a PR. If CI/CD fails, fix it immediately.
3. **No Untested Code**: If you add a complex system (like a new physics solver or memory allocator), include a sandbox test layer to prove it works and doesn't leak memory.

## Commit Messages

To keep the git history readable and easy to search, please prefix your commit messages with the subsystem you modified. 

Examples:
- `Vulkan: implement bindless descriptor manager`
- `Renderer: add dynamic rendering pass`
- `AssetSystem: fix memory leak when loading GLTF`
- `Core: update application layer loop`
- `Doc: add contribution guidelines`
