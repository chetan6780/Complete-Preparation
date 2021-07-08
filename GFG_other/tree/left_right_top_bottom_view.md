# Left, Right, Top, Bottom view of binary tree

# Left

- Just do level order traversal.
- for every traversal print first element and push delimiter at end.

### Code

```cpp
struct Node 
{ 
    Node * left; 
    Node* right; 
    int hd; 
    int data; 
}; 

void leftView(Node *root)
{
    queue<Node *> q;

    if (root == NULL)
        return;

    // Push root Delimiter
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();

        if (temp)
        {
            //  Print first element of leve
            cout << temp->data;

            while (q.front() != NULL)
            {
                if (temp->left)
                    q.push(temp->left);

                if (temp->right)
                    q.push(temp->right);

                q.pop();
                temp = q.front();
            }

            // push delimiter at the end of Level
            q.push(NULL);
        }
        q.pop();
    }
}
```

# Right

- For right view, we just need to print last element and push the delimiter at the end.

```
        cout << temp->data;
        q.push(NULL);
```

# Top

```cpp

void topview(Node *root)
{
    if (root == NULL)
        return;

    queue<Node *> q;

    map<int, int> m;

    int hd = 0;

    root->hd = hd;

    // push node and horizontal distance to queue
    q.push(root);

    while (q.size())
    {
        hd = root->hd;

        // Check if any node with this horizontal distance is encontered yet or not.
        // If not insert, current node's data to Map
        if (m.count(hd) == 0)
            m[hd] = root->data;

        // Push the left and right child with its horizontal distance to queue
        if (root->left)
        {
            root->left->hd = hd - 1;
            q.push(root->left);
        }

        if (root->right)
        {
            root->right->hd = hd + 1;
            q.push(root->right);
        }

        q.pop();
        root = q.front();
    }

    // Print the map as it stores the nodes appearing in the Top View
    for (auto i = m.begin(); i != m.end(); i++)
    {
        cout << i->second << " ";
    }
}
```

# Bottom

A node x is there in output if x is the bottom most instead of the top most node at its horizontal distance.

The process of printing the bottom view is almost the same as that of top view with a little modification that while storing the node's data along with a particular horizontal distance in the map, keep updating the node's data in the map for a particular horizontal distance so that the map contains the last node appearing with a particular horizontal distance instead of first.
