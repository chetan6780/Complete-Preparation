# [Trailing Zeros](https://cses.fi/problemset/task/1618/)

Your task is to calculate the number of trailing zeros in the factorial `n!`.
For example, `20! = 2432902008176640000` and it has 4 trailing zeros.

### Explanation

-   In factorial `0` will always code from product of `5` and `2`.
-   so, counting them will give us answer, but as we know there will be always more `2` than `5` in factorial. so, we need to just count total `5` in factorial.
-   Remember that powers of `5` will always give extra `5` in factorial.
-   so, we can get count by dividing number by `5`, `25`, `125`, `625` and so on.

### Code

```cpp
// solution 1
void solve()
{
    ll n;
    cin >> n;
    ll count = 0;
    for (ll i = 5; n / i >= 1; i *= 5) {
        count += n / i;
    }
    print(count);
    return;
}

// solution 2
void solve()
{
    ll n;
    cin >> n;
    ll count = 0;
    while (n>5) {
        n /= 5;
        count += n;
    }
    print(count);
    return;
}
```
