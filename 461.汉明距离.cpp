/*
 * @lc app=leetcode.cn id=461 lang=cpp
 *
 * [461] 汉明距离
 */

// @lc code=start
class Solution {
public:
    int hammingDistance(int x, int y) {
        x = x ^ y;
        y = 0;

        while(x){
            x = x & (x-1);
            ++y;
        }
        return y;
    }
};
// @lc code=end

