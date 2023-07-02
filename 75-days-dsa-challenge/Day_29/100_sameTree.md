# [100. Same Tree](https://leetcode.com/problems/same-tree/) 

### Intuitive recursive solution

-   self explanatory

```cpp
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        if (p == NULL && q == NULL) return true;
        if (p == NULL || q == NULL) return false;
        if (p->val != q->val) return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
```

### Recursive to iterative using queue

```cpp
class Solution {
private:
    bool check(TreeNode* left, TreeNode* right)
    {
        if (left == NULL || right == NULL) return false;
        if (left->val != right->val) return false;
        return true;
    }

public:
    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        if (p == NULL && q == NULL) return true;
        if (check(p, q) == false) return false;
        queue<TreeNode*> q1, q2;
        q1.push(p);
        q2.push(q);

        while (q1.empty() == false) {
            TreeNode* left = q1.front(); q1.pop();
            TreeNode* right = q2.front(); q2.pop();

            if (left == NULL && right == NULL) continue;
            if (check(left, right) == false) return false;

            q1.push(left->left);
            q1.push(left->right);
            q2.push(right->left);
            q2.push(right->right);
        }
        return true;
    }
};
```
