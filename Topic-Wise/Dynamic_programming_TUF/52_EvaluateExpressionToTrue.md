# [Evaluate Expression To True](https://www.codingninjas.com/codestudio/problems/problem-name-boolean-evaluation_1214650?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos) 🌟🌟

### Recursive Approach

-   [striver's video](https://www.youtube.com/watch?v=MM7fXopgyjw) for explanation.

```cpp
#include <bits/stdc++.h>
#define ll long long
int mod = 1e9 + 7;
ll f(int i, int j, int isTrue, string& s)
{
    if(i>j) return 0;
    if(i==j){
        if(isTrue) return s[i]=='T';
        else return s[i]=='F';
    }
    ll ways = 0;
    for(int k=i+1; k<=j-1; k+=2){
        ll lt = f(i, k-1, 1, s);
        ll lf = f(i, k-1, 0, s);
        ll rt = f(k+1, j, 1, s);
        ll rf = f(k+1, j, 0, s);
        if(s[k]=='&'){
            if(isTrue) ways += (lt*rt)%mod;
            else ways += ((lt*rf)%mod + (lf*rt)%mod + (lf*rf)%mod)%mod;
        }
        else if(s[k]=='|'){
            if(isTrue) ways += ((lt*rt)%mod + (lt*rf)%mod + (lf*rt)%mod)%mod;
            else ways += (lf*rf)%mod;
        }
        else if(s[k]=='^'){
            if(isTrue) ways += ((lt*rf)%mod + (lf*rt)%mod)%mod;
            else ways += ((lt*rt)%mod + (lf*rf)%mod)%mod;
        }
    }
    return ways%mod;
}
int evaluateExp(string& exp)
{
    return f(0, exp.size()-1, 1, exp);
}
```

### Memoization(top-down)

-   **TC: O(n^3)**
-   **SC: O(n^2)**

```cpp
#include <bits/stdc++.h>
#define ll long long
int mod = 1e9 + 7;
ll f(int i, int j, int isTrue, string& s,vector<vector<vector<ll>>> &dp)
{
    if(i>j) return 0;
    if(i==j){
        if(isTrue) return s[i]=='T';
        else return s[i]=='F';
    }
    if(dp[i][j][isTrue]!=-1) return dp[i][j][isTrue];
    ll ways = 0;
    for(int k=i+1; k<=j-1; k+=2){
        ll lt = f(i, k-1, 1, s,dp);
        ll lf = f(i, k-1, 0, s,dp);
        ll rt = f(k+1, j, 1, s,dp);
        ll rf = f(k+1, j, 0, s,dp);
        if(s[k]=='&'){
            if(isTrue) ways += (lt*rt)%mod;
            else ways += ((lt*rf)%mod + (lf*rt)%mod + (lf*rf)%mod)%mod;
        }
        else if(s[k]=='|'){
            if(isTrue) ways += ((lt*rt)%mod + (lt*rf)%mod + (lf*rt)%mod)%mod;
            else ways += (lf*rf)%mod;
        }
        else if(s[k]=='^'){
            if(isTrue) ways += ((lt*rf)%mod + (lf*rt)%mod)%mod;
            else ways += ((lt*rt)%mod + (lf*rf)%mod)%mod;
        }
    }
    return dp[i][j][isTrue] = ways%mod;
}
int evaluateExp(string& exp)
{
    int n = exp.size();
    vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(n, vector<ll>(2, -1)));
    return f(0, n-1, 1, exp,dp);
}
```

### Tabulation(bottom-up)

-   **TC: O(n^3)**
-   **SC: O(n^2)**

```cpp
#include<bits/stdc++.h>
#define ll long long
int mod = 1e9+7;

int evaluateExp(string & exp) {
    int n= exp.size();
    vector<vector<vector<ll>>> dp(n, vector<vector<ll>> (n, vector<ll> (2, 0)));

    for(int i=0; i<n; i++){
        dp[i][i][1] = exp[i] == 'T';
        dp[i][i][0] = exp[i] == 'F';
    }

    for(int i=n-1; i>=0; i--){
        for(int j=i+1; j<n; j++){
            for(int isTrue=0; isTrue <=1; isTrue++){
                ll ways=0;
                for(int ind =i+1; ind <= j-1; ind=ind+2){
                    ll lT = dp[i][ind-1][1];
                    ll lF = dp[i][ind-1][0];
                    ll rT = dp[ind+1][j][1];
                    ll rF = dp[ind+1][j][0];
                    if(exp[ind] == '&'){
                        if(isTrue) ways = (ways + (lT * rT)%mod)%mod;
                        else ways = (ways + (lT*rF)%mod + (lF*rF)%mod + (lF*rT)%mod)%mod;
                    }
                    else if(exp[ind] == '|'){
                        if(isTrue) ways = (ways + (lT*rT)%mod + (lT*rF)%mod + (lF*rT)%mod)%mod;
                        else ways = (ways + (lF*rF)%mod)%mod;
                    }
                    else{
                        if(isTrue) ways = (ways + (lT*rF)%mod + (lF*rT)%mod)%mod;
                        else ways = (ways + (lT*rT)%mod + (lF*rF)%mod)%mod;
                    }
                }
                dp[i][j][isTrue] = ways;
            }
        }
    }

    return dp[0][n-1][1];
}
```
