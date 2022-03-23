# [991. Broken Calculator](https://leetcode.com/problems/broken-calculator/) 🌟🌟

There is a broken calculator that has the integer startValue on its display initially. In one operation, you can:

-   multiply the number on display by 2, or
-   subtract 1 from the number on display.

Given two integers startValue and target, return the minimum number of operations needed to display target on the calculator.

### Greedy Solution

-   Very intuitive solution. we can just think reverse of the problem statement.
-   we will start from target and divide it when it is even else add one init, until target is greater than the starting value.
-   count the total number of times we have to do so.
-   return count + (startValue - target).
-   **TC: O(log target)**
-   **TC: O(1)**

### Code

```cpp
class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int cnt = 0;
        while(target>startValue){
            if(target&1){
                target++;
            }else{
                target/=2;
            }
            cnt++;
        }
        return cnt + (startValue - target);
    }
};
```
