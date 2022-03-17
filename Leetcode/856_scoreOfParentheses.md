# [856. Score of Parentheses](https://leetcode.com/problems/score-of-parentheses/) 🌟🌟

Given a balanced parentheses string s, return the score of the string.

The score of a balanced parentheses string is based on the following rule:

-   "()" has score 1.
-   AB has score A + B, where A and B are balanced parentheses strings.
-   (A) has score 2 \* A, where A is a balanced parentheses string.

### Using stack

-   We use stack to store the score of each parentheses.
-   If we meet a `(`, we push 0 to the stack.
-   If we meet a `)`, pop call 0's and multiple the result with 2, also if there is only one () then result will become 0 so store val as `max(1, 2*val)`, push the result to the stack.
-   calculate total result from stack.
-   **TC: O(N)**
-   **SC: O(N)**

### code

```cpp
class Solution {
public:
    int scoreOfParentheses(string s)
    {
        int cnt = 0;
        stack<int> st;
        for (auto c : s) {
            int val = 0;
            if (c == '(') {
                st.push(0);
            } else {
                while (st.top() != 0) {
                    val += st.top();
                    st.pop();
                }
                val = max(2*val, 1);
                st.pop();
                st.push(val);
            }
        }
        while (!st.empty()) {
            cnt += st.top();
            st.pop();
        }
        return cnt;
    }
};
```

### Leetcode Approach 3: Count Cores

-   **TC: O(N)**
-   **SC: O(N)**

**Intuition**

-   The final sum will be a sum of powers of 2, as every core (a substring (), with score 1) will have it's score multiplied by 2 for each exterior set of parentheses that contains that core.

**Algorithm**

-   Keep track of the balance of the string, as defined in Approach #1. For every ) that immediately follows a (, the answer is 1 << balance, as balance is the number of exterior set of parentheses that contains this core.

### Code

```cpp
class Solution {
public:
    int scoreOfParentheses(string s)
    {
        int ans = 0, bal = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                bal++;
            } else {
                bal--;
                if (s[i-1] == '(')
                    ans += 1 << bal;
            }
        }
        return ans;
    }
};
```

### kkzeng's explanation:

The key idea is that:

1. the balance tells you what "depth" you are at since with each '(' we are increasing the depth by 1 (kind of similar to the concept in Solution 2).
2. the "cores" () are the only structure that provides value, the outer parentheses just add some multiplier to the cores. So we only need to be concerned with those.
   With those 2 ideas in mind, we are able to calculate how much the "core" is worth directly without having to calculate substructures recursively and then apply multipliers.

E.g. For the example of `( ( ) ( ( ) ) )`, with the stack method, we are calculating the inner structure `( ) ( ( ) )` first and then multiplying the score by 2. With the 3rd method, by knowing the depth of the core, we are actually performing this calculation `( ( ) )` + `( ( ( ) ) )`.
