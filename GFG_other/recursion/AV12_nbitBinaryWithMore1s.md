# N bit binary number with more number of ones than zeros.

Given a positive integer n, print all n-bit binary numbers having more 1’s than 0’s for any prefix of the number.

### Algorithms

1. Main function.

   - Get input int n. Create empty string and variabe zero ad one with the value 0

2. Recursive function.
   - if n is 0 ,then we print the output and return.
   - We always have choice to add 1 in the output, we do so.
   - Cal the recursive function with the reduced output.++one & --n.
   - When ones are more than zeros we can add zero in the output, we do so.
     - Call the recursive function with the reduced output. ++zero & --n.

### Code

```cpp
#include <bits/stdc++.h>
using namespace std;

void solve(int one, int zero, int n, string op)
{
    if (n == 0)
    {
        cout << op << ' ';
        return;
    }
    string op1 = op;
    op1.push_back('1');
    solve(one + 1, zero, n - 1, op1);

    if (one > zero)
    {
        string op2 = op;
        op2.push_back('0');
        solve(one, zero + 1, n - 1, op2);
    }
}

int main()
{
    int n;
    cin >> n;
    string op = "";

    int one = 0;
    int zero = 0;
    solve(one, zero, n, op);

    return 0;
}
```

### References

- GFG: [N bit binary number with more number of ones than zeros.](https://www.geeksforgeeks.org/print-n-bit-binary-numbers-1s-0s-prefixes/)
- Youtube: [N bit binary number with more number of ones than zeros.](https://www.youtube.com/watch?v=U81n0UYtk98&list=PL_z_8CaSLPWeT1ffjiImo0sYTcnLzo-wY&index=18)
