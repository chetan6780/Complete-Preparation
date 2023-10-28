# [Two knights](https://cses.fi/problemset/task/1072/)

### Explanation

-   For a n\*n board, there are `n^2` ways to place 1st knight.
-   for 2nd knight, there are `(n^2 - 1)` ways to place it, as it can't be placed on the same square as 1st knight.
-   So, total ways to place 2 knights in n*n board = `n^2 * (n^2 - 1)` .....(1)
-   But, we have to remove the cases where 2 knights attack each other.
-   2 knights can attack each other only in `2*3` or `3*2` board configuration.
-   so, we need to subtract total number of `2*3` and `3*2` board configurations from (1).
-   total number of `2*3` boards in `n*n` board = `(n-1)*(n-2)` (as we can place `2*3` board in `n*n` board in `n-1` rows and `n-2` columns) .....(2)
-   total number of `3*2` boards in `n*n` board = `(n-2)*(n-1)` (as we can place `3*2` board in `n*n` board in `n-2` rows and `n-1` columns) .....(3)
-   total number of `2*3` and `3*2` boards in `n*n` board = `2*(n-1)*(n-2)`.....from (2) and (3)
-   in every `2*3` and `3*2` board, there are only 2 positions where 2 knights can attack each other as explained previously, so we need to multiply `2*(n-1)*(n-2)` by 2.
-   then, total number of ways where 2 knights attack each other = `4*(n-1)*(n-2)` .....(4)
-   our answer = (1) - (4) = total ways to place 2 knights in n\*n board - total ways where 2 knights attack each other
-   final formula for n*n board = `(n^2 * (n^2 - 1)) - (4*(n-1)*(n-2))`

### Code

```cpp
void solve()
{
    ll n;
    cin >> n;
    for (ll i = 1; i <= n; i++) {
        ll ans = ((i * i * (i * i - 1)) / 2) - 4 * (i - 1) * (i - 2);
        print(ans);
    }
    return;
}
```
