# [199. Binary Tree Right Side View](https://leetcode.com/problems/binary-tree-right-side-view/)

### Recursive Solution

-   Simple DFS with right node first.
-   if our level is same as result vector's size, then we push the value in the result vector.
-   Travel right first and then left.

### Code

```cpp
class Solution {
private:
    void rightSideViewDFS(vector<int>& res, TreeNode* root, int level)
    {
        if (root == NULL) return;

        if (level == res.size()) res.push_back(root->val);

        rightSideViewDFS(res, root->right, level + 1); // first right
        rightSideViewDFS(res, root->left, level + 1); // then left
    }

public:
    vector<int> rightSideView(TreeNode* root)
    {
        vector<int> res;
        rightSideViewDFS(res, root, 0);
        return res;
    }
};
```

### Iterative Solution

-   Simple level order traversal.
-   We push last element of queue in the result to get right side view.

### Code

```cpp
class Solution {
public:
    vector<int> rightSideView(TreeNode* root)
    {
        vector<int> res;
        if (root == NULL)
            return res;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                TreeNode* node = q.front(); q.pop();

                if (i == sz - 1) res.push_back(node->val);

                if (node->left != NULL) q.push(node->left);
                if (node->right != NULL) q.push(node->right);
            }
        }
        return res;
    }
};
```
