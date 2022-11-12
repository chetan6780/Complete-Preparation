# Alien Dictionary

-   [GFG](https://practice.geeksforgeeks.org/problems/alien-dictionary/1)
-   [Leetcode Premium](https://leetcode.com/problems/alien-dictionary/)

### BFS - Toposort

-   Below are the two cases where it is not possible to create a valid dictionary.
    -   When string a is greater than string b and all the character matches except extra characters from string a then it is not possible to create a valid dictionary. Ex. `abcd` and `abc` then it is not possible to create a valid dictionary.
    -   When there is cyclic dependency then it is not possible to create a valid dictionary. Ex. 'abc', 'cde','ace' then it is not possible to create a valid dictionary.
-   **TC: O(N \* |S| + K)** , where |S| denotes maximum length of string
-   **SC: O(K)**

### Code

```cpp
class Solution {
    vector<int> topoSort(int V, vector<int> adj[])
    {
        vector<int> inDegree(V, 0);
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                inDegree[it]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> topo;
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            topo.push_back(node);
            // node in topo so decrease it from indegree
            for (auto it : adj[node]) {
                inDegree[it]--;
                if (inDegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        return topo;
    }

public:
    string findOrder(string dict[], int N, int K)
    {
        vector<int> adj[K];
        for (int i = 0; i < N - 1; i++) {
            string word1 = dict[i];
            string word2 = dict[i + 1];

            for (int j = 0; j < min(word1.length(), word2.length()); j++) {
                if (word1[j] != word2[j]) {
                    adj[word1[j] - 'a'].push_back(word2[j] - 'a');
                    break;
                }
            }
        }

        vector<int> topo = topoSort(K, adj);
        if (topo.size() != K) {
            return "";
        }

        string ans = "";
        for (auto it : topo) {
            ans += (it + 'a');
        }

        return ans;
    }
};
```
