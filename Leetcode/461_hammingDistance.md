# [461. Hamming Distance](https://leetcode.com/problems/hamming-distance/) 🌟

The **Hamming distance** between two integers is the number of positions at which the corresponding bits are different.

Given two integers `x` and `y`, return the `Hamming distance` between them.

### Original Post - [4 Solutions](https://leetcode.com/problems/hamming-distance/discuss/1585474/C%2B%2BPython-4-Simple-Solutions-w-Explanations-or-XOR-and-Brian-Kernighan-method)

### Converting Binary Form to String/Array & Iterating

-   The most basic way one could solve this question is by simply taking the number, converting them to binary form's string / array and iterating over it to find the number of positions at which bits are different.
-   **TC : O(N)**, where `N` is the `number of bits` in the given input numbers
-   **SC : O(N)**, required to store the input number's binary form.

```cpp
class Solution {
public:
    int hammingDistance(int x, int y) {
        bitset<32> xb(x), yb(y);
        int ans = 0;
        for(int i = 0; i < 32; i++)
            ans += (xb[i] != yb[i]);
        return ans;
    }
};
```

### Iterating & Comparing each Bit

-   We can also iterate over each bit of the given numbers manually and then compare the bits at each position.
-   To check if the `ith` bit of a number `x` is set, we can perform - `(x >> i) & 1`.
-   If the bit differ at a given position, we increment the count of hamming distance.
-   **TC : O(N)**, to iterate over each bit of the number.
-   **SC : O(1)**, No extra space required.

```cpp
class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans = 0;
        for(int i = 0; i < 32; i++)
            ans += ((x >> i & 1) != (y >> i & 1));
        return ans;
    }
};
```

### XOR & count bits

-   We can XOR x and y and count the number of set bits in the result.
-   To count the number of set bits we can use these inbuilt options:
    ```cpp
    ans = bitset<32>(Xor).count()
    ans = __builtin_popcount(Xor);
    ans = popcount(Xor)            // only since C++20
    ```
-   OR below is code to do it manually.
-   **TC : O(N)**, to iterate over each bit of the number.
-   **SC : O(1)**, No extra space required.

```cpp
class Solution {
public:
    int hammingDistance(int x, int y) {
        int Xor = x ^ y, ans = 0;
        for(int i = 0; i < 32; i++)
            ans += ((Xor & (1 << i)) != 0);
        return ans;
    }
};
```

### Brian-Kernighan's method

-   We can use Brian Kernighan's method to count the number of set bits in the XOR of the two numbers.
-   Take a XOR of x and y.
-   Clear(unset) the rightmost bit by `n & (n - 1)` until xor becomes 0 and increment the count each time.
-   **TC : O(K)**, where K is the hamming distance between given numbers. This assume XOR operation as O(1)
-   **SC : O(1)**, No extra space required.

```cpp
class Solution {
public:
    int hammingDistance(int x, int y) {
        int XOR = x ^ y, ans = 0;
        while(XOR) {
            XOR &= XOR-1; // n&(n-1) clears the rightmost set bit
            ans++;
        }
        return ans;
    }
};
```

### 💡 Note:

1. The number of bits `N` for this problem is fixed to `32`. So, strictly speaking, the time complexity of 1st three solutions is `O(N) = O(32) = O(1)`. But to differentiate between time complexities of 1st three and last approach, I have denoted them as `O(N)`.
2. It's likely that if you got such a question during an interview, you will probably be expected to come up with an approach similar to this one. This approach performs the least number of loops to find the number of set bits in a number which is equal to the number of set bits in the number itself.
