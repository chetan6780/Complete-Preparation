# [997. Find the Town Judge](https://leetcode.com/problems/find-the-town-judge/)

In a town, there are n people labeled from 1 to n. There is a rumor that one of these people is secretly the town judge.

If the town judge exists, then:

-   The town judge trusts nobody.
-   Everybody (except for the town judge) trusts the town judge.
-   There is exactly one person that satisfies properties 1 and 2.

You are given an array trust where trust[i] = [ai, bi] representing that the person labeled ai trusts the person labeled bi.

Return the label of the town judge if the town judge exists and can be identified, or return -1 otherwise.

### Most intuitive

-   There are 2 main conditions for the town judge if it exists.
    -   1. The town judge trusts no one.
    -   2. Everyone (except the town judge)(n-1 people) trusts the town judge.
-   So we can build trusts array in which we store how many person , the current person trusts.
-   also we can build trusted array in which we store the current person is trusted by how many people.
-   So the answer will be simple, if any person has `trusts count == 0` and `trusted count == n-1`(everyone except town judge), then it is the town judge.else we return -1.
-   **TC: O(N)**
-   **SC: O(N)**, 2 Extra vectors, We can also take vector of pairs instee

### Code

```cpp
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& t)
    {
        vector<int> trusts(n + 1, 0), trusted(n + 1, 0);
        for (int i = 0; i < t.size(); i++) { // here t.size() not n
            trusts[t[i][0]]++;
            trusted[t[i][1]]++;
        }
        for (int i = 1; i <= n; i++) {
            if (trusted[i] == n - 1 && trusts[i] == 0) {
                return i;
            }
        }
        return -1;
    }
};
```
