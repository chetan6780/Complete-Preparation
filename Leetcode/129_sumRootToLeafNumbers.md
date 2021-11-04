# [129. Sum Root to Leaf Numbers](https://leetcode.com/problems/sum-root-to-leaf-numbers/) 🌟🌟

You are given the root of a binary tree containing digits from 0 to 9 only.
Each root-to-leaf path in the tree represents a number.

- For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.

Return the total sum of all root-to-leaf numbers. Test cases are generated so that the answer will fit in a 32-bit integer.
A leaf node is a node with no children.

### O(N) Time recursive

- We recursively traverse to the all leaf node.
- Multiply val by 10 and add curr val in it.
- if both left and right child is null, we add the current node value to the sum.
- else recurse for left anf right subtree.
- Stack can grow upto the height of the tree so that we can explore the path from root to leaf node.
- Thus, **Space Complexity = O(Height of the tree)**
- **Time Complexity:O(N)** --> All Nodes will be visited once.

### Code

```cpp
class Solution{
    int ans = 0;
    void dfs(TreeNode *root, int val){
        if (!root) return;
        val *= 10;
        val += root->val;

        if (root->left == NULL && root->right == NULL){
            ans += val;
            return;
        }
        dfs(root->left, val);
        dfs(root->right, val);
    }

public:
    int sumNumbers(TreeNode *root){
        if (!root) return 0;
        dfs(root, 0);
        return ans;
    }
};
```

### Useful Comment:

1. List of problems you need to master the concept :
   - [104. Maximum Depth of Binary Tree](https://leetcode.com/problems/maximum-depth-of-binary-tree/)
   - [110. Balanced Binary Tree](https://leetcode.com/problems/balanced-binary-tree/)
   - [111. Minimum Depth of Binary Tree](https://leetcode.com/problems/minimum-depth-of-binary-tree/)
   - [112. Path Sum](https://leetcode.com/problems/path-sum/)
   - [113. Path Sum II](https://leetcode.com/problems/path-sum-ii/)
   - [124. Binary Tree Maximum Path Sum](https://leetcode.com/problems/binary-tree-maximum-path-sum/)
   - [257. Binary Tree Paths](https://leetcode.com/problems/binary-tree-paths/)
   - [437. Path Sum III](https://leetcode.com/problems/path-sum-iii/)
   - [559. Maximum Depth of N-ary Tree](https://leetcode.com/problems/maximum-depth-of-n-ary-tree/)
   - [687. Longest Univalue Path](https://leetcode.com/problems/longest-univalue-path/)
   - [988. Smallest String Starting From Leaf](https://leetcode.com/problems/smallest-string-starting-from-leaf/)
   - [1376. Time Needed to Inform All Employees](https://leetcode.com/problems/time-needed-to-inform-all-employees/)

If you find more problems, please comment it below :)
