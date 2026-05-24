# Introduction to Linked Lists

## Core Concepts & Array Comparison

*   **Dynamic linear structure:** A Linked List is a linear data structure that grows and shrinks dynamically. Unlike arrays, elements are **not stored in contiguous memory locations**.
*   **The Array Limitation:** Arrays require a continuous block of memory. Once initialized with a fixed size, expanding them is impossible if the adjacent memory slots are already occupied.
*   **The Chain Model:** A Linked List overcomes this by allocating memory for each element independently. Individual elements (**nodes**) are linked together using **pointers/references**, forming a chain.
*   **Key Entry Points:**
    *   **Head:** A reference pointing to the very first node of the list (the entry point).
    *   **Tail:** The final node in the list, whose next pointer references `null` (signifying the end of the chain).

---

## Node Anatomy & Java Representation

Each individual node in a linked list must store two distinct pieces of information:
1.  **Data:** The actual value being stored (integer, string, object).
2.  **Next:** A reference variable storing the memory address/location of the subsequent node.

```java
// Node class blueprint
class Node {
    int data;      // Data value
    Node next;     // Reference variable pointing to the next node

    // Constructor providing both data and explicit next reference
    Node(int data1, Node next1) {
        this.data = data1;
        this.next = next1;
    }

    // Constructor providing only data (initializes terminal node)
    Node(int data1) {
        this.data = data1;
        this.next = null; // No immediate connection
    }
}
```

### Reference Variables vs. Pointers
*   **C++ (`Node*`):** Represents a raw pointer that stores direct, physical memory addresses, allowing explicit pointer arithmetic and manual memory management.
*   **Java (`Node`):** References act similarly to pointers but abstract away manual pointer arithmetic. A Java reference variable holds a managed, safe reference to the location of the object inside the JVM heap memory.

---

### Memory Footprint Analysis
While linked lists provide incredible flexibility, they carry a significantly higher memory overhead than arrays because they must store pointers/references alongside raw data. 

Assuming the stored data is a standard 4-byte integer (`int`), the overall footprint per node changes based on your system's architecture:

| System Architecture | Integer Data Size | Pointer/Reference Size | Total Memory per Node |
| :--- | :--- | :--- | :--- |
| **32-Bit System** | 4 Bytes | 4 Bytes | **8 Bytes** |
| **64-Bit System** | 4 Bytes | 8 Bytes | **12 Bytes** |

> **Takeaway:** On a standard 64-bit machine, a single linked list node consumes 3x more memory than a primitive array slot storing the exact same integer value.

---

### Types of Linked Lists

#### 1. Singly Linked Lists
*   **Mechanic:** Each node contains a single pointer pointing exclusively forward to the next node.
*   **Constraint:** Traversal is strictly **unidirectional**—you can only move forward from the `head` toward the `tail`.

#### 2. Doubly Linked Lists
*   **Mechanic:** Each node maintains **two** pointers: one pointing forward to the `next` node, and one pointing backward to the `prev` (previous) node.
*   **Advantage:** Allows for full **bidirectional** traversal and simplifies deleting a node when you only have a reference to the target node itself.

#### 3. Circular Linked Lists
*   **Mechanic:** The `next` pointer of the final node (`tail`) does not point to `null`. Instead, it loops back and references the `head` node directly.
*   **Advantage:** Forms a continuous closed loop, making cycles and round-robin scheduling loops straightforward to implement.

---

### Common Applications
*   **Base Data Structures:** Serving as the structural backbone for custom implementations of dynamic **Stacks** and **Queues**.
*   **System Memory Management:** Used by operating systems to log, track, and allocate free blocks of heap memory dynamically.
*   **State History Navigation:** Powering browser history tracking (Back/Forward buttons) or the Undo/Redo stack in software applications.
