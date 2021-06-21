// * general ------------------------------------------------------------------------------------------
// tie(w,x,y,z) = make_tuple(10,20,30,40) --> w=10,x=20,y=30,z=40
// unordered_set,unordered_map are faster than set and maps.
// set-->uses self balancing binery search trees therefore O(nlogn)
// unordered_set-->uses hashing therefore O(1) same for the map and unordered_map
// auto keyword can be used for declaring variables, it automatically set the type of that variable.
// lower_bound = find >= elem , upper_bound = find > element
// when we want to find element equal to we use lower_bound else upper_bound

// * Faster operations ---------------------------------------------------------------------------------
// a>>1 == a//2
// a<<1 == a*2
// if (a&1)==0 --> even 
// if (a&1)==1 --> odd , make sure you use the brackets.
// swap --> a=a^b;b=a^b;a=a^b;  
// We should use emplace_back to push pair in vector insteed of pb(mp()) or pb({})

// * Bit magic / Bit mask -------------------------------------------------------------------------------
// __builtin_popcount(n) --> returns no. of set bits in n.
// find i th bit --> ( n & (1<<i))==0 then ith bit is 0 else 1 --> mask = &(1<<i) for find
// set i th bit  --> ( n | (1<<i)) then ith bit set to 1       --> mask = |(1<<i) for set-1
// clear ith bit --> ( n & ~(1<<i)) then ith bit set to 0      --> mask = & ~(1<<i) for set-0 
// (n&(n-1)) used in many ways -->
// 1. It reduces last set bit to 1 ex.1101->1100->1000->0000 then we can count no of set bit by cnt.
// 2. we can find if a number is power of 2 or not -->if (n&(n-1))==0 then it is power of two else not.

// * Strings --------------------------------------------------------------------------------------------
// temp.find(B) != string::npos , find B is in string or not.

// * vectors --------------------------------------------------------------------------------------------
// v.erase(iterator) to delete elem while traversing in vector.Rememder to do it--.
// auto it = lower_bound(v.begin(), v.end(),elem);
// int ind = it - v.begin(); OR = it - v;

// * set -------------------------------------------------------------------------------------------------
// auto it = s.lower_bound(elem);
// int elem = *it;

// * map -------------------------------------------------------------------------------------------------
