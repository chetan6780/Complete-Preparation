# [653. Two Sum IV - Input is a BST](https://leetcode.com/problems/two-sum-iv-input-is-a-bst/) 🌟

Given the root of a Binary Search Tree and a target number k, return true if there exist two elements in the BST such that their sum is equal to the given target.

### O(N) Time and O(N) space

- This method also works for those who are not BSTs.
- The idea is to use a hashtable to save the values of the nodes in the BST. Each time when we insert the value of a new node into the hashtable, we check if the hashtable contains k - node.val.

### Code

```cpp
class Solution{
public:
    unordered_set<int> s;
    bool findTarget(TreeNode *root, int k){
        if (!root) return false;
        if (s.count(k - root->val)) return true;
        s.insert(root->val);
        return findTarget(root->left, k) || findTarget(root->right, k);
    }
};
```

### O(N) Time and O(N) space

- The idea is to use a sorted array to save the values of the nodes in the BST by using an inorder traversal.
- Then, we use two pointers which begins from the start and end of the array to find if there is a sum k.

### Code

```cpp
    bool findTarget(TreeNode* root, int k) {
        vector<int> nums;
        inorder(root, nums);
        for(int i = 0, j = nums.size()-1; i<j;){
            if(nums[i] + nums[j] == k)return true;
            (nums[i] + nums[j] < k)? i++ : j--;
        }
        return false;
    }

    void inorder(TreeNode* root, vector<int>& nums){
        if(root == NULL)return;
        inorder(root->left, nums);
        nums.push_back(root->val);
        inorder(root->right, nums);
    }
```

### O(hn) Time and O(h) space

- `h` is the height of the tree, which is `logn` at best case, and `n` at worst case.
- The idea is to use binary search method.
- For each node, we check if k - node.val exists in this BST.

```cpp
    bool findTarget(TreeNode* root, int k) {
        return dfs(root, root,  k);
    }

    bool dfs(TreeNode* root,  TreeNode* cur, int k){
        if(cur == NULL)return false;
        return search(root, cur, k - cur->val) || dfs(root, cur->left, k) || dfs(root, cur->right, k);
    }

    bool search(TreeNode* root, TreeNode *cur, int value){
        if(root == NULL)return false;
        return (root->val == value) && (root != cur)
            || (root->val < value) && search(root->right, cur, value)
                || (root->val > value) && search(root->left, cur, value);
    }
```
