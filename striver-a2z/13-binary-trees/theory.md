# Introduction to Binary Trees

## Core Concepts & Terminology

*   **Non-Linear Hierarchy:** Unlike linear data structures (arrays, linked lists, stacks, queues), a Binary Tree organizes data in a multi-level, branching sequence—similar to a computer's file directory system.
*   **Node Anatomy:** Each node contains data (value/key) and pointers/references to a maximum of two children (**left child** and **right child**).
*   **Root Node:** The topmost node of the tree. It has no parent and serves as the single entry point for any traversal algorithm.
*   **Leaf Nodes:** Terminal nodes at the outermost ends of branches that have **zero** children.
*   **Ancestors:** All nodes encountered on the direct path moving upward from a specific node to the root.

---

## Types of Binary Trees

When interviewing or writing algorithms, the structural properties of these specific variations dictate your time and space complexities.

### 1. Full Binary Tree (Strict Binary Tree)
*   **Rule:** Every node must have either **0 or 2 children**. 
*   **Key Detail:** No node in this tree can ever have exactly *one* child. This structural consistency ensures highly predictable traversal and insertion patterns.

### 2. Complete Binary Tree
*   **Rule:** All levels are completely filled except possibly the last level, which **must be filled from left to right**.
*   **Key Detail:** Every leaf node must lean as far left as possible. You will use this exact property later when implementing **Heaps** and priority queues, as it maps perfectly to contiguous array indexing.

### 3. Perfect Binary Tree
*   **Rule:** Every single internal node has exactly 2 children, and **all leaf nodes are at the exact same level**.
*   **Key Detail:** This is the most dense version of a binary tree. The number of nodes exactly doubles with each level you move down.

### 4. Balanced Binary Tree
*   **Rule:** For *any given node* in the tree, the absolute difference between the height of its left subtree and right subtree can be **at most 1**.
*   **Key Detail:** This property keeps the maximum height of the tree bounded to $O(\log_2 N)$, guaranteeing efficient search, insertion, and deletion times.

### 5. Degenerate Tree (Skewed Tree)
*   **Rule:** Every internal node has exactly one child, causing the tree to grow in a single path leaning entirely left or right.
*   **Key Detail:** The tree effectively degrades into a **Singly Linked List**. The height of the tree becomes $n$ (total nodes), causing operations to drop to a highly inefficient worst-case time complexity of $O(n)$.

---

## Cheat Sheet: Tree Types Comparison

| Tree Type | Node Child Count Rule | Level Filling Constraint | Main Application / Advantage |
| :--- | :--- | :--- | :--- |
| **Full** | Exactly 0 or 2 | None | Predictable space optimization |
| **Complete** | 0, 1, or 2 | Filled left-to-right on last level | Binary Heaps / Array-based trees |
| **Perfect** | Exactly 0 or 2 | All levels 100% fully filled | Maximum density, predictable depth |
| **Balanced**| Height delta $\le 1$ | Distributed relatively evenly | Maintains $O(\log N)$ operation bounds |
| **Degenerate**| Exactly 1 (except leaf) | 1 node per level (linear path) | Used to analyze worst-case time limits |

---

## Binary Tree Representation in Java

Java implements binary trees using **object references**. Instead of direct memory manipulation via raw pointers (like in C++), Java references store the memory addresses of child nodes to establish hierarchical connections.

### Node Architecture Breakdown
1. **Data Component (`int data`):** Holds the actual value or key of the node.
2. **Left Child Reference (`Node left`):** Reference variable pointing to the left child node. Initialized to `null`.
3. **Right Child Reference (`Node right`):** Reference variable pointing to the right child node. Initialized to `null`.
4. **Constructor:** Allocates memory for a new node, assigns the input value to `data`, and explicitly marks both child references as `null` to signify a fresh node with zero initial links.

### Java Implementation & Tree Assembly

```java
import java.util.*;

// Class representing a Node in the Binary Tree
class Node { 
    int data;       // Stores the value of the node
    Node left;      // Reference to the left child node
    Node right;     // Reference to the right child node

    // Constructor to initialize a node with a given key
    public Node(int key) {
        data = key;     
        left = null;    
        right = null;   
    }
}

// Class containing the logic for Binary Tree creation
class Solution {
    public Node createBinaryTree() {
        // Creates the root node with key value 1
        Node root = new Node(1);       

        // Creates a left child node for the root with key value 2
        root.left = new Node(2);       

        // Creates a right child node for the root with key value 3
        root.right = new Node(3);      

        // Creates a left child node for the right child of root with key value 5
        root.right.left = new Node(5); 

        return root;
    }
}

// Driver class
public class Main {
    public static void main(String[] args) {
        Solution solution = new Solution();
        Node root = solution.createBinaryTree();

        // Tree created, can be used for further operations
    }
}
