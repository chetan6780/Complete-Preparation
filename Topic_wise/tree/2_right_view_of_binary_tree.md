# Right View of binary Tree

Given a Binary Tree, find Right view of it. Right view of a Binary Tree is set of nodes visible when tree is viewed from right side.

### Algorithm

1. Do Level order traversal.
2. Store last element of each order in result vector.

### Code

```cpp

vector<int> rightView(Node *root)
{
    queue<Node *> q;
    vector<int> v;

    if (root == NULL) return v;

    q.push(root);

    int l = q.size();
    while (l)
    {
        int k = q.size();
        Node *temp;
        while (k--)
        {
            temp = q.front();
            q.pop();

            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
        v.push_back(temp->data);
        l = q.size();
    }

    return v;
}
```
