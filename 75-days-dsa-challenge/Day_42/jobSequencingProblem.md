# [Job sequencing problem](https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1)

### Algorithm

1. Sort all jobs in decreasing order of profit.
2. Iterate on jobs in decreasing order of profit.For each job , do the following :

For each job find an empty time slot from deadline to 0. If found empty slot put the job in the slot and mark this slot filled.

### Code

```cpp

struct Job
{
    char id;
    int dead;
    int profit;
};

bool comparison(Job a, Job b)
{
    return (a.profit > b.profit);
}

vector<int> JobScheduling(Job arr[], int n)
{
    vector<int> v;
    sort(arr, arr + n, comparison);
    int mx = arr[0].dead;

    for (int i = 1; i < n; i++)
        mx = max(mx, arr[i].dead);

    int slot[mx + 1];

    for (int i = 0; i <= mx; i++)
        slot[i] = -1;

    int countJobs = 0, jobProfit = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = arr[i].dead; j > 0; j--)
        {
            if (slot[j] == -1)
            {
                slot[j] = i;
                countJobs++;
                jobProfit += arr[i].profit;
                break;
            }
        }
    }
    v.push_back(countJobs);
    v.push_back(jobProfit);
    return v;
}
```

### using disjoint set

-   GFG: [link](https://www.geeksforgeeks.org/job-sequencing-using-disjoint-set-union/)
