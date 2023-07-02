# [155. Min Stack](https://leetcode.com/problems/min-stack/description/)

---

### TIP

-   Solving a question to implement stack using stack is possible , but not a good idea.
-   you can use 2 vector, 1 vector, vector of pair or map to implement the stack.

### Time Complexity: O(1) for all the solutions.

### Space Complexity: Extra O(N) Space used.

---

### Using 2 Vectors

-   We maintain 2 vectors, 1 for stack implementation and another for min stack. push `INT_MAX` to min stack in declaration.
-   `push` operation:
    -   push element to stack.
    -   push min element to min stack.
-   `pop` operation:
    -   pop element from stack.
    -   pop min element from min stack.
-   `top` operation:
    -   return top element from stack.
-   `getMin` operation:
    -   return top element from min stack.

### Code

```cpp
class MinStack {
    vector<int> st;
    vector<int> mnStack;
public:
    MinStack() {
        mnStack.push_back(INT_MAX);
    }

    void push(int val) {
        st.push_back(val);
        mnStack.push_back(min(val,mnStack.back()));
    }

    void pop() {
        st.pop_back();
        mnStack.pop_back();
    }

    int top() {
        return st.back();
    }

    int getMin() {
        return mnStack.back();
    }
};
```

### Using 1 vector

-   Instead of 2 vectors, we can use 1 vector to implement the stack.
-   `push` operation:
    -   if minElement is greater or equal to val, push minElement to stack and update minElement to val.
    -   then push val in the stack.
-   `pop` operation:
    -   pop the top of the stack.
    -   if top is equal to minElement, minElement will be top(next top) of the stack and pop the top(next top) from stack.

### Code

```cpp
class MinStack{
    vector<int> st;
    int minElem;

public:
    MinStack() { minElem = INT_MAX; }

    void push(int val){
        if(val<=minElem){
            st.push_back(minElem);
            minElem = val;
        }
        st.push_back(val);
    }

    void pop(){
        int top = st.back();
        st.pop_back();
        if (top == minElem){
            minElem = st.back();
            st.pop_back();
        }
    }

    int top() { return st.back(); }

    int getMin() { return minElem; }
};

```

### Using vector of pair

-   Self explanatory code

### Code

```cpp
class MinStack{
    vector<pair<int, int>> st;
public:
    MinStack() {}

    void push(int val){
        if (st.empty())
            st.push_back({val, val});
        else
            st.push_back({val, min(st.back().second, val)});
    }

    void pop() { st.pop_back(); }

    int top() { return st.back().first; }

    int getMin() { return st.back().second; }
};
```
