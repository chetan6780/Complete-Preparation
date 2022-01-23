# [107. Binary Tree Level Order Traversal II](https://leetcode.com/problems/binary-tree-level-order-traversal-ii/) 🌟🌟

Given the root of a binary tree, return the bottom-up level order traversal of its nodes' values. (i.e., from left to right, level by level from leaf to root).

### Recursive solution

-   The code is same as [level-order-traversal](./102_btLevelOrderTraversal.md), just 2 modifications.
    1. We have to insert New vector to the beginning of the result vector.
    2. We have to insert values at `res.size() - 1 - level` position.

### Code

```cpp
class Solution {
private:
    void levelOrderBottomRec(TreeNode* root, int level, vector<vector<int>>& res)
    {
        if (root == NULL) {
            return;
        }
        if (level >= res.size()) {
            res.insert(res.begin(), vector<int>());
        }
        res[res.size() - 1 - level].push_back(root->val);
        levelOrderBottomRec(root->left, level + 1, res);
        levelOrderBottomRec(root->right, level + 1, res);
    }

public:
    vector<vector<int>> levelOrderBottom(TreeNode* root)
    {
        vector<vector<int>> res;
        if (root == NULL)
            return res;
        levelOrderBottomRec(root, 0, res);
        return res;
    }
};
```

### Iterative solution

-   It is also same as [level-order-traversal](./102_btLevelOrderTraversal.md), just we return the reverse of the result vector.

### Code

```cpp
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> levelorder;
        if(root==NULL){
            return levelorder;
        }

        queue<TreeNode *> q;
        q.push(root);

        while(!q.empty()){
            int sz=q.size();
            vector<int> level;
            for(int i=0;i<sz;i++){
                TreeNode *node= q.front(); q.pop();
                if(node->left!=NULL)q.push(node->left);
                if(node->right!=NULL)q.push(node->right);
                level.push_back(node->val);
            }
            levelorder.push_back(level);
        }
        reverse(levelorder.begin(),levelorder.end());
        return levelorder;

    }
};
```

### Iterative Solution without reverse

-   If you don't want to reverse the vector, you can insert new level directly to the beginning of the result vector.
-   But as compared to previous solution, this solution is takes more time to execute.

### Code

```cpp
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> levelorder;
        if(root==NULL){
            return levelorder;
        }

        queue<TreeNode *> q;
        q.push(root);

        while(!q.empty()){
            int sz=q.size();
            vector<int> level;
            for(int i=0;i<sz;i++){
                TreeNode *node= q.front(); q.pop();
                if(node->left!=NULL)q.push(node->left);
                if(node->right!=NULL)q.push(node->right);
                level.push_back(node->val);
            }
            levelorder.insert(levelorder.begin(),level);
        }
        return levelorder;
    }
};
```
