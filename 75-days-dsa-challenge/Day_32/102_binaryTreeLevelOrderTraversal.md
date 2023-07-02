# [102. Binary Tree Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal/)

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
        vector<vector<int>> levelorder;
        if(root==NULL)return levelorder;

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
        return levelorder;
    }
};
```
