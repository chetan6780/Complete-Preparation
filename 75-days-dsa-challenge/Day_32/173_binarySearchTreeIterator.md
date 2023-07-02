# [173. Binary Search Tree Iterator](https://leetcode.com/problems/binary-search-tree-iterator/)

### Solution

-   Code is self explanatory.
-   Traverse as left as possible.

### Code

```cpp

class BSTIterator {
private:
    stack<TreeNode*> st;

public:
    BSTIterator(TreeNode* root)
    {
        st = stack<TreeNode*>();
        addAllLeft(root);
    }

    int next()
    {
        TreeNode* topValue = st.top();
        st.pop();
        addAllLeft(topValue->right);
        return topValue->val;
    }

    bool hasNext()
    {
        return !st.empty();
    }

    void addAllLeft(TreeNode* root)
    {
        while (root != nullptr) {
            st.push(root);
            root = root->left;
        }
    }
};
```
