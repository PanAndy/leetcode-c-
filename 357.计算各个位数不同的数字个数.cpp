/*
 * @lc app=leetcode.cn id=357 lang=cpp
 *
 * [357] 计算各个位数不同的数字个数
 */

// @lc code=start
#include<algorithm>

using namespace std;
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n==0)return 1;
        int first = 10;
        int second = 9 * 9;
        int size = min(n, 10);

        for(int i=2;i<=size;i++){
            first += second;
            second *= (10-i);
        }
        return first;
    }
};
// @lc code=end

