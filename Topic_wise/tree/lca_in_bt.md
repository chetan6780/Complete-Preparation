# Lowest Common Ancestor in binary tree

Given a Binary Tree and the value of two nodes n1 and n2. The task is to find the lowest common ancestor of the nodes n1 and n2 in the given Binary Tree.

## Method 1

### Algorithm

1. Find the path from the root node to node n1 and store it in a vector or array.
2. Find the path from the root node to node n2 and store it in another vector or array.
3. Traverse both paths untill the values in arrays are same. Return the common element just before the mismatch.

### Example

```
For Example: consider the above-given tree and nodes 4 and 5.
Path from root to node 4: [1, 2, 4]
Path from root to node 5: [1, 2, 5].
The last common node is 2 which will be the LCA.
```

### code

```cpp

// find path if exitst and store the path in vecotr.
bool findPath(Node *root, vector<int> &path, int k)
{
    // base case
    if (root == NULL)
        return false;

    // Store this node in path vector.
    // The node will be removed if not in path from root to k
    path.push_back(root->key);

    // See if the k is same as root's key
    if (root->key == k)
        return true;

    // Check if k is found in left or right sub-tree
    if ((root->left && findPath(root->left, path, k)) ||
        (root->right && findPath(root->right, path, k)))
        return true;

    // If not present in subtree rooted with root, remove root from path[] and return false
    path.pop_back();
    return false;
}

// Function to return LCA if node n1, n2
int findLCA(Node *root, int n1, int n2)
{
    // to store paths to n1 and n2 from the root
    vector<int> path1, path2;

    // Find paths from root to n1 and root to n2 If either n1 or n2 is not present, return -1
    if (!findPath(root, path1, n1) || !findPath(root, path2, n2))
        return -1;

    // Compare the paths to get the first different value
    int i;

    for (i = 0; i < path1.size() && i < path2.size(); i++)
        if (path1[i] != path2[i])
            break;

    return path1[i - 1];
}
```

### Complexity

- Time complexity: O(N)
- Space Complexity: O(N)

---

## Method 2

### Algorithm

1. The idea is to traverse the tree starting from the root node.
2. If any of the given keys (n1 and n2) matches with root, then root is LCA (assuming that both keys are present).
3. If root doesn't match with any of the keys, we recur for left and right subtrees.
4. The node which has one key present in its left subtree and the other key present in the right subtree is the LCA.
5. If both keys lie in left subtree, then left subtree has LCA also, otherwise, LCA lies in the right subtree.

### Code

```cpp
Node *findLCA(Node *root, int n1, int n2)
{
    // Base case
    if (root == NULL)
        return NULL;

    // if key matches with n1 or n2 it's a LCA
    if (root->key == n1 || root->key == n2)
        return root;

    // Look for keys in left and right subtrees
    Node *left_lca = findLCA(root->left, n1, n2);
    Node *right_lca = findLCA(root->right, n1, n2);

    // If both of the above calls return Non-NULL, then one key is present in one subtree and other is present in other, So this node is the LCA.
    if (left_lca && right_lca)
        return root;

    // Otherwise check if left subtree or right subtree is LCA
    return (left_lca != NULL) ? left_lca : right_lca;
}
```

### Complexity
- Time complexity: O(N)
- Space complexity: O(1)
