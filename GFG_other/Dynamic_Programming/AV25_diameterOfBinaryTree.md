# Diameter of a Binary Tree

### Node structure

```cpp
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};
```

### Recursive Approach

- If root is NULL, then diameter is 0.return 0
- Get the diameter of left and right sub-trees.
- store max height.
- check if it itself is diameter.
- update max diameter.

### Code 1

```cpp
int diameterRec(Node *root, int &diamtr)
{
    if (root == NULL)
        return 0;

    // Calculate diameter of left and right subtrees
    int l = diameterRec(root->left, diamtr);
    int r = diameterRec(root->right, diamtr);

    int maxH = 1 + max(l, r); // maximum height
    int ans = max(maxH, 1 + l + r); // If it's itself is diameter
    diamtr = max(diamtr, ans); // store max diameter

    return maxH;
}

int diameter(Node *root)
{
    int diamtr = INT_MIN;
    diameterRec(root, diamtr);
    return diamtr;
}
```

### Time Complexity: O(n)

### Code 2

```cpp
int height(Node *root)
{
    if (root == NULL) return 0;

    return 1 + max(height(root->left), height(root->right));
}

int diameter(struct Node *root)
{
    if (root == NULL) return 0;

    int ldiameter = diameter(root->left);
    int rdiameter = diameter(root->right);

    int lheight = height(root->left);
    int rheight = height(root->right);

    return max({ldiameter, rdiameter, lheight + rheight + 1});
}
```

### Time Complexity: O(n2)

### References

- GFG: [Diameter of a Binary Tree](https://www.geeksforgeeks.org/diameter-of-a-binary-tree/)
- Youtube: [AV - Diameter of a Binary Tree](https://www.youtube.com/watch?v=zmPj_Ee3B8c&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=47)
