# [832. Flipping an Image](https://leetcode.com/problems/flipping-an-image/) 🌟

Given an n x n binary matrix image, flip the image horizontally, then invert it, and return the resulting image.

To flip an image horizontally means that each row of the image is reversed.

- For example, flipping [1,1,0] horizontally results in [0,1,1].

To invert an image means that each 0 is replaced by 1, and each 1 is replaced by 0.

- For example, inverting [0,1,1] results in [1,0,0].

### O(N^2) Time and O(1) Space

- Use inbuilt reverse() function to revese the vector.
- To Toggle we can use either `y=1-y` or `y^=1`

### Code

```cpp
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for(auto &x:image){
            reverse(x.begin(),x.end());
            for(auto &y:x){
                y^=1;
            }
        }
        return image;
    }
};
```
