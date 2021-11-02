# [Sieve of Eratosthenes](https://www.geeksforgeeks.org/sieve-of-eratosthenes/)

- **Time Complexity: O(n\*log(log(n)))**
- **Auxiliary Space: O(n)**

### Code

```cpp
ll N = 1e7 + 5;
vector<bool> isPrime(N, true);
void sieveOfEratosthenes(){
    isPrime[0] = isPrime[1] = false;
    for (ll i = 2; i * i <= N; i++){
        if (isPrime[i]){
            for (ll j = i * i; j <= N; j += i){
                isPrime[j] = false;
            }
        }
    }
}
```

---

### Q.[SPOJ - TDKPRIME - Finding the Kth Prime](https://www.spoj.com/problems/TDKPRIME/)

```cpp
vi primes;
vb isPrime(90000001,true);

void sieve(){
    int maxN = 90000000;
    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i*i <= maxN; i++){
        if(isPrime[i]){
            for(int j = i * i; j <= maxN; j += i){
                isPrime[j] = false;
            }
        }
    }
    for(int i = 2; i <= maxN; i++){
        if(isPrime[i]){
            primes.pb(i);
        }
    }
}

void solve(){
    int n;
    cin >> n;
    deb(primes[n - 1]);
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    sieve();
    while (t--){
        solve();
    }
    return 0;
}
```
