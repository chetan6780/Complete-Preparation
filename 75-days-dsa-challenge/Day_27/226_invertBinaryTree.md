# [226. Invert Binary Tree](https://leetcode.com/problems/invert-binary-tree/)

### O(N) Time recursive solution

-   if root is null return null
-   we just need to swap the left and right children of each node recursively.we can use inbuilt swap function or implement our own swap function.
-   We can travel in preorder as well as postorder , both solutions are accepted.(here is preorder solution)

```cpp
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return NULL;

        // Swap left and right children
        // swap(node->left, node->right);
        TreeNode* temp;
        temp = root->left;
        root->left = root->right;
        root->right = temp;

        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};
```

### O(N) Time O(N) stack iterative solution

-   We use stack instead of recursive stack.

```cpp
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        stack<TreeNode*> st;
        st.push(root);

        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            if (node) {
                st.push(node->left);
                st.push(node->right);
                swap(node->left, node->right);
            }
        }
        return root;
    }
};
```

---

### Many might say why we need an iterative solution in every tree problem ?

**The ans is simple, Tree can be skewed which effectively makes it a linked list.
And if we recurse in a large linked-list, the call stack will overflow for sure.
That's why its necessary to also know how to implement iteratively.
Honestly, iterative implementation also will utilize a stack, but it will be in heap.**
