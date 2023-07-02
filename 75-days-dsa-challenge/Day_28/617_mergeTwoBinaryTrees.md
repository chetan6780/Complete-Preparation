# [617. Merge Two Binary Trees](https://leetcode.com/problems/merge-two-binary-trees/)

### DFS - Recursive

-   if both nodes are null returns null.
-   if one of the node null, return the other node.
-   else Create new node with value = t1->val+t2->val.
-   set new nodes left = merge(t1->left, t2->left)
-   set new nodes right = merge(t1->right, t2->right)
-   return new node;

**Time complexity**: **O(n)**. A total of n nodes need to be traversed. Here, n represents the minimum number of nodes from the two given trees.
**Space complexity**: **O(n)**. The depth of the recursion tree can go upto n in the case of a skewed tree. In average case, depth will be **O(log n)**.

### Code

```cpp
class Solution{
public:
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2){
        if (root1 == NULL && root2 == NULL) return NULL;
        if (root1 == NULL) return root2;
        if (root2 == NULL) return root1;

        TreeNode *sum = new TreeNode(root1->val + root2->val);
        sum->left = mergeTrees(root1->left, root2->left);
        sum->right = mergeTrees(root1->right, root2->right);

        return sum;
    }
};
```

```cpp
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2)
    {
        if (root1 == NULL || root2 == NULL)
            return root1 == NULL ? root2 : root1;
        TreeNode* root = new TreeNode(root1->val + root2->val);
        root->left = mergeTrees(root1->left, root2->left);
        root->right = mergeTrees(root1->right, root2->right);
        return root;
    }
};
```

### BFS - Iterative

-   Base condition as in recursion
-   Create 2 queues for BFS and push root nodes in them.
-   While both queues are not empty
    -   Store the front nodes and Pop from both queues
    -   Add value of 2nd node in 1st
    -   if node1's left is null and node2's left is not null, then add node1's left to node2's left
    -   else if both's left not null then push them in respective queues
    -   if node1's right is null and node2's right is not null, then add node1's right to node2's right
    -   else if both's right not null then push them in respective queues.

**Time complexity**: **O(n)**. A total of n nodes need to be traversed. Here, n represents the minimum number of nodes from the two given trees.
**Space complexity**: **O(n)**. The size of queue can go upto n in the case of a skewed tree.

### Code

```cpp
class Solution{
public:
    TreeNode *mergeTrees(TreeNode *t1, TreeNode *t2){
        // Base condition as in recursion
        if (t1 == NULL && t2 == NULL) return NULL;
        if (t1 == NULL) return t2;
        if (t2 == NULL) return t1;

        // Create 2 queues for BFS and push root nodes in them.
        queue<TreeNode *> q1, q2;
        q1.push(t1), q2.push(t2);

        // While both queues are not empty
        while (!q1.empty() && !q2.empty()){
            // Store the front nodes and Pop from both queues
            TreeNode *node1(q1.front()), *node2(q2.front());
            q1.pop(), q2.pop();

            // Add value of 2nd node in 1st
            node1->val += node2->val;

            // if node1's left is null and node2's left is not null, then add node1's left to node2's left
            if (node1->left == NULL && node2->left != NULL)
                node1->left = node2->left;
            else if (node1->left && node2->left) // if both's left not null then push them in respective queues
                q1.push(node1->left), q2.push(node2->left);

            // if node1's right is null and node2's right is not null, then add node1's right to node2's right
            if (node1->right == NULL && node2->right != NULL)
                node1->right = node2->right;
            else if (node1->right && node2->right) // if both's right not null then push them in respective queues
                q1.push(node1->right), q2.push(node2->right);
        }
        return t1;
    }
};
```
