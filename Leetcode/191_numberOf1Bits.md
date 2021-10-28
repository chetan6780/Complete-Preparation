# [[Python] n & (n-1) trick + even faster, explained](https://leetcode.com/problems/number-of-1-bits/) 🌟

### Using \_\_builtin_popcount

```cpp
class Solution {
public:
    int hammingWeight(uint32_t n) {
        return (__builtin_popcount(n));
    }
};
```

### Using n=n&(n-1) trick

- Each time of "n &= n - 1", we delete one '1' from n.

```cpp
int hammingWeight(uint32_t n){
    int res = 0;
    while(n){
        n &= n - 1;
        ++ res;
    }
    return res;
}
```

### READ:

- [[Python] n & (n-1) trick + even faster, explained](<https://leetcode.com/problems/number-of-1-bits/discuss/1044775/Python-n-and-(n-1)-trick-%2B-even-faster-explained>)
- [Short code of C++, O(m) by time, m is the count of 1's, and another several method of O(1) time](<https://leetcode.com/problems/number-of-1-bits/discuss/55120/Short-code-of-C%2B%2B-O(m)-by-time-m-is-the-count-of-1's-and-another-several-method-of-O(1)-time>)
