// * https://www.hackerearth.com/practice/algorithms/searching/linear-search/practice-problems/algorithm/simple-search-4/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &it : a)
        cin >> it;

    int k;
    cin >> k;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == k)
        {
            cout << i;
            return 0;
        }
    }

    return 0;
}