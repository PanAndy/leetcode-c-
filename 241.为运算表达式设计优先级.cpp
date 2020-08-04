/*
 * @lc app=leetcode.cn id=241 lang=cpp
 *
 * [241] 为运算表达式设计优先级
 */

// @lc code=start
class Solution {
public:
    bool isOperation(char c){
        return c=='+' || c=='-' || c=='*';
    }
    vector<int> diffWaysToCompute(string input) {
        vector<int> numList;
        vector<char> opList;
        int num = 0;
        for(int i=0;i<input.size();i++)
        {
            if(isOperation(input[i]))
            {
                numList.push_back(num);
                num = 0;
                opList.push_back(input[i]);
                continue;
            }
            num = num * 10 + input[i] - '0';
        }
        numList.push_back(num);

        int N = numList.size();
        vector<vector<vector<int>>> dp(N, vector<vector<int>>(N, vector<int>()));
        for(int i=0;i<N;i++)
        {
            vector<int> result;
            result.push_back(numList[i]);
            dp[i][i] = result;
        }
        for(int n=2;n<=N;n++)
        {
            for(int i=0;i<N;i++)
            {
                int j = i + n - 1;
                if(j >= N)break;
                vector<int> result;
                for(int s=i;s<j;s++){
                    vector<int> result1 = dp[i][s];
                    vector<int> result2 = dp[s+1][j];
                    for(int x=0;i<result1.size();x++)
                    {
                        for(int y=0;y<result2.size();y++)
                        {
                            char op = opList[s];
                            result.push_back(caculate(result1[x], op, result2[y]));
                        }
                    }
                }
                dp[i][j] = result;
            }
        }
        return dp[0][N-1];
    }
    int caculate(int num1, char c, int num2)
    {
        switch(c){
            case '+':
                return num1 + num2;
            case '-':
                return num1 - num2;
            case '*':
                return num1 * num2;
        }
        return -1;
    }
};
// @lc code=end

