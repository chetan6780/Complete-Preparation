# [705. Design HashSet](https://leetcode.com/problems/design-hashset/) 🌟

Design a HashSet without using any built-in hash table libraries.

Implement MyHashSet class:

void add(key) Inserts the value key into the HashSet.
bool contains(key) Returns whether the value key exists in the HashSet or not.
void remove(key) Removes the value key in the HashSet. If key does not exist in the HashSet, do nothing.

```cpp
class MyHashSet {
    vector<int> a;

public:
    MyHashSet()
    {
        a.resize(1000001, 0);
    }

    void add(int key)
    {
        a[key] = 1;
    }

    void remove(int key)
    {
        a[key] = 0;
    }

    bool contains(int key)
    {
        return a[key] == 1;
    }
};
```

```cpp
class MyHashSet {
private:
    int sz;
    vector<list<int>> st;

public:
    MyHashSet()
    {
        sz = 100;
        st.resize(sz);
    }

    // hashing function
    int hash(int key)
    {
        return key % sz;
    }

    // returns the iterator to the key in the vector of linked list
    list<int>::iterator search(int key)
    {
        int i = hash(key);
        return find(st[i].begin(), st[i].end(), key);
    }

    // if key present do nothing,else add hash of the key to the linked list of vector.
    void add(int key)
    {
        if (contains(key))
            return;
        int i = hash(key);
        st[i].push_back(key);
    }

    // if key present remove hash of the key from the linked list of vector,else do nothing.
    void remove(int key)
    {
        if (!contains(key))
            return;
        int i = hash(key);
        st[i].erase(search(key));
    }

    // returns true if hash of key present in the linked list of vector,else false.
    bool contains(int key)
    {
        int i = hash(key);
        return search(key) != st[i].end();
    }
};
```
