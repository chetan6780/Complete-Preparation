### Minimum Element in Stack using Extra space

### Statement

Design a Data Structure SpecialStack that supports all the stack operations like push(), pop(), isEmpty(), isFull() and an additional operation getMin() which should return minimum element from the SpecialStack

### Implementation

1. **O(n) space**
    * We use another stack to store minimum element. 
    * We can push extra element(mininum element with each element)
2. **O(1) space**
    * We store currupted value in stack so then we can retrive minimun element with it.


### Code
#### With O(n) space

```cpp

stack<int> s, ss;

void push(int a)
{
    s.push(a);

    if (ss.empty() || ss.top() >= a)
        ss.push(a);

    return;
}

int pop()
{
    if (s.empty())
        return -1;

    int ans = s.top();
    s.pop();

    if (ss.top() == ans)
        ss.pop();

    return ans;
}

int getMin()
{
    if (ss.empty())
        return -1;

    return ss.top();
}
```

#### Another Approach with O(n) space
**
```cpp

stack<int> s;
int minElem = INT_MAX;


int getMin()
{
    if (s.empty())
        return -1;
    return s.top();
}
/*returns poped element from stack*/
int pop()
{
    if (s.empty())
        return -1;
    s.pop();

    int temp = s.top();
    s.pop();
    if (!s.empty())
        minElem = s.top();
    return temp;
}
/*push element x into the stack*/
void push(int x)
{
    if (s.empty())
        minElem = INT_MAX;
    if (x < minElem)
        minElem = x;
    s.push(x);
    s.push(minElem);
}
```

#### Minimum Element in Stac**k in O(1) space**

```cpp

stack<int> s;
int minElem = INT_MAX;

int getMin()
{
    if (s.empty())
        return -1;
    return minElem;
}

void push(int x)
{
    if (s.empty())
    {
        s.push(x);
        minElem = x;
    }
    else
    {
        if (x >= minElem)
            s.push(x);
        else
        {
            s.push((2 * x) - minElem);
            minElem = x;
        }
    }
}

void pop()
{
    if (s.empty())
        return;

    else
    {
        if (s.top() >= minElem)
            s.pop();
        else
        {
            minElem = 2 * minElem - s.top();
            s.pop();
        }
    }
}

int top()
{
    if (s.empty())
        return -1;

    else
    {
        if (s.top() >= minElem)
            return s.top();
        else
            return minElem;
    }
}

```

### References

**With O(n) space:**
- Youtube: [link](https://www.youtube.com/watch?v=asf9P2Rcopo&list=PL_z_8CaSLPWdeOezg68SKkeLN4-T_jNHd&index=10)

**With O(1) space:**
- Youtube: [link](https://www.youtube.com/watch?v=ZvaRHYYI0-4&list=PL_z_8CaSLPWdeOezg68SKkeLN4-T_jNHd&index=11)
- GFG: [link](https://www.geeksforgeeks.org/design-a-stack-that-supports-getmin-in-o1-time-and-o1-extra-space/)
