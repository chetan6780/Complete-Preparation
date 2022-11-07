```json
{
    // Place your snippets for cpp here. Each snippet is defined under a snippet name and has a prefix, body and description.
    // The prefix is what is used to trigger the snippet and the body will be expanded and inserted. Possible variables are:
    // $1, $2 for tab stops, $0 for the final cursor position, and ${1:label}, ${2:another} for placeholders. Placeholders with the
    // same ids are connected.
    // Example:
    //--------------------------------------------------------------
    "Snippet for cp": {
        "prefix": "cpft",
        "body": [
            "#include <bits/stdc++.h>",
            "using namespace std;",
            "#define PI 3.1415926535897932384626",
            "#define mod 1000000007",
            "#define all(x) x.begin(), x.end()",
            "#define rall(x) x.rbegin(), x.rend()",
            "#define mem(a, elem) memset(a, elem, sizeof(a))",
            "#define ff first",
            "#define ss second",
            "#define bpc __builtin_popcount",
            "#define nl '\\n'",
            "#define sp ' '",
            "#define yes cout << \"YES\\n\"",
            "#define no cout << \"NO\\n\"",
            "#define ANS(cnd) cout << ((cnd) ? \"YES\\n\" : \"NO\\n\")",
            "#define print(x) cout << (x) << nl",
            "#define precision(x) cout << fixed << setprecision(x)",
            "#ifdef ONLINE_JUDGE",
            "#define line",
            "#define deb(x)",
            "#define deb2(x, y)",
            "#define deb3(x, y, z)",
            "#else",
            "#define line cerr << \"------------\\n\"",
            "#define deb(x) cerr << (x) << nl",
            "#define deb2(x, y) cerr << #x << \":\" << (x) << sp << #y << \":\" << (y) << nl",
            "#define deb3(x, y, z) cerr << #x << \":\" << (x) << sp << #y << \":\" << (y) << sp << #z << \":\" << (z) << nl",
            "#endif",
            "typedef long long ll;",
            "typedef long double lld;",
            "",
            "void solve()",
            "{",
            "    $0",
            "    return;",
            "}",
            "",
            "int main()",
            "{",
            "    ios_base::sync_with_stdio(false);",
            "    cin.tie(0);",
            "    cout.tie(0);",
            "    ll t = 1;",
            "    cin >> t;",
            "    while (t--)",
            "    {",
            "        solve();",
            "    }",
            "#ifndef ONLINE_JUDGE",
            "    cerr << \"------------\\nTime : \" << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << \"ms\";",
            "#endif",
            "    return 0;",
            "}",
            ""
        ],
        "description": "Snippet for cp"
    },
    //--------------------------------------------------------------
    "simple cpp template": {
        "prefix": "cpp",
        "body": [
            "#include <bits/stdc++.h>",
            "using namespace std;",
            "",
            "int main()",
            "{",
            "    $0",
            "    return 0;",
            "}"
        ],
        "description": "simple cpp template"
    },
    //--------------------------------------------------------------
    "Input an array": {
        "prefix": "arrin",
        "body": [
            "int n;",
            "cin >> n;",
            "",
            "int a[n];",
            "for (int i = 0; i < n; i++)",
            "{",
            "    cin >> a[i];",
            "}"
        ],
        "description": "Input an array"
    },
    //--------------------------------------------------------------
    "Output an array": {
        "prefix": "arrout",
        "body": [
            "for (int i = 0; i < n; i++)",
            "{",
            "\tcout << a[i] << ' ';",
            "}",
            "cout << nl;"
        ],
        "description": "chetan's cpp snippet for output array"
    },
    //--------------------------------------------------------------
    "Input a 2d array": {
        "prefix": "2arrin",
        "body": [
            "int n, m;",
            "cin >> n >> m;\n",
            "int a[n][m];",
            "for (int i = 0; i < n; i++)",
            "{",
            "for (int j = 0; j < m; j++)",
            "cin >> a[i][j];",
            "}"
        ],
        "description": "chetan's cpp snippet for input 2d array"
    },
    //--------------------------------------------------------------
    "2d array output": {
        "prefix": "2arrout",
        "body": [
            "for (int i = 0; i < n; i++)",
            "{",
            "    for (int j = 0; j < m; j++)",
            "        cout << a[i][j];",
            "    cout << nl;",
            "}"
        ],
        "description": "2d array output"
    },
    //--------------------------------------------------------------
    "vector input 1": {
        "prefix": "vin",
        "body": [
            "ll n;",
            "cin >> n;",
            "vector<ll> a(n);",
            "for (ll i = 0; i < n; i++) {",
            "    cin >> a[i];",
            "}"
        ],
        "description": "vector intput 1"
    },
    //--------------------------------------------------------------
    "vector input 2": {
        "prefix": "vin2",
        "body": [
            "ll n;",
            "cin >> n;",
            "vector<ll> a(n);",
            "for (auto &it : a)",
            "    cin >> it;"
        ],
        "description": "vector input 2"
    },
    //--------------------------------------------------------------
    "output vector": {
        "prefix": "vout",
        "body": ["for (auto x : a)", "    cout << x << ' ';", "cout << nl;"],
        "description": "output vector"
    },
    //--------------------------------------------------------------
    "toBinary function": {
        "prefix": "tobin",
        "body": [
            "string toBin(ll n)",
            "{",
            "    string s = bitset<64>(n).to_string();",
            "    const auto los = s.find('1');",
            "    if (los != string::npos)",
            "        return s.substr(los);",
            "    return \"0\";",
            "}"
        ],
        "description": "toBinary function"
    },
    //--------------------------------------------------------------
    "toDecimal function": {
        "prefix": "todec",
        "body": [
            "ll toDec(string n)",
            "{",
            "    string num = n;",
            "    ll dec_value = 0;",
            "    ll base = 1;",
            "    ll len = num.length();",
            "    for (ll i = len - 1; i >= 0; i--)",
            "    {",
            "        if (num[i] == '1')",
            "            dec_value += base;",
            "        base = base * 2;",
            "    }",
            "    return dec_value;",
            "}"
        ],
        "description": "toDecimal function"
    },
    //--------------------------------------------------------------
    "toggle the string": {
        "prefix": "toggle",
        "body": [
            "char *toggleCase(char *a)",
            "{",
            "    for (int i = 0; a[i] != '\\0'; i++)",
            "    {",
            "        // Bitwise EXOR with 32",
            "        a[i] ^= 32;",
            "    }",
            "",
            "    return a;",
            "}"
        ],
        "description": "toggle the string"
    },
    //--------------------------------------------------------------
    "isSubsequence": {
        "prefix": "issubseq",
        "body": [
            "",
            "bool isSubsequence(string s, string t)",
            "{",
            "    int ind = 0;",
            "    if (s.size() == 0)",
            "        return true;",
            "",
            "    for (int i = 0; i < t.size(); i++)",
            "    {",
            "        if (s[ind] == t[i])",
            "        {",
            "            ind++;",
            "            if (ind == s.size())",
            "                return true;",
            "        }",
            "    }",
            "    return false;",
            "}",
            ""
        ],
        "description": "isSubsequence"
    },
    //--------------------------------------------------------------
    "sum of digits in number": {
        "prefix": "sumdigits",
        "body": [
            "ll sumDigits(ll n)",
            "{",
            "    ll sum;",
            "    for (sum = 0; n > 0; sum += n % 10, n /= 10);",
            "    return sum;",
            "}"
        ],
        "description": "sum of digits in number"
    },
    //--------------------------------------------------------------
    "map output": {
        "prefix": "mout",
        "body": [
            "for (auto x : mp)",
            "    cout << x.ff << ':' << x.ss << ' ';",
            "cout << nl;"
        ],
        "description": "map output"
    },
    //--------------------------------------------------------------
    "file input output": {
        "prefix": "fio",
        "body": [
            "#ifdef ONLINE_JUDGE",
            "    freopen(\"input.txt\", \"r\", stdin);",
            "    freopen(\"output.txt\", \"w\", stdout);",
            "#endif "
        ],
        "description": "file input output when we are on online judge // ifndef when we want to use file io in local not in online"
    },
    //--------------------------------------------------------------
    "fast power": {
        "prefix": "fpow",
        "body": [
            "template<typename T> T pow(T a,T b,ll m){T ans=1;while(b > 0){if((b&1)==1)ans=(ans*a)%m;b>>=1;a=(a * a)%m;}return ans % m;}"
        ],
        "description": "fast power"
    },
    //--------------------------------------------------------------
    "fastest gcd alsorithm": {
        "prefix": "fgcd",
        "body": [
            "template <typename T>inline T gcd(T a,T b){T c;while (b){c = b;b = a % b;a = c;}return a;}",
            ""
        ],
        "description": "fastest gcd alsorithm"
    },
    //--------------------------------------------------------------
    "sieve of Eratosthenes": {
        "prefix": "sieve",
        "body": [
            "const int N = 1000000;",
            "vector<bool> sieve(N + 1);",
            "void createSieve(){",
            "    for (int i = 2; i <= N; i++)",
            "        sieve[i] = true;",
            "",
            "    for (int i = 2; i * i <= N; i++){",
            "        if (sieve[i] == true){",
            "            for (int j = i * i; j <= N; j += i)",
            "                sieve[j] = false;",
            "        }",
            "    }",
            "}"
        ],
        "description": "It will return integer vector of prime numbers"
    },
    //--------------------------------------------------------------
    "sort by value in increasing order of values then keys": {
        "prefix": "sortByVal",
        "body": [
            "bool sortByVal(pair<int, int> a, pair<int, int> b)",
            "{",
            "if (a.second == b.second)",
            "return a.first < b.first;",
            "return a.second < b.second;",
            "}"
        ],
        "description": "sort by value in increasing order of values then keys"
    },
    //--------------------------------------------------------------
    "Even->odd increasing order comparator function": {
        "prefix": "eoc",
        "body": [
            "bool comp(ll a, ll b)",
            "{",
            "",
            "    if (a % 2 == 0 && b % 2 == 0)",
            "        return a < b;",
            "",
            "    if (a % 2 != 0 && b % 2 != 0)",
            "        return b < a;",
            "",
            "    if (a % 2 != 0)",
            "        return false;",
            "",
            "    return true;",
            "}"
        ],
        "description": "Even->odd increasing order comparator function"
    },
    //--------------------------------------------------------------
    "Return true if string is palindrome else false": {
        "prefix": "ispal",
        "body": [
            "bool is_palindrome(string s) {",
            "    return equal(all(s) - s.size() / 2, s.rbegin());",
            "}"
        ],
        "description": "Return true if string is palindrome else false"
    },
    //--------------------------------------------------------------
    "modular operations": {
        "prefix": "modi",
        "body": [
            "ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}",
            "ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}",
            "ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}",
            "ll modulo(ll x,ll N) {return (x % N + N) % N;}"
        ],
        "description": "modular operations"
    },
    //--------------------------------------------------------------
    "Snippet for google kickstart": {
        "prefix": "gsn",
        "body": [
            "#include <bits/stdc++.h>",
            "using namespace std;",
            "#define PI 3.1415926535897932384626",
            "#define mod 1000000007",
            "#define all(x) x.begin(), x.end()",
            "#define rall(x) x.rbegin(), x.rend()",
            "#define mem(a, elem) memset(a, elem, sizeof(a))",
            "#define ff first",
            "#define ss second",
            "#define bpc __builtin_popcount",
            "#define nl '\\n'",
            "#define sp ' '",
            "#define yes cout << \"YES\\n\"",
            "#define no cout << \"NO\\n\"",
            "#define ANS(cnd) cout << ((cnd) ? \"YES\\n\" : \"NO\\n\")",
            "#define print(x) cout << (x) << nl",
            "#define precision(x) cout << fixed << setprecision(x)",
            "#ifdef ONLINE_JUDGE",
            "#define line",
            "#define deb(x)",
            "#define deb2(x, y)",
            "#define deb3(x, y, z)",
            "#else",
            "#define line cerr << \"------------\\n\"",
            "#define deb(x) cerr << (x) << nl",
            "#define deb2(x, y) cerr << #x << \":\" << (x) << sp << #y << \":\" << (y) << nl",
            "#define deb3(x, y, z) cerr << #x << \":\" << (x) << sp << #y << \":\" << (y) << sp << #z << \":\" << (z) << nl",
            "#endif",
            "typedef long long ll;",
            "typedef long double lld;",
            "",
            "void solve()",
            "{",
            "    $0",
            "    return;",
            "}",
            "",
            "int main()",
            "{",
            "    ios_base::sync_with_stdio(false);",
            "    cin.tie(0);",
            "    cout.tie(0);",
            "    ll t = 1;",
            "    cin >> t;",
            "    ll cnt = 1;",
            "    while (t--)",
            "    {",
            "        cout << \"Case #\" << cnt++ << \": \";",
            "        solve();",
            "    }",
            "#ifndef ONLINE_JUDGE",
            "    cerr << \"------------\\nTime : \" << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << \"ms\";",
            "#endif",
            "    return 0;",
            "}",
            ""
        ],
        "description": "Snippet for google kickstart"
    },
    //--------------------------------------------------------------
    //---------------------------------------- Short Snippets ----------------------------------------
    //--------------------------------------------------------------
    "vector of int": {
        "prefix": "svi",
        "body": ["vector<int>"],
        "description": "vector of int"
    },
    "vector of ll": {
        "prefix": "svl",
        "body": ["vector<ll>"],
        "description": "vector of ll"
    },
    "vector of string": {
        "prefix": "svs",
        "body": ["vector<string>"],
        "description": "vector of string"
    },
    "vector of char": {
        "prefix": "svc",
        "body": ["vector<char>"],
        "description": "vector of char"
    },
    //--------------------------------------------------------------
    "2d vector of intergers": {
        "prefix": "svvi",
        "body": ["vector<vector<int>>"],
        "description": "2d vector of intergers"
    },
    "2d vector of long long": {
        "prefix": "svvl",
        "body": ["vector<vector<ll>>"],
        "description": "2d vector of long long"
    },
    //--------------------------------------------------------------
    "vector of ll pair": {
        "prefix": "svp",
        "body": ["vector<pair<ll, ll>>"],
        "description": "vector of ll pair"
    }
    //--------------------------------------------------------------
}
```