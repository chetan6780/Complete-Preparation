# [Two sets](https://cses.fi/problemset/task/1092/)

Your task is to divide the numbers `1,2,...,n` into two sets of equal sum.

### Explanation

-   From math, we know that we can only divide numbers in two sets if the sum off all numbers is even.
-   If its odd return "NO".
-   sum of n numbers = `n*(n+1)/2`.
-   we need to create two sets with sum = `total_sum/2`.
-   here is simple algorithm:
    -   take two vectors to return the two sets.
    -   start from n and keep adding numbers to first set until sum of first set is less than or equal to `total_sum/2`.
    -   if sum of first set is greater than `total_sum/2`, then add the current number to second set.
    -   finally, print "YES" and the two sets.

### Code

```cpp
void solve()
{
    ll n;
    cin >> n;
    ll sm = n * (n + 1) / 2;
    if (sm & 1) {
        no;
        return;
    }
    ll half = sm / 2;
    vector<ll> a, b;
    for (ll i = n; i >= 1; i--) {
        if (half - i >= 0) {
            a.push_back(i);
            half -= i;
        } else {
            b.push_back(i);
        }
    }
    print("YES");
    print(a.size());
    for (auto x : a)
        cout << x << ' ';
    cout << nl;
    print(b.size());
    for (auto x : b)
        cout << x << ' ';
    cout << nl;
    return;
}

```
