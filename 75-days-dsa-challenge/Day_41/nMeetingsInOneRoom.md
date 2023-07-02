### [N meeting in one room](https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1)

### Approach

-   Sort all pairs(Meetings) in increasing order of second number(Finish time) of each pair.
-   Select first meeting of sorted pair as the first Meeting in the room and push it into result vector and set a variable time_limet(say) with the second value(Finishing time) of the first selected meeting.
-   Iterate from the second pair to last pair of the array and if the value of the first element(Starting time of meeting) of the current pair is greater then previously selected pair finish time (time_limit) then select the current pair and update the result vector (push selected meeting number into vector) and variable time_limit.
-   Print the Order of meeting from vector.
- **Time Complexity: O(N log(N))**

### Code

```cpp
struct meeting
{
    int start;
    int end;
    int pos;
};

bool comparator(struct meeting m1, meeting m2)
{
    if (m1.end < m2.end)
        return true;
    else if (m1.end > m2.end)
        return false;
    else if (m1.pos < m2.pos)
        return true;
    return false;
}

void nMeetings(int s[], int e[], int n)
{
    struct meeting meet[n];

    for (int i = 0; i < n; i++)
    {
        meet[i].start = s[i];
        meet[i].end = e[i];
        meet[i].pos = i + 1;
    }
    sort(meet, meet + n, comparator);
    vector<int> ans;

    ans.push_back(meet[0].pos);
    int limit = meet[0].end;

    for (int i = 1; i < n; i++)
    {
        if (meet[i].start > limit)
        {
            limit = meet[i].end;
            ans.push_back(meet[i].pos);
        }
    }
    int l = ans.size();
    for (int i = 0; i < l; i++)
    {
        cout << ans[i] << " ";
    }
}
```

