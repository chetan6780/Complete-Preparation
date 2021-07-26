# Registration System

### Problem link: [codeforces-C](https://codeforces.com/problemset/problem/4/C)

### Approach

- We will use unordered_map since order does not matter for this problem

### Code

```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl '\n'

int main()
{
    int n;
    cin >> n;

    unordered_map<string, int> mp;
    string s;

    for (int i = 0; i < n; i++)
    {
        cin >> s;
        if (mp[s] == 0)
            cout << "OK" << nl;
        else
            cout << s << mp[s] << nl;

        mp[s]++;
    }

    return 0;
}
```
