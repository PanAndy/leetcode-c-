/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
class Solution {
public:

    int maxProfit(vector<int>& prices) {
        int max_f=0;
        for(int i=0;i<prices.size()-1;++i)
        {
            if(prices[i+1]-prices[i]>0)
            {
                max_f += (prices[i+1]-prices[i]);
            }
        }
        // if(prices[prices.size()-1]-prices[prices.size()-2]>0)
        // {
        //     max_f += prices[prices.size()-1]-prices[prices.size()-2];
        // }
        return max_f;
    }

    // 只要价格不下跌就一直持有
    // int maxProfit(vector<int>& prices) {
    //     int max_f=0;
    //     if(prices.size()==0)return max_f;
    //     int pos=prices[0];
    //     for(int i=0;i<prices.size()-1;++i){
    //         if(prices[i+1]-prices[i]<0){
    //             max_f += (prices[i]-pos);
    //             pos = prices[i+1];
    //         }

    //     }
    //     if(pos>=0){
    //         max_f+=(prices[prices.size()-1]-pos);
    //     }

    //     return max_f;
    // }
};
// @lc code=end

