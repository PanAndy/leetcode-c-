/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        if(strs.size()==0)return "";
        if(strs.size()==1)return strs[0];
        int cnt = 0;
        
        int flag = 0;
        while(flag == 0){
            for(int i=0;i<strs.size();i++){
                if(cnt>=strs[0].size()){
                    flag = 1;
                    break;
                }
                if(strs[i][cnt]!=strs[0][cnt]){
                    flag = 1;
                    break;
                }
            }
            cnt++;
        }
        //cout<<cnt-1<<endl;
        return strs[0].substr(0,cnt-1);
    }
};
// @lc code=end

