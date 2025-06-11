# GFG-Shortest-Common-Supersequence

# 🌟 Shortest Common Supersequence (SCS) 🚀

Welcome to the **Shortest Common Supersequence (SCS)** guide! 🎯 This problem is a fascinating twist on the LCS (Longest Common Subsequence) and forms the basis for many real-world applications like merging file versions or DNA sequence alignment! 🧬

---

## 📘 Problem Statement

Given two strings `text1` and `text2`, return the **shortest string that has both `text1` and `text2` as subsequences**.

### 💡 Example:

Input: `text1 = "abac"`, `text2 = "cab"`
Output: `"cabac"`

---

## 🧵 Approach 1: Pure Recursion 🌀

### 🔍 Idea:

* Try to build SCS by checking each character.
* If characters match ➡️ include once and move both pointers.
* If not ➡️ take minimum length after adding one character from either string.

### ⛔ Drawback:

* **Exponential time complexity** ⚠️
* Time Complexity: **O(2^n)**

---

## 🧠 Approach 2: Top-Down DP (Memoization) 🧠

### 💡 Idea:

* Store the result of overlapping subproblems using a 2D memo table.
* Avoid redundant recursive calls 🛡️

### ⚙️ How:

* Use a matrix `dp[i][j]` to represent shortest supersequence of `text1[i:]` and `text2[j:]`

### 🧮 Complexity:

* Time: **O(n \* m)**
* Space: **O(n \* m)** (for memo table)

---

## 🧊 Approach 3: Bottom-Up DP (Tabulation) 🧊

### 🔍 Idea:

* Use a 2D DP table to build the length of SCS from substrings.
* Use LCS as a stepping stone:

  * SCS length = `len(text1) + len(text2) - LCS(text1, text2)`

### 🚀 Steps:

1. Find the LCS.
2. Use the LCS to weave both strings into the shortest supersequence.

### ⚡ Complexity:

* Time: **O(n \* m)**
* Space: **O(n \* m)**

---

## 💼 Approach 4: Space Optimized DP 💾

### 🧠 Idea:

* Just like LCS space optimization, use only 2 rows (or 2 columns) at a time.
* Construct length only; actual SCS string construction still needs full table or trace-back logic.

### 🌟 Advantage:

* Saves space in memory-critical environments.

### 🚀 Complexity:

* Time: **O(n \* m)**
* Space: **O(2 \* min(n, m))**

---

## 🧮 Bonus: SCS via LCS Function (Efficient Space + Logic) 🧠

This approach cleverly reuses a **space-optimized LCS function** to compute the length of the Shortest Common Supersequence!

### 🔧 How it works:

* Step 1: Calculate LCS length using a 2-row DP table.
* Step 2: Use formula: `SCS Length = len(text1) + len(text2) - LCS Length`

### 💡 Why it's smart:

* Reuses LCS logic 🔁
* Saves space with just two rows 💾
* Keeps code clean and modular ✨

### 🚀 Complexity:

* Time: **O(n \* m)**
* Space: **O(2 \* min(n, m))**

---

## 🎓 Final Thoughts

* 🧬 **SCS is a super useful variation of LCS**.
* It's essential when you want to merge two sequences while keeping them intact in order.

🔁 **Use SCS in:**

* File version merging ⚙️
* DNA sequence analysis 🧬
* Text diffing tools 📝

---

## 📜 License

MIT License. Free to use and modify! 💡

---

**Made with ❤️ by Ridham Garg**
