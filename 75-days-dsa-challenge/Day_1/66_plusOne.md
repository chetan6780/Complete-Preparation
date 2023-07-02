# [66. Plus One](https://leetcode.com/problems/plus-one/) (Easy)

### Solution

-   Start from the end of the vector.
-   maintain a carry every time you add a digit.
-   finally if carry greater than 0 then add it to the star of vector.
-   **TC: O(N)**
-   **SC: O(1)**

### Code

```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int carry = 1;
        for(int i = n-1;i>=0;i--){
            digits[i]+=carry;
            if(digits[i]>9){
                carry = digits[i]/10;
                digits[i]%=10;
            }else{
                carry = 0;
            }
        }
        if(carry>0) digits.insert(digits.begin(),carry);
        return digits;
    }
};
```
