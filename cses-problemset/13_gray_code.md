# [Gray Code](https://cses.fi/problemset/task/2205/)

A Gray code is a list of all 2^n bit strings of length n, where any two successive strings differ in exactly one bit (i.e., their Hamming distance is one).
Your task is to create a Gray code for a given length n.

### Explanation

-   Start with 'n' and create an initial vector containing "0" and "1" as the base cases.
-   Iterate to generate Gray codes for 'n' by doubling the number of codes in each step.
-   Mirror the existing codes.
-   Prepend "0" to the left half and "1" to the right half of the codes.
-   Repeat these steps iteratively until all Gray codes for 'n' are generated.
-   Print the generated Gray codes.

### code

```cpp
void solve()
{
    int n;
    cin >> n;

    vector<string> ans;
    ans.push_back("0");
    ans.push_back("1");
    for (int i = 2; i < (1 << n); i <<= 1) {
        for (int j = i - 1; j >= 0; j--) {
            ans.push_back(ans[j]);
        }
        for (int j = 0; j < i; j++) {
            ans[j] = "0" + ans[j];
        }
        for (int j = i; j < 2 * i; j++) {
            ans[j] = "1" + ans[j];
        }
    }
    for (auto& i : ans) {
        print(i);
    }

    return;
}

```
