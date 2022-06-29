# Generate Balanced Paranthesis

Write a function to generate all possible n pairs of balanced parentheses.

### Algorithm

1. balancedParanthesis function. (Main function)

   - Create a vector to store the results.
   - Inititalize the open and close variables with n. And a empty string for output.
   - Recursive getParanthesis function which return vector of string with balaced paranthesis values.

2. getParanthesis function. (Recursive function)
   - If both open and close are 0 then we push output in the vector and return.
   - If we have open paranthesis remaining.
     - Create new output variable.
     - push open paranthesis in it.
     - Call the recursive function with the reduced output.
   - If we have more close paranthesis remaining than open paranthesis.
     - Create new output variable.
     - push close paranthesis in it.
     - Call the recursive function with the reduced output.

### Code

```cpp
#include <bits/stdc++.h>
using namespace std;

void getParanthesis(int open, int close, string op, vector<string> &v)
{
    if (open == 0 && close == 0)
    {
        v.push_back(op);
        return;
    }

    if (open != 0)
    {
        string op1 = op;
        op1.push_back('(');
        getParanthesis(open - 1, close, op1, v);
    }
    if (close > open)
    {
        string op2 = op;
        op2.push_back(')');
        getParanthesis(open, close - 1, op2, v);
    }
}

vector<string> balancedParanthesis(int n)
{
    vector<string> v;
    int open = n, close = n;
    string op = "";
    getParanthesis(open, close, op, v);
    return v;
}
```

### References

- GFG: [Generate Balanced Paranthesis](https://www.geeksforgeeks.org/print-all-combinations-of-balanced-parentheses/)
- Youtube: [Generate Balanced Paranthesis](https://www.youtube.com/watch?v=eyCj_u3PoJE&list=PL_z_8CaSLPWeT1ffjiImo0sYTcnLzo-wY&index=18)
