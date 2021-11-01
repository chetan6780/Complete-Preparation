# [56. Merge Intervals](https://leetcode.com/problems/merge-intervals/) 🌟🌟

Given an array of intervals where intervals[i] = [start i, end i], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

### O(N^2) Time Solution

- Brute force.
- sort the intervals by start time.(NlogN Time)
- for every interval i, check if it overlaps with any interval j.
- if it does, merge the two intervals.
- if it doesn't, add it to the result.

### O(NlogN) Time O(N) Space Solution

- Check for invalid case.
- Sort the intervals by start time.
- Take first pair of interval.
- iterate over intervals and check if they overlap or not.
- if they overlap, then change temp pair to `max(temp[1],x[1])`.
- else push temp pair to result and change temp pair to x.

```cpp
class Solution{
public:
	vector<vector<int>> merge(vector<vector<int>> &intervals){
		int n = intervals.size();
		vector<vector<int>> ans;
		if (n == 0) return ans;

		sort(intervals.begin(), intervals.end());
		vector<int> temp = intervals[0]; // first pair

		for (auto &x : intervals){
			if (temp[1] >= x[0]){
				temp[1] = max(temp[1], x[1]);
			}
			else{
				ans.push_back(temp);
				temp = x;
			}
		}
		ans.push_back(temp);
		return ans;
	}
};
```

### O(NlogN) Time O(1) Space Solution

- If we not consider the vector ans, which we have to return this problem can be solved without using temp vector.
- We can simply use vector.back and do the operations on it.

```cpp
class Solution{
public:
	vector<vector<int>> merge(vector<vector<int>> &intervals){
		int n = intervals.size();
		if (n <= 1) return intervals;

		sort(intervals.begin(), intervals.end());
		vector<vector<int>> ans;

		ans.push_back(intervals[0]);
		for (int i = 1; i < n; i++){
			if (ans.back()[1] >= intervals[i][0])
				ans.back()[1] = max(ans.back()[1], intervals[i][1]);
			else
				ans.push_back(intervals[i]);
		}
		return ans;
	}
};
```
