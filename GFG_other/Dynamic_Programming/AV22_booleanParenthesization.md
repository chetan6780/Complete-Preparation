# Boolean Parenthesization Problem

Given a boolean expression with following symbols.

```
Symbols
    'T' ---> true
    'F' ---> false
```

And following operators filled between symbols

```
Operators
    &   ---> boolean AND
    |   ---> boolean OR
    ^   ---> boolean XOR
```

Count the number of ways we can parenthesize the expression so that the value of expression evaluates to true.
Let the input be in form of two arrays one contains the symbols (T and F) in order and other contains operators (&, | and ^)

### <h3 style="color: red">Warnings: Non of the code passed GFG</h3>

- Code 1 give TLE.
- Code 2&3 give WA when len==35.
- Neither GFG solution work.

### Recursive approach

### Code

```cpp

int solve(string &s, int i, int j, bool isTrue)
{
    if (i > j)
        return 0;

    if (i == j)
    {
        if (isTrue == true)
            return (s[i] == 'T') ? 1 : 0;
        else
            return (s[i] == 'F') ? 1 : 0;
    }

    int ans = 0;
    for (int k = i + 1; k <= j - 1; k += 2)
    {
        int lt = solve(s, i, k - 1, true);
        int lf = solve(s, i, k - 1, false);
        int rt = solve(s, k + 1, j, true);
        int rf = solve(s, k + 1, j, false);

        if (s[k] == '&')
        {
            if (isTrue)
                ans += lt * rt;
            else
                ans += lf * rt + rf * lt + lf * rf;
        }
        else if (s[k] == '|')
        {
            if (isTrue)
                ans += lt * rt + lt * rf + lf * rt;
            else
                ans += lf * rf;
        }
        else if (s[k] == '^')
        {
            if (isTrue)
                ans += lf * rt + lt * rf;
            else
                ans += lf * rf + lt * rt;
        }
    }
    return ans;
}

int countWays(int N, string S)
{
    return solve(S, 0, N - 1, true);
}
```

# DP APPROACHES

### A) Memoization: Map APPROACHE

### Code

```cpp

unordered_map<string, int> mp;

int solve(string &s, int i, int j, bool isTrue)
{
    if (i > j)
        return false;

    if (i == j)
    {
        if (isTrue == true)
            return (s[i] == 'T');
        else
            return (s[i] == 'F');
    }

    // created unique key for memoization
    string temp = to_string(i);
    temp.push_back('_');
    temp.append(to_string(j));
    temp.push_back('_');
    temp.append(to_string(isTrue));

    // if key is already present return its value
    if (mp.find(temp) != mp.end())
        return mp[temp];

    int ans = 0;
    for (int k = i + 1; k <= j - 1; k += 2)
    {
        int lt = solve(s, i, k - 1, true);
        int lf = solve(s, i, k - 1, false);
        int rt = solve(s, k + 1, j, true);
        int rf = solve(s, k + 1, j, false);

        if (s[k] == '&')
        {
            if (isTrue)
                ans += lt * rt;
            else
                ans += lf * rt + rf * lt + lf * rf;
        }
        else if (s[k] == '|')
        {
            if (isTrue)
                ans += lt * rt + lt * rf + lf * rt;
            else
                ans += lf * rf;
        }
        else if (s[k] == '^')
        {
            if (isTrue)
                ans += lf * rt + lt * rf;
            else
                ans += lf * rf + lt * rt;
        }
        mp[temp] = ans
    }
    return mp[temp] = ans;
}

int countWays(int N, string S)
{
    mp.clear(); // clear map
    return solve(S, 0, N - 1, true);
}
```

### 3D DP APPROACHE

### Code

```cpp
int solve(string &s, int i, int j, bool isTrue)
{
    if (i > j)
        return false;

    if (i == j)
    {
        if (isTrue == true)
            return (s[i] == 'T');
        else
            return (s[i] == 'F');
    }
    if (dp[i][j][isTrue] != -1)
        return dp[i][j][isTrue];

    int ans = 0;
    for (int k = i + 1; k <= j - 1; k += 2)
    {
        int lt, lf, rt, rf;
        if (dp[i][k - 1][1] != -1)
            lt = (dp[i][k - 1][1]);
        else
            lt = solve(s, i, k - 1, true);

        if (dp[i][k - 1][0] != -1)
            lf = (dp[i][k - 1][0]);
        else
            lf = solve(s, i, k - 1, false);

        if (dp[k + 1][j][1] != -1)
            rt = (dp[k + 1][j][1]);
        else
            rt = solve(s, k + 1, j, true);

        if (dp[k + 1][j][0] != -1)
            rf = (dp[k + 1][j][0]);
        else
            rf = solve(s, k + 1, j, false);

        if (s[k] == '&')
        {
            if (isTrue)
                ans += (lt * rt);
            else
                ans += (lf * rt + rf * lt + lf * rf);
        }
        else if (s[k] == '|')
        {
            if (isTrue)
                ans += (lt * rt + lt * rf + lf * rt);
            else
                ans += (lf * rf);
        }
        else if (s[k] == '^')
        {
            if (isTrue)
                ans += lf * rt + lt * rf;
            else
                ans += lf * rf + lt * rt;
        }
    }
    return dp[i][i][isTrue] = ans;
}

int countWays(int N, string S)
{
    memset(dp, -1, sizeof(dp));
    return solve(S, 0, N - 1, true);
}
```

### References

- GFG: [Boolean Parenthesization](https://www.geeksforgeeks.org/boolean-parenthesization-problem-dp-37/)
- YouTube: [AV - Boolean Parenthesization](https://www.youtube.com/watch?v=pGVguAcWX4g&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=38)
