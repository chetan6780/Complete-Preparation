# [706. Design HashMap](https://leetcode.com/problems/design-hashmap/)

### Solution

### Code

```cpp
class MyHashMap {
public:
    int arr[1000001];
    MyHashMap() {
        memset(arr,-1,sizeof(arr));
    }

    void put(int key, int val) {
        arr[key]=val;
    }

    int get(int key) {
        return arr[key];
    }

    void remove(int key) {
          arr[key]=-1;
    }
};
```
