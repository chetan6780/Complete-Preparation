# Permutation with case change

### Algorithm

1. Main function.

   - Take input, output string
   - Call recursive function

2. Recursive function.
   - If length of string is 0 we print the output
   - Initialize two strings, 1 for upper case and 2nd for lower case
   - Push lower case in first string and upprcase of first character in second string
   - Erase first character from string
   - Recursive call for op1 and op2

### Code

```cpp
void solve(string ip, string op)
{
    if (ip.length() == 0)
    {
        cout << op << endl;
        return;
    }
    string op1 = op;
    string op2 = op;

    op1.push_back(tolower(ip[0]));
    op2.push_back(toupper(ip[1]));

    ip.erase(ip.begin() + 0);

    solve(ip, op1);
    solve(ip, op2);
}

int main()
{
    string ip;
    cin >> ip;
    string op = "";
    solve(ip, op);
    return 0;
}
```

### References

- GFG: [Permutation with case change](https://www.geeksforgeeks.org/permute-string-changing-case/)
- Youtube: [Permutation with case change](https://www.youtube.com/watch?v=J2Er5XceU_I&list=PL_z_8CaSLPWeT1ffjiImo0sYTcnLzo-wY&index=15)
