# Tower of Hanoi

Tower of Hanoi is a mathematical puzzle where we have three rods and n disks. The objective of the puzzle is to move the entire stack to another rod, obeying the following simple rules:

1. Only one disk can be moved at a time.
2. Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack i.e. a disk can only be moved if it is the uppermost disk on a stack.
3. No disk may be placed on top of a smaller disk.

### Algorithm

- if only one disk remaining, move it from source to destination.
- Recursively move 1 disk less (n-1 disks) from source to temporary tower using destination tower.
- Move n'th disk from source to destination using temporary tower.
- Recursively move 1 disk less (n-1 disks) from temporary tower to destination tower using source tower.

### Code

```cpp

void towerOfHanoi(int n, char source, char dest, char temp)
{
    if (n == 1)
    {
        cout << "Move disk 1 from " << source << " to " << dest << endl;
        return;
    }
    towerOfHanoi(n - 1, source, temp, dest);

    cout << "Move disk " << n << " from " << source << " to " << dest << endl;

    towerOfHanoi(n - 1, temp, dest, source);

    return;
}
```

### References

- GFG: [Tower of Hanoi](https://www.geeksforgeeks.org/c-program-for-tower-of-hanoi/)
- YouTube: [Tower of Hanoi](https://www.youtube.com/watch?v=l45md3RYX7c&t=1165s)
