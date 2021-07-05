# Generate Binary Numbers 

### Statement
Given a number N. The task is to generate and print all binary numbers with decimal values from 1 to N.

### Pseudo code
1. Create an empty queue of strings 
2. Enqueue the first binary number "1" to queue. 
3. Now run a loop for generating and printing n binary numbers. 
    - Dequeue and store the front of queue in a list. 
    - Append "0" at the end of front item and enqueue it. 
    - Append "1" at the end of front item and enqueue it.
4. Return the list containing the binary numbers.

### Code

```cpp

vector<string> generatePrintBinary(int n)
{
    // Create queue and answer vector
    queue<string> q;
    vector<string> ans;

    // Initially push one in the queue
    q.push("1");

    // while n is not 0 run the loop
    while (n--)
    {
        // store front in temp and pop front
        string temp = q.front();
        q.pop();
        
        // push into the vector
        ans.push_back(temp);

        // first push temp with 0 then with 1
        q.push(temp+'0');
        q.push(temp+'1');
    }
    return ans;
}

```

### References

- GFG: [link](https://www.geeksforgeeks.org/interesting-method-generate-binary-numbers-1-n/)
