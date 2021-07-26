# Bear and Segment

### Problem link: [Codechef-SEGM01](https://www.codechef.com/problems/SEGM01)

### Approach

- This is simple problem we will check if 1 appear once and then if it apperas after 0 again the ans will be "NO" otherwise "YES".

### Code

```cpp
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        bool flag = false;
        int cnt = 0;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '1' && flag == false)
            {
                cnt++;
                flag = true;
            }
            else if (s[i] == '0')
                flag = false;
        }

        if (cnt == 1)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
```
