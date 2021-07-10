# Level order traversal in spiral form

Print tree in level order traversal in spiral form.

### Code

```cpp

vector<int> findSpiral(Node *root)
{
    vector<int> res;

    if (root == NULL)
        return;

    stack<struct Node *> s1; // For right to left
    stack<struct Node *> s2; // For left to right

    s1.push(root);

    // Keep printing while any of the stacks has some nodes
    while (!s1.empty() || !s2.empty())
    {
        // Print nodes of current level from s1 and push nodes of next level to s2
        while (!s1.empty())
        {
            struct Node *temp = s1.top();
            s1.pop();
            res.push_back(temp->data);

            // Note that is right is pushed before left
            if (temp->right)
                s2.push(temp->right);
            if (temp->left)
                s2.push(temp->left);
        }

        // Print nodes of current level from s2 and push nodes of next level to s1
        while (!s2.empty())
        {
            struct Node *temp = s2.top();
            s2.pop();
            res.push_back(temp->data);

            // Note that is left is pushed before right
            if (temp->left)
                s1.push(temp->left);
            if (temp->right)
                s1.push(temp->right);
        }
    }
    return res;
}
```

### Reference
GFG :[link](https://www.geeksforgeeks.org/level-order-traversal-in-spiral-form/)