# [Unique Path II](https://www.codingninjas.com/codestudio/problems/maze-obstacles_977241?leftPanelTab=0) 🌟🌟

-   This Problem is same as previous unique path problem, But here we need to add one condition for -1 element.
-   If we encounter -1 element then we can't go further in that direction, so we return 0.
-   write `If(mat[i][j]==-1) return 0;` after checking if indexes are not out of bound.
-   All solution passes with this extra case.
