# [227. Basic Calculator II](https://leetcode.com/problems/basic-calculator-ii/) 🌟🌟

Given a string s which represents an expression, evaluate this expression and return its value.
The integer division should truncate toward zero.

You may assume that the given expression is always valid. All intermediate results will be in the range of `[-231, 231 - 1]`.

**Note:** You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as `eval()`.

### Using Stack

-   Scan the string from left to right
    -   If the current character is a digit add it to the number currentNumber.
    -   Otherwise, the current character must be an operation (+,-,\*, /). Evaluate the expression based on the type of operation.
        -   _Addition (+) or Subtraction (-):_ We must evaluate the expression later based on the next operation. So, we must store the currentNumber to be used later. Let's push the currentNumber in the Stack.
        -   _Multiplication (\*) or Division (/):_ Pop the top values from the stack and evaluate the current expression. Push the evaluated value back to the stack.
-   Once the string is scanned, pop from the stack and add to the result.
-   **TC: O(n)**
-   **SC: O(n)**

### Code

```cpp
class Solution {
public:
    int calculate(string s)
    {
        int n = s.length();
        if (n == 0)
            return 0;
        stack<int> stk;
        int currentNumber = 0;
        char operation = '+';
        for (int i = 0; i < n; i++) {
            if (isdigit(s[i])) {
                currentNumber = (currentNumber * 10) + (s[i] - '0');
            }
            if (!isdigit(s[i]) && !iswspace(s[i]) || i == n - 1) {
                if (operation == '-') {
                    stk.push(-currentNumber);
                } else if (operation == '+') {
                    stk.push(currentNumber);
                } else if (operation == '*') {
                    int stkTop = stk.top();
                    stk.pop();
                    stk.push(stkTop * currentNumber);
                } else if (operation == '/') {
                    int stkTop = stk.top();
                    stk.pop();
                    stk.push(stkTop / currentNumber);
                }
                operation = s[i];
                currentNumber = 0;
            }
        }
        int ans = 0;
        while (stk.size()) {
            ans += stk.top();
            stk.pop();
        }
        return ans;
    }
};
```

### Without Stack

The approach works similar to Approach 1 with the following differences :

-   Instead of using a stack, we use a variable lastNumber to track the value of the last evaluated expression.
-   If the operation is Addition (+) or Subtraction (-), add the lastNumber to the result instead of pushing it to the stack. The currentNumber would be updated to lastNumber for the next iteration.
-   If the operation is Multiplication (\*) or Division (/), we must evaluate the expression lastNumber \* currentNumber and update the lastNumber with the result of the expression. This would be added to the result after the entire string is scanned.
-   **TC: O(n)**
-   **SC: O(1)**

### Code

```cpp
class Solution {
public:
    int calculate(string s)
    {
        int length = s.length();
        if (length == 0)
            return 0;
        int currentNumber = 0, lastNumber = 0, result = 0;
        char sign = '+';
        for (int i = 0; i < length; i++) {
            char currentChar = s[i];
            if (isdigit(currentChar)) {
                currentNumber = (currentNumber * 10) + (currentChar - '0');
            }
            if (!isdigit(currentChar) && !iswspace(currentChar) || i == length - 1) {
                if (sign == '+' || sign == '-') {
                    result += lastNumber;
                    lastNumber = (sign == '+') ? currentNumber : -currentNumber;
                } else if (sign == '*') {
                    lastNumber = lastNumber * currentNumber;
                } else if (sign == '/') {
                    lastNumber = lastNumber / currentNumber;
                }
                sign = currentChar;
                currentNumber = 0;
            }
        }
        result += lastNumber;
        return result;
    }
};
```
