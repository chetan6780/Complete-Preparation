# C++ Tips and Tricks 😀

---

## General ⚙️

- `tie(w,x,y,z) = make_tuple(10,20,30,40)` :- w=10,x=20,y=30,z=40
- `unordered_set`,`unordered_map` are **faster** than `set` and `maps`.
- `set` uses _self balancing binery search trees_ therefore **O(nlogn)**.
- `unordered_set` uses _hashing_ therefore **O(1)** same for the `map` and `unordered_map`.
- `auto` keyword can be used for declaring variables, it automatically set the type of that variable.
- `lower_bound` : find >= elem , `upper_bound` : find > element
- when we want to find element equal to we use lower_bound else upper_bound
- `is_sorted` : Returns `true` if the container is sorted else `false`.
- In Global we can declare array of `bool` upto `10^8` or `int` array upto `10^7`.
- In Local we can declare array of `bool` upto `10^7` or `int` array upto `10^6`.

---

## Faster operations ⏩⏩

- `a>>1` == divide a by 2.
- `a<<1` == multiply a with 2.
- if `(a&1)==0` == number is even.
- if `(a&1)==1` == number is odd, _make sure you use the brackets_.
- swap numbers == `a=a^b;b=a^b;a=a^b;`
- We should use `emplace_back` to push `pair` in `vector` insteed of `pb(mp())` or `pb({})`.

---

## Bit magic / Bit mask 0️⃣1️⃣

- `__builtin_popcount(n)` == returns no. of set bits in n.
- find i'th bit --> `(n & (1<<i))==0` then ith bit is 0 else 1.
- set i'th bit --> `( n | (1<<i))` then ith bit set to 1.
- clear i'th bit --> `(n & ~(1<<i))` then ith bit set to 0
- mask = `&(1<<i)` for find.
- mask = `|(1<<i)` for set-1.
- mask = `& ~(1<<i)` for set-0.
- `(n&(n-1))` used in many ways :
  1. It reduces last set bit to 1. `ex.1101->1100->1000->0000` then we can **_count no of set bits_** by count.
  2. we can find if a number is **_power of 2_** or not -->if `(n&(n-1))==0` then it is power of two else not.

---

## std::string 🧵

- `temp.find(B) != string::npos`, find B is in string or not.
- `s.insert(pos, string)`, insert string at pos position.

---

## std::vector 🔼

- `v.erase(iterator)` to delete elem while traversing in vector. _Remember to do it--_.
- `auto it = lower_bound(v.begin(), v.end(),elem);`
- `int index = it - v.begin();` OR `index = it - v;`

---

## std::set 🦄

- `auto it = s.lower_bound(elem);`
- `int elem = *it;`
- `s.count()` returns 1 if element is present in set else 0.
- _NOTE:_ for vector and other containers which contains duplicate elements count returns count of the number.

---

## std::map 🍁

- `mp.count()` returns 1 if element is present in map else 0.
- _NOTE:_ for vector and other containers which contains duplicate elements it returns count of the number.

---

## Other tips 🍹

1. We can use dec,hex,oct to print numbers in different bases.

   ```cpp
   // bitset<bitcnt>(num)
   cout << bitset<12>(n) << "\n"; // Binary
   cout << oct << n << "\n"; // Octal
   cout << hex << n << "\n"; // Hexadecimal
   cout << dec << n << "\n"; // Decimal-normal
   ```

2. `std::minmax_element` == returns `pair{minelement, maxelement}`

   ```cpp
   vector<int> x = {1, 2, 3, 4};
   auto it = minmax_element(all(x));
   cout << *it.first << ' ' << *it.second << endl;
   ```

   ```
   output:
   1 4
   ```

3. `is_palindrome` function using `std::equal`.

   ```cpp
   bool is_palindrome(string s) {
       return equal(all(s) - s.size() / 2, s.rbegin());
   }
   ```

---

©️ prepared by [_chetan6780_](https://github.com/chetan6780) 
