# [1041. Robot Bounded In Circle](https://leetcode.com/problems/robot-bounded-in-circle/) 🌟🌟

**No.1 Most asked amazon question of the year 2021**-Leetcode premium/

On an infinite plane, a robot initially stands at `(0, 0)` and faces north. The robot can receive one of three instructions:

-   `"G"`: go straight 1 unit;
-   `"L"`: turn 90 degrees to the left;
-   `"R"`: turn 90 degrees to the right.

The robot performs the instructions given in order, and repeats them forever.

Return true if and only if there exists a circle in the plane such that the robot never leaves the circle.

### Simulation

-   We can simulate the robots movement 4 times and check if it reaches to same location(0,0), if it does return true, else false.
    **or**
-   we can simulate the process 1 time and check if it reaches to same location(0,0) or it changed its directions, if it does return true, else false.
-   **TC: O(N)**
-   **SC: O(1)**

### Code

```cpp
class Solution {
public:
    bool isRobotBounded(string instructions)
    {
        int dirX = 0, dirY = 1;
        int x = 0, y = 0;
        int temp = 0;
        for (auto& d : instructions) {
            if (d == 'G') {
                x += dirX;
                y += dirY;
            } else if (d == 'L') {
                temp = dirX;
                dirX = -dirY;
                dirY = temp;
            } else {
                temp = dirX;
                dirX = dirY;
                dirY = -temp;
            }
        }
        return ((x == 0 && y == 0) || (dirX != 0 || dirY != 1));
    }
};
```
