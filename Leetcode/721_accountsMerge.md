# [721. Accounts Merge](https://leetcode.com/problems/accounts-merge/) 🌟🌟

Given a list of accounts where each element accounts[i] is a list of strings, where the first element accounts[i][0] is a name, and the rest of the elements are emails representing **emails** of the account.

Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some common email to both accounts. Note that even if two accounts have the same name, they may belong to different people as people could have the same name. A person can have any number of accounts initially, but all of their accounts definitely have the same name.

After merging the accounts, return the accounts in the following format: the first element of each account is the name, and the rest of the elements are emails **in sorted order**. The accounts themselves can be returned in **any order**.

-   **Famous Union-find interview Question**
-   **Nutanix**

### DFS Solution

<!-- TODO: DFS solution here -->

### Union-find (DSU)

<!-- TODO: Learn DSU and explain this question -->

### Code

```cpp
class Solution {
private:
    string find(string s, map<string, string>& p){
        return p[s] == s ? s : find(p[s], p);
    }

public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& acts)
    {
        map<string, string> owner;
        map<string, string> parents;
        map<string, set<string>> unions;
        for (int i = 0; i < acts.size(); i++) {
            for (int j = 1; j < acts[i].size(); j++) {
                parents[acts[i][j]] = acts[i][j];
                owner[acts[i][j]] = acts[i][0];
            }
        }
        for (int i = 0; i < acts.size(); i++) {
            string p = find(acts[i][1], parents);
            for (int j = 2; j < acts[i].size(); j++)
                parents[find(acts[i][j], parents)] = p;
        }
        for (int i = 0; i < acts.size(); i++)
            for (int j = 1; j < acts[i].size(); j++)
                unions[find(acts[i][j], parents)].insert(acts[i][j]);

        vector<vector<string>> res;
        for (pair<string, set<string>> p : unions) {
            vector<string> emails(p.second.begin(), p.second.end());
            emails.insert(emails.begin(), owner[p.first]);
            res.push_back(emails);
        }
        return res;
    }
};
```

### MUST READ:

-   [Disjoint Set Union (DSU)/Union-Find - A Complete Guide](<https://leetcode.com/discuss/general-discussion/1072418/Disjoint-Set-Union-(DSU)Union-Find-A-Complete-Guide>)
-   [DSU Practice Questions](https://leetcode.com/list/9nkostg1/)
-   [[Java/C++] Union Find](https://leetcode.com/problems/accounts-merge/discuss/109157/JavaC%2B%2B-Union-Find)
