# [Number spiral](https://cses.fi/problemset/task/1071)

### Explanation

-   Observation based problem.
-   For every diagonal, number = `n^2 - (n-1)` where n is the number of rows/columns.
-   if we go up from the diagonal, number decreases by 1 when n is even and increases by 1 when n is odd.
-   if we go left from the diagonal, number increases by 1 when n is even and decreases by 1 when n is odd.
-   rest is just implementation.

### Code

```cpp
// code is for 1 iteration
void solve()
{
    ll a, b;
    cin >> a >> b;
    ll mx = max(a, b);
    ll sm = mx * mx - (mx-1);
    if (mx & 1) {
        sm = sm - (abs(mx - b)) + (abs(mx - a));
    } else {
        sm = sm - (abs(mx - a)) + (abs(mx - b));
    }
    print(sm);
    return;
}
```
