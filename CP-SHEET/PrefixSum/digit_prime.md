# Digit Prime 
A prime number is a positive number, which is divisible by exactly two different integers. A digit prime is a prime number whose sum of digits is also prime. For example the prime number 41 is a digit prime because 4 + 1 = 5 and 5 is a prime number. 17 is not a digit prime because 1 + 7 = 8, and 8 is not a prime number. In this problem your job is to find out the number of digit primes within a certain
range less than 1000000.

### Approach
In the problem statement we have given that range will be not more than 1000000. So we precomute digit sum vector to solve this problem efficiently.

1. Precompute sieve vector
2. get the sum of digit
3. Precompute digit prime vector
4. In main function, output the v[r] - v[l - 1]


### Code
```cpp
#include <bits/stdc++.h>
using namespace std;

const int N = 1000000;
vector<bool> sieve(N + 1);
void createSieve()
{
    for (int i = 2; i <= N; i++)
        sieve[i] = true;

    for (int i = 2; i * i <= N; i++)
    {
        if (sieve[i] == true)
        {
            for (int j = i * i; j <= N; j += i)
                sieve[j] = false;
        }
    }
}

int sumDigits(int n)
{
    return n == 0 ? 0 : n % 10 + sumDigits(n / 10);
}

vector<int> v(N + 1, 0);
void digitPrime()
{
    createSieve();
    for (int i = 2; i <= N; i++)
    {
        if (sieve[i] && sieve[sumDigits(i)])
            v[i] = v[i - 1] + 1;
        else
            v[i] = v[i - 1];
    }
}

int main()
{
    digitPrime();
    int n;
    cin >> n;

    while (n--)
    {
        int l, r;
        cin >> l >> r;

        cout << v[r] - v[l - 1] << endl;
    }

    return 0;
}
```