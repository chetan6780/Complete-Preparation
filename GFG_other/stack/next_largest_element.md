```cpp

vector<long long> nextLargerElement(vector<long long> arr, int n)
{
    vector<long long> v;
    stack<long long> s;

    for (int i = n - 1; i >= 0; i--)
    {
        // if stack is empty
        if (s.empty())
        {
            v.push_back(-1);
        }

        // else if stack not empty and top is greater than arr[i]
        else if (!s.empty() && s.top() > arr[i])
        {
            v.push_back(s.top());
        }

        // else if stack is not empty and top is less than arr[i]
        else if (!s.empty() && s.top() <= arr[i])
        {
            // pop untill we get greater element or stack is empty
            while (!s.empty() && s.top() <= arr[i])
            {
                s.pop();
            }
            // if stack is empty else push top()
            if (s.empty())
            {
                v.push_back(-1);
            }
            else
            {
                v.push_back(s.top());
            }
        }
        // push in stack
        s.push(arr[i]);
    }

    // reverse the vector to get right answers
    reverse(v.begin(), v.end());

    return v;
}
```