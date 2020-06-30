/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */

// @lc code=start
#include<iostream>
#include<string>
#include<map>
using namespace std;
class Solution {
public:
    // string addBinary(string a, string b) {
    //     int x = a;
    // }
    void revert_string(string &s){
        string tmp;
        for(auto it=s.end()-1;it>=s.begin();it--){
            tmp.push_back(*it);
        }
        s = tmp;
    }
    string addBinary(string a, string b) {
        revert_string(a);
        revert_string(b);
        string ans;
        map<char,int> m;
        m['0'] = 0;
        m['1'] = 1;
        map<int,char> n;
        n[0] = '0';
        n[1] = '1';
        int flag = 0;
        if(a.size()<b.size()){
            swap(a,b);
        }
        for(int i=0;i<=b.size();i++){
            if(i==b.size()){
                for(int j=i;j<a.size();j++){
                    int s = m[a[j]] + flag;
                    if(s >= 2){
                        flag = 1;
                        ans.push_back(n[s%2]);
                    }else{
                        flag = 0;
                        ans.push_back(n[s]);
                    }
                }
                if(flag==1){
                    ans.push_back(n[flag]);
                }
                break;
            }
            int s = m[a[i]] + m[b[i]] + flag;
            if(s >= 2){
                flag = 1;
                ans.push_back(n[s%2]);
            }else{
                flag = 0;
                ans.push_back(n[s]);
            }
        }

        revert_string(ans);
        return ans;
    }
};
// @lc code=end

