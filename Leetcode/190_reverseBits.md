# [190_reverseBits](https://leetcode.com/problems/reverse-bits/) 🌟

Reverse bits of a given 32 bits unsigned integer.

Note:

- Note that in some languages, such as Java, there is no unsigned integer type. In this case, both input and output will be given as a signed integer type. They should not affect your implementation, as the integer's internal binary representation is the same, whether it is signed or unsigned.
- In Java, the compiler represents the signed integers using 2's complement notation. Therefore, in Example 2 above, the input represents the signed integer -3 and the output represents the signed integer -1073741825.

### Using lsb 

- `n&1` will give us lsb.
- we will shift lsb to left by `31-i` bits and it will be our reverseLsb.
- we will or reverseLsb with result.
- shift n by 1 to right.
- [Reference Video](https://www.youtube.com/watch?v=LJiMk8lPJNc)

### Code

```cpp
class Solution{
public:
	uint32_t reverseBits(uint32_t n){
		int res = 0;
		for (int i = 0; i < 32; i++){
			int lsb = n & 1;
			int reverseLsb = lsb << (31 - i);
			res |= reverseLsb;
			n = n >> 1;
		}
		return res;
	}
};
```
