# [Coin Piles](https://cses.fi/problemset/task/1754/)

You have two coin piles containing a and b coins. On each move, you can either remove one coin from the left pile and two coins from the right pile, or two coins from the left pile and one coin from the right pile.
Your task is to efficiently find out if you can empty both the piles.

### Explanation

-   Suppose there are two piles with `a` and `b` coins respectively.
-   there are two options for us:
    -   take `2*x` coins from first pile and ` y`` coins from second pile  `a=2\*x+y`.
    -   take `x` coins from first pile and `2*y` coins from second pile `b=2*y+x`.
-   solving these two equations we get `x=(2*a-b)/3` where `(2*a-b)>0` and `y=(2*b-a)/3` where `(2*b-a)>0`.
-   just check this condition if its true then print "YES" else "NO".
-   NOTE: `condition = ((2*a-b)%3==0 && (2*b-a)%3==0 && (2*a-b)>=0 && (2*b-a)>=0)`, `a` and `b` are inputs
