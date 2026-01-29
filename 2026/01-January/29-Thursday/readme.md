# Minimum Cost to Convert String

This problem is about converting one string into another string using the **minimum total cost**.

---

## Problem in Simple Words

* You have a `source` string and a `target` string (same length)
* You are allowed to change one character to another if a rule is given
* Every rule has a **cost**
* You can apply rules **any number of times**
* Your task is to find the **minimum cost** to convert `source` into `target`
* If it is not possible, return `-1`

---

## Key Observation

* Only **26 lowercase letters** exist
* Each character can be treated as a **node**
* Each conversion rule is like a **path with a cost**
* Sometimes converting via another character is cheaper

So we need the **cheapest cost between every pair of characters**.

---

## Algorithm Used

### Floyd–Warshall Algorithm

Why?

* Works well for small graphs
* Here we only have **26 nodes**
* Finds minimum cost between **all character pairs**

---

## Step-by-Step Logic

1. Create a `26 x 26` matrix
2. Set:

   * Cost to same character = `0`
   * Others = very large value
3. Fill direct conversion costs
4. Run Floyd–Warshall to relax all paths
5. For each position in the string:

   * Add cost to convert `source[i]` → `target[i]`
6. If any conversion is impossible, return `-1`

---

## Time Complexity

* Floyd–Warshall: `26³` (constant)
* Traversing string: `O(n)`

Efficient for large input sizes.

---

## Java Conversion Hints (Small Pieces Only)

You can easily convert the C++ solution to Java using these parts.

### Matrix Setup

```java
long INF = Long.MAX_VALUE / 4;
long[][] dist = new long[26][26];

for (int i = 0; i < 26; i++) {
    Arrays.fill(dist[i], INF);
    dist[i][i] = 0;
}
```

### Add Conversion Cost

```java
int u = original[i] - 'a';
int v = changed[i] - 'a';
dist[u][v] = Math.min(dist[u][v], cost[i]);
```

### Floyd–Warshall Core Logic

```java
for (int k = 0; k < 26; k++)
    for (int i = 0; i < 26; i++)
        for (int j = 0; j < 26; j++)
            dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
```

### Final Cost Check

```java
if (dist[s][t] == INF) return -1;
ans += dist[s][t];
```

These snippets are enough to rewrite the full solution in Java.

---

## Output

* Returns the **minimum cost** if conversion is possible
* Returns `-1` if conversion cannot be done

---

Happy Coding 🚀
