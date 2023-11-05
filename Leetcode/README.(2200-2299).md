# Leetcode Problem 1600-1699

---

# [2265. Count Nodes Equal to Average of Subtree](./2265_countNodeEqualToAverageOfSubtree.md) 🌟🌟

### Brute Force

-   For every root, calculate the sum of its subtree and the number of nodes in its subtree.
-   If the average is equal to the value of the node, increase the answer by 1.
-   Do same for left and right subtree.
-   **Time Complexity:** O(N^2)
-   **Space Complexity:** O(1), ignoring recursion stack.

### Optimized Solution

-   In brute force solution, we are calculating the sum of subtree for every node.
-   What if we start from the leaf nodes(kind of postorder traversal) and return {sum, count} to its parent.
-   now for current root we have sum and count of its left and right subtree.
-   we can simply calculate avg and check if it is equal to root->val and increase the answer by 1.
-   return {sum, count} to its parent, for calculating avg of its parent.
-   **Time Complexity:** O(N)
-   **Space Complexity:** O(1), ignoring recursion stack.
