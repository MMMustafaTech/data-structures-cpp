# C++ Data Structures & Practice Projects

Course-based implementations from **Algorithms & Problem Solving — Level 5** in the Programming Advices roadmap.

## Implementations

| Component | Source |
| --- | --- |
| Doubly linked list | [clsDblLinkedList.h](include/clsDblLinkedList.h) |
| Queue based on a linked list | [clsMyQueue.h](include/clsMyQueue.h) |
| Stack based on a linked list | [clsMyStack.h](include/clsMyStack.h) |
| Dynamic array | [clsDynamicArray.h](include/clsDynamicArray.h) |
| Queue based on a dynamic array | [clsMyQueueArr.h](include/clsMyQueueArr.h) |
| Stack based on a dynamic array | [clsMyStackArr.h](include/clsMyStackArr.h) |
| String undo/redo | [clsMyString.h](include/clsMyString.h) |
| Service queue simulation | [clsQueueLine.h](include/clsQueueLine.h) |

## Try the example

Use a **Visual Studio Developer Command Prompt**, then run:

```bat
cl /std:c++20 /EHsc /I include examples\demo.cpp /Fe:demo.exe
demo.exe
```

The example demonstrates FIFO queue access, LIFO stack access, and issuing/serving queue tickets. Headers using `__declspec(property)` require Microsoft compiler extensions.

The example was compiled and run with MSVC 14.51 and C++20. It produced queue front `10`, stack top `20`, next ticket `A1`, and `1` waiting client after serving one ticket.

## Repository preparation

The saved headers are collected in `include/` so their relative includes resolve. Date/string helpers from the banking coursework support the queue-line example. `examples/demo.cpp` is an added usage demonstration.

These are learning implementations with manual memory management. Boundary handling and copying of owning containers remain areas for future improvement.

See [ATTRIBUTION.md](ATTRIBUTION.md) for the Programming Advices learning source.
