/*
 * @lc app=leetcode.cn id=583 lang=cpp
 *
 * [583] 两个字符串的删除操作
 */

// @lc code=start
class Solution {
public:


    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                // if(i == 0 || j == 0)continue;
                if(word1[i-1] == word2[j-1])
                {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return m + n - 2 * dp[m][n];
    }
    // int minDistance(string word1, string word2) {
    //     if(word1==word2)return 0;
    //     map<char, int> m1;
    //     map<char, int> m2;

    //     int m = word1.size();
    //     int n = word2.size();
    //     if(m==0)return n;
    //     if(n==0)return m;

    //     int cnt = 0;
        
    //     int i = 0;
    //     int j = 0;

    //     while(i+1!=m || j+1!=n)
    //     {
    //         if(word1[i] == word2[j]){
    //             cnt++;
    //             if(i+1 < m)
    //                 i++;
    //             if(j+1 < n)
    //                 j++;
    //             m1.clear();
    //             m2.clear();
    //             continue;
    //         }
    //         if(m2.count(word1[i]))
    //         {
    //             cnt++;
    //             j = m2[word1[i]];
    //             m2.clear();
    //             m1.clear();
    //         }else if(m1.count(word2[j]))
    //         {
    //             cnt++;
    //             i = m1[word2[j]];
    //             m1.clear();
    //             m2.clear();
    //         }else{
    //             m1[word1[i]] = i;
    //             m2[word2[j]] = j;
    //         }
    //         if(i+1 < m)
    //             i++;
    //         if(j+1 < n)
    //             j++;
    //     }
    //     // cout<<cnt<<endl;
    //     int ans = m + n - 2 * cnt;
    //     return ans;
    // }
};
// @lc code=end

