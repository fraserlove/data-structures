# Strux

A lightweight C++ library implementing essential data structures with zero external dependencies. Each structure is built on top of simpler ones, forming an integrated, standalone collection that works across different C++ standards.


| Structure | Base Type | `push` | `pop` | `insert` | `remove` | `contains` | `get` | `set` | `find` | `clear` | `length` | `isEmpty` | `peek` | `reverse` |
|-----------|---------------------|--------------|-------------|--------|--------|----------|-----|-----|------|-------|--------|---------|------|---------|
| `List` | - | O(1) | O(n) | O(n) | O(n) | O(n) | O(n) | O(n) | O(n) | O(n) | O(1) | O(1) | O(1) | O(n) |
| `Vector` | `T[]` | O(1) | O(1) | O(n) | O(n) | O(n) | O(1) | O(1) | O(n) | O(1) | O(1) | O(1) | - | O(n) |
| `Stack` | `List` | O(1) | O(1) | - | - | O(n) | - | - | - | O(n) | O(1) | O(1) | O(1) | - |
| `Queue` | `List` | O(1) | O(1) | - | - | O(n) | - | - | - | O(n) | O(1) | O(1) | O(1) | - |
| `PQueue` | `Vector` | O(log n) | O(log n) | - | O(log n) | O(n) | - | - | - | O(1) | O(1) | O(1) | O(1) | - |


## Testing

Each data structure is tested using Google Test. To run all tests, use the following commands:

```sh
cmake -B build && cmake --build build
ctest --test-dir build
```