# Insertion in binary tree

Given a Binary Tree and a Key. The task is to insert the key into the binary tree at **first position available** in **level order**.

### Algorithm
1. We travese in level order.
2. Find empty place in left then in right.
3. If we found a place we create new node with given data there.

### Code
```cpp

void insert(Node *temp, int key)
{
    queue<Node *> q;
    q.push(temp);

    // Do level order traversal until we find an empty place.
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        // if there is no empty place in left we push left in queue  
        // else we found empty place and we create new node there. 
        if (temp->left != NULL)
            q.push(temp->left);
        else
        {
            temp->left = newNode(key);
            break;
        }

        // if there is no empty place in right we push right in queue  
        // else we found empty place and we create new node there. 
        if (temp->right != NULL)
            q.push(temp->right);
        else
        {
            temp->right = newNode(key);
            break;
        }
    }
}
```