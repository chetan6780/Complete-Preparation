# House robber II

This problem is extension of previous problem, so all the methods of previous problem can be applied to solve it with some slight modification.

### Modification

-   Since we cannot choose first and last both if they are adjacent, we can calculate 2 results.
-   first is without including first element.
-   second is without including last element.
-   return max of both the results.

### Code

```cpp
long long int houseRobber(vector<int>& valueInHouse)
{
    int n = valueInHouse.size();
    if(n==1) return valueInHouse[0];
    vector<int> wtf, wtl;
    for(int i = 0; i< n; i++){
        if(i!=0) wtf.push_back(valueInHouse[i]);
        if(i!=n-1) wtl.push_back(valueInHouse[i]);
    }
    long long int withoutFirst = maximumNonAdjacentSum(wtf);
    long long int withoutLast = maximumNonAdjacentSum(wtl);

    return max(withoutFirst,withoutLast);
}
```
