# Or in matrix

### Problem link: [486B](https://codeforces.com/problemset/problem/486/B)

### Approach

Hint of this problem is presented in its statement. " where is equal to 1 if some ai = 1, otherwise it is equal to 0."

To solve this problem, do 3 following steps:

1. Assign all aij (1 ≤ i ≤ m, 1 ≤ j ≤ n) equals to 1.
2. If some bij = 0, then do assignments: aik = atj = 0 (1 ≤ k ≤ n, 1 ≤ t ≤ m) (that means, assign all elements in row i and column j of matrix a to 0).
3. Then we have matrix a which need to find. Just check whether from matrix a, can we produce matrix b. If not, the answer is obviously "NO".

### Complexity

We can implement this algorithm in **O(m \* n)**, but it's not neccesary since 1 ≤ m, n ≤ 100.

### Code

```cpp
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int a[n][m];
    int b[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            b[i][j] = 1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 0)
            {
                // make column zero
                for (int x = 0; x < n; x++)
                {
                    b[x][j] = 0;
                }
                // make row zero
                for (int x = 0; x < m; x++)
                {
                    b[i][x] = 0;
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int c = 0;
            // if a[i][j]th element is 1 ,sum of row+col should be > 0
            if (a[i][j] == 1)
            {
                for (int x = 0; x < n; x++)
                {
                    c += b[x][j];
                }
                for (int x = 0; x < m; x++)
                {
                    c += b[i][x];
                }
                // since this element is 1 if sum is 0 then we print NO and return
                if (c == 0)
                {
                    cout << "NO" << "\n";
                    return 0;
                }
            }
        }
    }
    // if all checks work well we print YES and array
    cout << "YES" << "\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << b[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}

```
