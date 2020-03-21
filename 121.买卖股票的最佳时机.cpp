/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_p=0;
        if(prices.size()==0)return max_p;
        for(int i=0;i<prices.size()-1;++i)
        {
            for(int j=i+1;j<prices.size();++j){
                if(max_p<prices[j]-prices[i]){
                    max_p = prices[j]-prices[i];
                }
            }
        }
        return max_p;
    }
};
// @lc code=end

