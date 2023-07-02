# [101. Symmetric Tree](https://leetcode.com/problems/symmetric-tree/)

### O(N) Time solution

-   we will traverse left and right subtrees of the root with the same type of traversal.
-   we compare the value of left with right or value of right with left , if they are not equal we return false.
-   we recurse for left's left with right's right and left's right with right's left.

### Code

```cpp
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return root==NULL || isSymmetricHelp(root->left,root->right);
    }

    bool isSymmetricHelp(TreeNode* left,TreeNode* right){
        if(left==NULL || right==NULL) return left==right;
        if(left->val!=right->val) return false;

        return isSymmetricHelp(left->left,right->right)&&isSymmetricHelp(left->right,right->left);
    }
};
```

### O(N) Time, using 2 queue, iterative solution

-   Same recursive solution can be converted to iterative solution by using queue.
-   Remember while using 2 queue we push `left->left,left->right` in 1st queue and `right->right,right->left` in 2nd queue.

```cpp
class Solution{
public:
    bool isSymmetric(TreeNode *root){
        if (!root) return true;

        TreeNode *left, *right;
        queue<TreeNode *> q1, q2;
        q1.push(root->left);
        q2.push(root->right);

        while (!q1.empty() && !q2.empty()){
            left = q1.front();
            q1.pop();
            right = q2.front();
            q2.pop();

            if (left == NULL && right == NULL) continue;
            if (left == NULL || right == NULL) return false;
            if (left->val != right->val) return false;

            q1.push(left->left);
            q1.push(left->right);
            q2.push(right->right);
            q2.push(right->left);
        }
        return true;
    }
};
```

### O(N) Time, using 1 queue, iterative solution

-   We can use 1 queue instead of 2.
-   remember that while using 1 queue we do `left->left,right->right,left->right,right->left.`

```cpp
class Solution{
public:
    bool isSymmetric(TreeNode *root){
        TreeNode *left, *right;
        if (!root) return true;

        queue<TreeNode *> q;
        q.push(root->left);
        q.push(root->right);

        while (!q.empty()){
            left = q.front();
            q.pop();
            right = q.front();
            q.pop();

            if (left == NULL && right == NULL) continue;
            if (left == NULL || right == NULL) return false;
            if (left->val != right->val) return false;

            q.push(left->left);
            q.push(right->right);
            q.push(left->right);
            q.push(right->left);
        }
        return true;
    }
};
```
