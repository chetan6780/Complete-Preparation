# [133. Clone Graph](https://leetcode.com/problems/clone-graph/) 🌟🌟

Given a reference of a node in a connected undirected graph.

Return a deep copy (clone) of the graph.

Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

```
class Node {
    public int val;
    public List<Node> neighbors;
}
```

### Solution

-   To clone a graph, you will need to traverse it.
-   Both BFS and DFS are for this purpose. But that is not all you need.
-   To clone a graph, you need to have a copy of each node and you need to avoid copying the same node for multiple times.
-   So you still need a mapping from an original node to its copy.

### DFS Solution

-   We need map to store copies of node.
-   We pass node and map in dfs function.
-   **DFS:**
-   if node is already visited, return the node
-   else create a new node and add it to the map
-   add all the neighbors of the node in the new node(add dfs)
-   return new node

### Code

```cpp
class Solution {
private:
    Node* dfs(Node* node, unordered_map<Node*, Node*>& copies)
    {
        // base case
        if (node == NULL)
            return NULL;

        // if node is already visited, return the node
        if (copies.find(node) != copies.end())
            return copies[node];

        // else create a new node and add it to the map
        Node* newNode = new Node(node->val);
        copies[node] = newNode;

        // add all the neighbors of the node in the new node
        for (Node* x : node->neighbors) {
            newNode->neighbors.push_back(dfs(x, copies));
        }

        // return new node
        return newNode;
    }

public:
    Node* cloneGraph(Node* node)
    {
        unordered_map<Node*, Node*> copies;
        return dfs(node, copies);
    }
};
```

### BFS Solution

-   create a map to store the cloned nodes & queue for bfs
-   create a new node with the same value as the original node
-   and add it to the map
-   **BFS:**
-   add all the neighbors of the node in the new node
-   if x is not in the map
-   add x->val in the map
-   add x to the queue
-   add x to the neighbors of the cloned node

### Code

```cpp
class Solution {
public:
    Node* cloneGraph(Node* node)
    {
        if (node == NULL)
            return NULL;

        // create a map to store the cloned nodes & queue for bfs
        unordered_map<Node*, Node*> copies;
        queue<Node*> q;
        q.push(node);

        // create a new node with the same value as the original node
        // and add it to the map
        Node* newNode = new Node(node->val);
        copies[node] = newNode;

        // bfs
        while (!q.empty()) {
            Node* frontNode = q.front();
            q.pop();

            // add all the neighbors of the node in the new node
            for (Node* x : frontNode->neighbors) {
                if (copies.find(x) == copies.end()) { // if x is not in the map
                    copies[x] = new Node(x->val); // add x->val in the map
                    q.push(x); // add x to the queue
                }
                // add x to the neighbors of the cloned node
                copies[frontNode]->neighbors.push_back(copies[x]);
            }
        }
        return newNode;
    }
};
```
