# [Fractional Knapsack Problem](https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1/)

### Algorithm

-   Just sort the items by decreasing order of `value/weight`.
-   Get max portion of item.
-   Use double to not loose precision.
-   If item cannot fit full take its fraction.
-   **Time Complexity: O(n log n)**
-   **Space complexity: O(1)**

### Code

```cpp
struct Item
{
    int value, weight;

    // Constructor
    Item(int value, int weight)
    {
        this->value = value;
        this->weight = weight;
    }
};

bool cmp(struct Item a, struct Item b)
{
    double r1 = (double)a.value / (double)a.weight;
    double r2 = (double)b.value / (double)b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int W, struct Item arr[], int n)
{
    sort(arr, arr + n, cmp);

    int curWeight = 0;
    double finalvalue = 0.0;

    for (int i = 0; i < n; i++)
    {
        if (curWeight + arr[i].weight <= W)
        {
            curWeight += arr[i].weight;
            finalvalue += arr[i].value;
        }
        else
        {
            int remain = W - curWeight;
            finalvalue += arr[i].value * ((double)remain / (double)arr[i].weight);
            break;
        }
    }

    return finalvalue;
}
```
