# [150. Evaluate Reverse Polish Notation](https://leetcode.com/problems/evaluate-reverse-polish-notation/description/) 🌟🌟

You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

Evaluate the expression. Return an integer that represents the value of the expression.

Note that:

-   The valid operators are '+', '-', '\*', and '/'.
-   Each operand may be an integer or another expression.
-   The division between two integers always truncates toward zero.
-   There will not be any division by zero.
-   The input represents a valid arithmetic expression in a reverse polish notation.
-   The answer and all the intermediate calculations can be represented in a 32-bit integer.

### Stack Solution

-   This is simple stack problem.
-   We use stack to store the numbers in the expression.
-   If we encounter an operator, we pop the top two numbers 'b' and 'a' respectively(order matters for '-' and '/').
-   Then we calculate the result and push it back to the stack.
-   And if its number we simply push it to the stack.
-   Finally we return the top of the stack, which contains the result.
-   **TC: O(N)**
-   **SC: O(N)**

### Code

```cpp
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> st;
        for(auto x: tokens){
            if(x=="+"|| x=="-" || x=="*" || x=="/"){
                int b = st.top();st.pop();
                int a = st.top();st.pop();

                if(x=="+"){
                    st.push(a+b);
                }else if(x=="-"){
                    st.push(a-b);
                }else if(x=="*"){
                    st.push((long)a*(long)b);
                }else if(x=="/"){
                    st.push(a/b);
                }
            }else{
                st.push(stoi(x));
            }
        }
        return st.top();
    }
};
```
