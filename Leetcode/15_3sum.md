# [15. 3Sum](https://leetcode.com/problems/3sum/) 🌟🌟

Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

### O(N^3 Log m) Brute force

-   Travel all the triplets which sums to 0.
-   Pseudo code

```
    for(i=0,n-1)
        for(j=i+1,n-1)
            for(k=j+1,n-1)
                a+b+c==0, cnt++
```

-   To get unique triplets, we can use set data structure.
-   **TC: O(N^3 Log m)**, N^3 for for loop and Log M for inserting unique triplets in the set.
-   **SC: O(M)**, M is all unique triplets.

### O(N^2 Log M) Time and O(N)+O(M) Space

-   we can run 2 for loops for a and b.
-   store c in hashmap with its frequency
-   while running loops we have to decrease frequency of a and b inorder to find unique c.
-   then we find c=-(a+b) in the hashmap.
-   store the 3 numbers in sorted order in set so we will not have duplicates.
-   **TC: O(N^2 Log M)**, O(N^2) for 2 loops, Log(M) for inserting in set.
-   **SC: O(N)+O(M)**, O(N) for map and O(M) For set.

### Two pointers.

-   Sort the array.
-   Fix a and you just need to find b+c=-a which is two sum problem.
-   To not get duplicates we increment pointer in such way that they are not equal to their previous values.
-   **TC:O(N\*N)**
-   **SC:O(M)**, M is the number of triplets.

```cpp
class Solution{
public:
	vector<vector<int>> threeSum(vector<int> &nums){
		sort(nums.begin(), nums.end());
		vector<vector<int>> res;

		int n = nums.size();
		for (int i = 0; i < n - 2; i++){
			if (i == 0 || (i > 0 && nums[i] != nums[i - 1])){
				int lo = i + 1, hi = n - 1, sum = 0 - nums[i];

				while (lo < hi){
					if (nums[lo] + nums[hi] == sum){

						vector<int> temp;
						temp.push_back(nums[i]);
						temp.push_back(nums[lo]);
						temp.push_back(nums[hi]);
						res.push_back(temp);

						while (lo < hi && nums[lo] == nums[lo + 1]) lo++;
						while (lo < hi && nums[hi] == nums[hi - 1]) hi--;

						lo++,hi--;
					}
					else if (nums[lo] + nums[hi] < sum) lo++;
					else hi--;
				}
			}
		}
		return res;
	}
};
```
