/*
 * @lc app=leetcode.cn id=367 lang=cpp
 *
 * [367] 有效的完全平方数
 */

// @lc code=start
class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num<2)return true;
        long long left = 2;
        long long right = num/2;
        long long x, guessSquqred;

        while (left<=right)
        {
            x = left + (right - left) / 2;
            guessSquqred = x * x;
            if(guessSquqred == num)
            {
                return true;
            }else if(guessSquqred < num)
            {
                left = x + 1;
            }else{
                right = x - 1;
            }
        }
        return false;        
    }
};
// @lc code=end

