## Use BFS when the problem asks for...

BFS explores the graph layer by layer, like ripples in a pond. This property makes it perfect for finding the **shortest path** or tracking **proximity**.

### 1. "Shortest Path" or "Minimum Steps" in Unweighted Graphs
Because BFS visits all nodes at distance 1, then distance 2, and so on, the first time you reach your target node, you are guaranteed to have found the shortest path.
* **Keywords:** Shortest path, minimum moves, fewest steps, least number of operations.
* **Example:** *"Find the minimum number of knight moves to reach a target square on a chessboard."*

### 2. Level-Order Traversal
If you need to process nodes level by level or group them by their distance from the source.
* **Keywords:** Level by level, layer order, nearest neighbors.
* **Example:** *"Print a binary tree level by level."*

### 3. Multi-Source Shortest Path (Simultaneous Expansion)
When multiple points are expanding at the same time and rate, BFS handles this naturally by initializing the queue with all starting sources.
* **Keywords:** Spreading, rotting, flooding, infection.
* **Example:** *"Given a grid with rotting oranges, find how many minutes it takes for all fresh oranges to rot."*

---

## Use DFS when the problem asks for...

DFS dives as deep as possible down a path before backtracking. It is ideal for problems involving **exhaustion**, **structure**, or **connectivity**.

### 1. Exhaustive Search (Exploring All Paths)
If you need to find *every single* possible combination, permutation, or path from start to finish, DFS (often paired with backtracking) is your best bet.
* **Keywords:** Find all paths, generate all combinations, list all subsets.
* **Example:** *"Find all paths from the source vertex to the target vertex."*

### 2. Connectivity, Components, and Cycles
If the problem just asks "Are these two things connected?" or "How many distinct groups are there?", DFS is highly efficient because it completely clears out one component before moving to the next.
* **Keywords:** Number of islands, connected components, detect a cycle, maze solving.
* **Example:** *"Count the number of connected islands in a 2D grid matrix."*

### 3. Topological Sort / Dependency Resolution
When you need to order items based on dependencies (e.g., Task A must be done before Task B). DFS uses a post-order traversal to naturally order nodes by their completion time.
* **Keywords:** Course schedule, prerequisites, build order, dependencies.
* **Example:** *"Determine the order of courses you should take given their prerequisites."*

---

## Quick Decision Matrix

| Problem Scenario | BFS 🟢 | DFS 🔴 | Why? |
| :--- | :---: | :---: | :--- |
| **Shortest path on unweighted graph** | **Yes** | No | BFS guarantees shortest path first. DFS might find a longer path first and waste time. |
| **Graph is extremely deep / infinite** | **Yes** | No | DFS will cause a Stack Overflow or get stuck forever. BFS will find the target if it's close to the root. |
| **Memory is heavily constrained** | No | **Yes** | BFS stores an entire "level" in memory (can be massive). DFS only stores the current path. |
| **Need to find all paths** | No | **Yes** | DFS naturally lends itself to backtracking and exploring every branch. |
| **Detecting a cycle** | Possible | **Yes** | DFS keeps track of the "current path" via the recursion stack, making back-edges easy to spot. |

---

## A Rule of Thumb for Your Interviews

> "If it's about shortest path or finding something close to the starting point, use **BFS**. If it's about exploring every possibility, checking connectivity, or analyzing the structure of the graph, use **DFS**."
