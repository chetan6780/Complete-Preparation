# [342. Power of Four](https://leetcode.com/problems/power-of-four/) 🌟

Given an integer n, return true if it is a power of four. Otherwise, return false.
An integer n is a power of four, if there exists an integer x such that n == 4x.

### General Solution for any power

-   num should be greater than 0.
-   Divide n by 4 until its possible to divide by 4.
-   if n is 1 return true else false.

### Code

```cpp
class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n>1)while(n%4==0) n/=4;
        return n==1;
    }
};
```

### Bitwise Solution

-   Power of 4, numbers have those 3 common features.
    1. greater than 0.
    2. Second,only have one '1' bit in their binary notation,so we use x&(x-1) to delete the lowest '1',and if then it becomes 0,it prove that there is only one '1' bit.
    3. the only '1' bit should be locate at the odd location,for example,16.It's binary is 00010000.So we can use '0x55555555' to check if the '1' bit is in the right place.With this thought we can code it out easily!(0x55555555 is the hex representation of '1010101010101010101010101010101')

### Code

```cpp
class Solution {
public:
    bool isPowerOfFour(int num) {
        return num > 0 && (num&(num-1)) == 0 && (num & 0x55555555) != 0;
    }
};
```

### MUST READ

-   [Using bitwise operation](<https://leetcode.com/problems/power-of-four/discuss/80457/Java-1-line-(cheating-for-the-purpose-of-not-using-loops)>)
