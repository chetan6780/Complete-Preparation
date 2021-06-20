// ? https://www.hackerearth.com/practice/data-structures/hash-tables/basics-of-hash-tables/practice-problems/algorithm/perfect-pair-df920e90/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    // marking all squares and cubes true
    bool sq_cq[2001] = {false};
    for (int i = 1; i * i <= 2000; i++)
        sq_cq[i * i] = true;
    for (int i = 1; i * i * i <= 2000; i++)
        sq_cq[i * i * i] = true;

    int t;
    cin >> t;
    while (t--)
    {
        int n, cnt = 0;
        cin >> n;
        int a[n];
        unordered_map<int, int> m;
        // getting input and storing their freq in unordered_map
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            m[a[i]]++;
        }

        // from 1 to 1000 we check for every i
        for (int i = 1; i <= 1000; i++)
        {
            // if 2*i th element in sq_cq is true it can form (n*(n-1))/2 pairs so we add them to cnt {here n is natural number not n from program}
            if (sq_cq[2 * i])
                cnt += (m[i] * (m[i] - 1) / 2);

            // then we check from i+1 to n if i+j th element is true, it can form (freq[ith]*freq[jth]) pairs, we add them in cnt
            for (int j = i + 1; j <= 1000; j++)
                if (sq_cq[i + j])
                    cnt += (m[i] * m[j]);
        }
        cout << cnt << '\n';
    }
    return 0;
}