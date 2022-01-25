# [103. Binary Tree Zigzag Level Order Traversal](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/) 🌟🌟

Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

### This question is in continuation with **A general approach to level order traversal questions** series.

**Prerequisites:**

1. [Binary tree level order traversal](./102_btLevelOrderTraversal.md)
2. [Binary tree level order traversal - II](./107_btLevelOrderTraversalII.md)

### Recursive solution

-   Here is just one change, if level is odd we insert value at the beginning of vector, otherwise at the end.

### Code

```cpp
class Solution {
private:
    void zigzagLevelOrderRec(TreeNode* root, int level, vector<vector<int>>& res)
    {
        if (root == NULL)
            return;
        if (level >= res.size()) {
            res.push_back(vector<int>());
        }

        if (level & 1) { // odd
            res[level].insert(res[level].begin(), root->val);
        } else { // even
            res[level].push_back(root->val);
        }

        zigzagLevelOrderRec(root->left, level + 1, res);
        zigzagLevelOrderRec(root->right, level + 1, res);
    }

public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root)
    {
        vector<vector<int>> res;
        if (root == NULL)
            return res;
        zigzagLevelOrderRec(root, 0, res);
        return res;
    }
};
```

### Iterative solution

-   Same code, just reversed the current level vector if result vector has odd size.
-   Reason for above operation: since in the example we can observe every even vector is reversed, we have to reverse the even level vector, so at that time res vector has odd size.

### Code

```cpp
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root)
    {
        vector<vector<int>> res;
        if (root == NULL) {
            return res;
        }
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int sz = q.size();
            vector<int> currLevel;
            for (int i = 0; i < sz; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
                currLevel.push_back(node->val);
            }

            if (res.size() & 1) { // odd // only added this line
                reverse(currLevel.begin(), currLevel.end());
            }
            res.push_back(currLevel);
        }
        return res;
    }
};
```

### Without reverse, insert at front if odd (Fastest)

-   Here, just like we did in Q107, we just insert at the beginning of vector if res vector size is odd(i.e. currLevel is even).

### Code

```cpp
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root)
    {
        vector<vector<int>> res;
        if (root == NULL) {
            return res;
        }
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int sz = q.size();
            vector<int> currLevel;
            bool isOdd = (res.size() & 1);
            for (int i = 0; i < sz; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
                if(isOdd)
                    currLevel.insert(currLevel.begin(), node->val);
                else
                    currLevel.push_back(node->val);
            }
            res.push_back(currLevel);
        }
        return res;
    }
};
```
