# [102. Binary Tree Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal/) 🌟🌟

Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

### O(N) Time and O(N) Space

-   Create an empty queue q.
-   Push the root node of tree to q.
-   Loop while the queue is not empty:
    -   get all the elements of q.
    -   push their left and right nodes in the queue.
    -   push_back these elements in the vector.
    -   push_back this vector in main 2d vector.
-   return 2d vector.

### Code

```cpp
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> levelOrderVec;
        if(root==NULL)return levelOrderVec;

        queue<TreeNode *> q;
        q.push(root);

        while(!q.empty()){
            int sz=q.size();
            vector<int> level;
            for(int i=0;i<sz;i++){
                TreeNode *node= q.front();
                q.pop();
                if(node->left!=NULL)q.push(node->left);
                if(node->right!=NULL)q.push(node->right);
                level.push_back(node->val);
            }
            levelOrderVec.push_back(level);
        }
        return levelOrderVec;
    }
};
```

### Recursive solution

-   Create a recursive function that takes root, level and 2d vector as arguments.
-   If root is null, return.
-   If level is greater than the size of 2d vector, push an empty vector in it.
-   Push the value of root in the vector at level index.
-   recursively call the function for left and right child of root with level+1.

```cpp
class Solution {
private:
    void levelOrderRecursive(TreeNode* root, int level, vector<vector<int>>& res)
    {
        if (root == NULL) {
            return;
        }
        if (level >= res.size()) {
            res.push_back(vector<int>());
        }
        res[level].push_back(root->val);
        levelOrderRecursive(root->left, level + 1, res);
        levelOrderRecursive(root->right, level + 1, res);
    }

public:
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> res;
        if (root == NULL)
            return res;
        levelOrderRecursive(root, 0, res);
        return res;
    }
};
```

---

[A general approach to level order traversal questions in Java](https://leetcode.com/problems/binary-tree-level-order-traversal/discuss/114449/A-general-approach-to-level-order-traversal-questions-in-Java)
