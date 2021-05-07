// ? https://leetcode.com/problems/sort-colors/
// * https://www.youtube.com/watch?v=oaVa-9wmpns&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=3

// ! used dutch national flag Algorithm
// TC: O(N), SC:O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        // int lo = 0;
        // int hi = nums.size() - 1;
        // int mid = 0;

        // while (mid <= hi)
        // {
        //     switch (nums[mid])
        //     {
        //     case 0:
        //         swap(nums[lo++], nums[mid++]);
        //         break;
        //     case 1:
        //         mid++;
        //         break;
        //     case 2:
        //         swap(nums[mid], nums[hi--]);
        //         break;
        //     }
        // }

        int zer = 0, one = 0, two = 0; // label the end of different colors;
        for (int num : nums)
        {
            if (num == 0)
            {
                nums[two++] = 2;
                nums[one++] = 1;
                nums[zer++] = 0;
            }
            else if (num == 1)
            {
                nums[two++] = 2;
                nums[one++] = 1;
            }
            else if (num == 2)
                two++;
        }
    }
};

int main()
{
    Solution ans;
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    ans.sortColors(nums);

    for (int i = 0; i < n; i++)
        cout << nums[i] << ' ';

    return 0;
}