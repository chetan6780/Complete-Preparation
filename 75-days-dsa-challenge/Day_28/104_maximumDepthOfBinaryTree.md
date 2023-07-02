# [104. Maximum Depth of Binary Tree](https://leetcode.com/problems/maximum-depth-of-binary-tree/)

### O(N) Time and O(H) Space,(DFS) More preferred than iterative

-   If root is null then return 0.
-   else return 1 + maximum depth of(left subtree, right subtree)
-   Worst case, if tree is skewed then it will take **O(N)** else **O(h)** space, where h is the height of the tree.


### Code

```cpp
class Solution{
public:
    int maxDepth(TreeNode *root){
        if (root == NULL) return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};
```

### O(N) Time and O(N) Space (BFS), using level order traversal

-   Same like level order traversal, but we need to keep track of the depth.

### Code

```cpp
class Solution{
public:
    int maxDepth(TreeNode *root){
        if (root == NULL) return 0;

        queue<TreeNode *> q;
        q.push(root);
        int depth = 0;

        while (!q.empty())        {
            int sz = q.size();
            for (int i = 0; i < sz; i++)            {
                TreeNode *node = q.front();
                q.pop();
                if (node->left != NULL)
                    q.push(node->left);
                if (node->right != NULL)
                    q.push(node->right);
            }
            depth++;
        }
        return depth;
    }
};
```
