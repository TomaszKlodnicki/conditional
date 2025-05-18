```
  ____                _ _ _   _                   _ 
 / ___|___  _ __   __| (_) |_(_) ___  _ __   __ _| |
| |   / _ \| '_ \ / _` | | __| |/ _ \| '_ \ / _` | |
| |__| (_) | | | | (_| | | |_| | (_) | | | | (_| | |
 \____\___/|_| |_|\__,_|_|\__|_|\___/|_| |_|\__,_|_|
```

# About
Compile time conditional variable based on std::conditional_t. When working with std::conditional_t, assigning a value to the resulting variable can sometimes lead to issues. Here is example bellow;

```c++
constexpr bool kStore = true;

auto example = std::conditional_t<kStore, int, std::monostate>

example = 5; // compilation time error if !kStore

if constexpr (kStore){  //
    example = 5;        // Also compilation time error
}                       //
```

This wrapper is simple solution to such problem

```c++
#include "conditional.hpp"
constexpr bool kStore = true;

auto example = Conditional<int,kStore>;

example = 5; // if !kStore empty inline operator= overload will be called

int b = example.value(); // if !kStore example.value will return int {}

```

# Build
Use Cmake to build this example
``` bash
mkdir build
cd build
cmake ..
make all
```