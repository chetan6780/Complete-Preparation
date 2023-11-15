# [2390. Removing Stars From a String](https://leetcode.com/problems/removing-stars-from-a-string/) 🌟🌟

You are given a string s, which contains stars \*.

In one operation, you can:

-   Choose a star in s.
-   Remove the closest non-star character to its left, as well as remove the star itself.
    Return the string after all stars have been removed.

Note:

-   The input will be generated such that the operation is always possible.
-   It can be shown that the resulting string will always be unique.

### Simulation

-   Its given that if we get a start then we should remove \* and the closest non-star character to its left.
-   So we will maintain an temporary array where we will mark 1 if we have \* and also mark its left non-star character as 1.
-   at the end we will traverse the temporary array and add all the characters which are not marked as 1.
-   **TC**: O(N)
-   **SC**: O(N)

### Code

```cpp
class Solution {
public:
    string removeStars(string s)
    {
        int n = s.size();
        int str = 0;
        vector<int> v(n, 0);
        for (int i = n - 1; i >=0; i--){
            if (s[i] == '*'){
                v[i] = 1;
                str++;
            }else{
                if(str > 0){
                    v[i] = 1;
                    str--;
                }
            }
        }
        // for (auto x : v)
        //     cout << x << ' ';
        // cout <<endl;
        string res= "";
        for (int i = 0; i < n; i++){
            if (v[i] == 0){
                res += s[i];
            }
        }
        return res;
    }
};
```

### Stack

-   We can use stack to solve this problem.
-   We will traverse the string and if we get a \* then we will pop the top element from the stack.
-   At the end we will return the reverse of the stack.
-   **TC**: O(N)
-   **SC**: O(N)

### Code

```cpp
// Code 1
class Solution {
public:
    string removeStars(string s)
    {
        stack<char> st;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == '*') {
                if (!st.empty()) {
                    st.pop();
                }
            } else {
                st.push(s[i]);
            }
        }
        string res = "";
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

// Code 2
class Solution {
public:
    string removeStars(string s)
    {
        stack<char> st;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == '*') {
                if (!st.empty()) {
                    st.pop();
                }
            } else {
                st.push(s[i]);
            }
        }
        string res = "";
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
```
