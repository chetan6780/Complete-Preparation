# [682. Baseball Game](https://leetcode.com/problems/baseball-game/) 🌟🌟

You are keeping score for a baseball game with strange rules. The game consists of several rounds, where the scores of past rounds may affect future rounds' scores.

At the beginning of the game, you start with an empty record. You are given a list of strings ops, where ops[i] is the ith operation you must apply to the record and is one of the following:

- An integer x - Record a new score of x.
- "+" - Record a new score that is the sum of the previous two scores. It is guaranteed there will always be two previous scores.
- "D" - Record a new score that is double the previous score. It is guaranteed there will always be a previous score.
- "C" - Invalidate the previous score, removing it from the record. It is guaranteed there will always be a previous score.
Return the sum of all the scores on the record.

### Stack Solution

- Simple simulation using stack.

### Code
```cpp
class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> st;
        int sum = 0;
        for (auto op : ops) {
            if (op == "C") {
                sum -= st.top();
                st.pop();
            } else if (op == "D") {
                st.push(st.top() * 2);
                sum += st.top();
            } else if (op == "+") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.push(a);
                st.push(a + b);
                sum += a + b;
            } else {
                st.push(stoi(op));
                sum += stoi(op);
            }
        }
        return sum;
    }
};
```