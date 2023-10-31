# [Tower of hanoi](https://cses.fi/problemset/task/2165)

The Tower of Hanoi game consists of three stacks (left, middle and right) and n round disks of different sizes. Initially, the left stack has all the disks, in increasing order of size from top to bottom.
The goal is to move all the disks to the right stack using the middle stack. On each move you can move the uppermost disk from a stack to another stack. In addition, it is not allowed to place a larger disk on a smaller disk.
Your task is to find a solution that minimizes the number of moves.

### Explanation

-   3 step solution
-   if only one disk, move it from source to destination
-   if more than one disk, move n-1 disks from source to auxillary using destination peg as temp, to get larger disk to destination
-   move n-1 disks from auxillary to destination using source peg as temp, to get larger disk to destination

### Code

```cpp
void towerOfHanoi(int n, int source, int auxillary, int destination)
{
    if (n == 1) {
        cout << source << " " << destination << nl;
        return;
    }
    towerOfHanoi(n - 1, source, destination, auxillary);
    cout << source << " " << destination << nl;
    towerOfHanoi(n - 1, auxillary, source, destination);
    return;
}

void solve()
{
    int n;
    cin >> n;
    cout << pow(2, n) - 1 << nl; // (1 << n) - 1
    towerOfHanoi(n, 1, 2, 3);
    return;
}
```
