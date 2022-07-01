# [1710. Maximum Units on a Truck](https://leetcode.com/problems/maximum-units-on-a-truck/) 🌟

You are assigned to put some amount of boxes onto one truck. You are given a 2D array boxTypes, where boxTypes[i] = [numberOfBoxesi, numberOfUnitsPerBoxi]:

-   numberOfBoxesi is the number of boxes of type i.
-   numberOfUnitsPerBoxi is the number of units in each box of the type i.

You are also given an integer truckSize, which is the maximum number of boxes that can be put on the truck. You can choose any boxes to put on the truck as long as the number of boxes does not exceed truckSize.

Return the maximum total number of units that can be put on the truck.

### Greedy

-   It is a greedy problem.
-   We just choose the box with the largest number of units per box.
-   We keep adding boxes and **units\*boxes** until the total number of boxes on the truck is greater than truckSize.
-   finally, if we cannot take all boxes we take remaining required number of boxes and stop there.
-   Return the count of total units.
-   **TC:O(N log N)**
-   **SC:O(1)**

### Code

```cpp
class Solution {
    static bool comp(vector<int>& a, vector<int>& b)
    {
        return a[1] > b[1];
    }
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int ts)
    {
        int n = boxTypes.size();
        sort(boxTypes.begin(), boxTypes.end(), comp);
        int cnt = 0;
        for (auto x : boxTypes) {
            if (x[0] <= ts) {
                cnt += x[0] * x[1];
                ts -= x[0];
            } else {
                cnt += ts * x[1];
                break;
            }
        }
        return cnt;
    }
};
```
