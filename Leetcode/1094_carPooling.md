# [1094. Car Pooling](https://leetcode.com/problems/car-pooling/) 🌟🌟

There is a car with capacity empty seats. The vehicle only drives east (i.e., it cannot turn around and drive west).

You are given the integer capacity and an array trips where trip[i] = [numPassengers i, from i, toi] indicates that the ith trip has numPassengers i passengers and the locations to pick them up and drop them off are from i and toi respectively. The locations are given as the number of kilometers due east from the car's initial location.

Return true if it is possible to pick up and drop off all passengers for all the given trips, or false otherwise.

### Approach

-   for every trip we add the passengers in the car from destination and drop them off to the destination.
-   After these actions we check in our stops array(hashmap) if the car has enough empty seats.
-   If it does return true, else we return false.

### Code

```cpp
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity){
        int stops[1001] = {};
        for (auto t : trips) {
            int from = t[1], to = t[2];
            stops[from] += t[0], stops[to] -= t[0];
        }
        for (auto i = 0; capacity >= 0 && i < 1001; i++)
            capacity -= stops[i];
        return capacity >= 0;
    }
};
```
