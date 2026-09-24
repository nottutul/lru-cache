# LRU Cache in C++

A high-performance C++ implementation of an **LRU (Least Recently Used) Cache** with $O(1)$ average time complexity and an interactive command-line interface.

## 🧠 Why `unordered_map` and `list`?

- **`unordered_map`**: Provides **$O(1)$ lookups** by mapping keys directly to list nodes. Hash maps are fast for searching.
- **`list` (Doubly Linked List)**: Maintains strict recency ordering (front = most recent, back = least recent) and enables **$O(1)$ re-ordering and eviction** via pointer manipulation (splicing) without needing to search the list.

## 📊 Complexity

- **Time Complexity**: $O(1)$ for both `get()` and `put()`.
- **Space Complexity**: $O(\text{capacity})$.

## 🚀 How to Run

## 🚀 How to Run

1. Clone the repository:

   ```bash
   git clone https://github.com/nottutul/lru-cache.git

   ```

2. navigate to the folder

   ```bash
   cd lru-cache

   ```

3. run the code
   ```bash
   lru-cache> ./lru
   ```

or simply run the lru.exe file
