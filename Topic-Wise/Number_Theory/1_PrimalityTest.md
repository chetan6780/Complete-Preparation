# [Primality Test](https://www.codechef.com/problems/PRB01)

Given a number check if it is prime or not.

### O(N) Approach

- Brute force.
- for all i from 2 to n we check if it is divisible by i or not.
- if it is divisible by any number then it is not prime.else its a prime number.

### O(sqrt(n)) Solution

- if `a*b=n` then `a<sqrt(n)` and `b>sqrt(n)`
- So we can reduce our loop only upto `sqrt(n)`.

### Code

```cpp
bool isPrime(int n){
    if (n == 1) return false;

    for (int i = 2; i * i <= n; i++){
        if (n % i == 0) 
            return false;
    }
    return true;
}
```
