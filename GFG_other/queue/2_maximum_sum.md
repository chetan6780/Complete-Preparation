# Maximium Sum

### Statement

You are Given an array A[] of  N Integers and an integer K. You have to choose one element one by one K times. You can only pick the element whose frequency is maximum. The element will be removed from the array after being chosen. If there are many elements with the maximum frequency then you can choose any. Your aim is to maximize the sum.

### Hint
Use priority queue to have the maximum frequency element at the top.

### Algorithm:
```
store the {frequency,element} in the priority queue
while(c<k):
      pair p <- top element of queue
      add to sum
      reduce the frequency by 1
      if frequency greater than 1 then add to queue again
      c=c+1
```

### Code

```cpp

long maximum_sum(int n, vector<int> v, int k)
{
    priority_queue<pair<int, int>> pq;

    // get the element and frequency with unordered_map
    unordered_map<int, int> m1;
    int i;
    long sum = 0;
    for (i = 0; i < n; i++)
    {
        m1[v[i]]++;
    }

    // store the {frequency,element} in the priority queue
    for (auto i : m1)
    {
        pq.push({i.second, i.first});
    }

    int c = 0;
    while (c < k)
    {
        pair<int, int> p;
        
        //pair p <- top element of queue
        p = pq.top();
        pq.pop();

        // add to sum
        sum += p.second;

        // reduce frequency by one
        p.first--;

        // if frequency greater than 1 then add to queue again
        if (p.first)
        {
            pq.push(p);
        }
        c++;
    }
    return sum;
}
```

### References

- GFG Problem: [link](https://practice.geeksforgeeks.org/problems/maximize-the-sum/1/?track=dsa-workshop-1-queue&batchId=308#)
