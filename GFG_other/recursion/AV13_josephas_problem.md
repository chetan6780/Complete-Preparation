# Josephas Problem

There are n people standing in a circle waiting to be executed. The counting out begins at some point in the circle and proceeds around the circle in a fixed direction. In each step, a certain number of people are skipped and the next person is executed. The elimination proceeds around the circle (which is becoming smaller and smaller as the executed people are removed), until only the last person remains, who is given freedom. Given the total number of persons n and a number k which indicates that k-1 persons are skipped and kth person is killed in circle. The task is to choose the place in the initial circle so that you are the last one remaining and so survive.

### Algorithm

1. Main function.

   - N = number of people, k = steps
   - From 1 to n inclusive
   - Initialize index to 0 and ans to -1
   - Recursive function with k-1 as step
   - Print answer.

2. Recursive function.
   - Base condition - only one person remains.
   - Get the index of person who die.
   - erase that position. (kill that person :P)
   - Call Recursive function for reduced input.

### Code

```cpp
#include <bits/stdc++.h>
using namespace std;
// IBH - Induction, Base and Hypothesis method

void solve(vector<int> &v, int k, int index, int &ans)
{
    if (v.size() == 1)
    {
        ans = v[0];
        return;
    }

    index = (index + k) % v.size();
    v.erase(v.begin() + index);

    solve(v, k, index, ans);

    return;
}

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> v;
    for (int i = 1; i <= n; i++)
        v.push_back(i);

    int index = 0;
    int ans = -1;

    solve(v, k - 1, index, ans);
    cout << ans << endl;

    return 0;
}
```

### References

- GFG: [Josephas Problem](https://www.geeksforgeeks.org/josephus-problem-set-1-a-on-solution/)
- Youtube: [Josephas Problem](https://www.youtube.com/watch?v=ULUNeD0N9yI&list=PL_z_8CaSLPWeT1ffjiImo0sYTcnLzo-wY&index=19)
