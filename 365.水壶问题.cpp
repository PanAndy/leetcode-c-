/*
 * @lc app=leetcode.cn id=365 lang=cpp
 *
 * [365] 水壶问题
 */

// @lc code=start
#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<algorithm>
#include<unordered_set>
using namespace std;

using PII=pair<int,int>;
// struct PII{
//     long long first;
//     long long second;
//     PII(){

//     }
//     PII(long long first, long long second):first(first), second(second){}
//     bool operator < (const PII &l) const{
//         return first == l.first ? second < l.second : first < l.first;
//     }
// };
class Solution {
public:

    bool canMeasureWater(int x, int y, int z) {
        if(x+y<z)return false;
        if(x==0||0){
            return z==0 || x+y==z;
        }
        return z%gcb(x,y) == 0;
    }

    int gcb(int x, int y){
        return y==0?x:gcb(y, x%y);
    }
    // bool canMeasureWater(int x, int y, int z) {
    //     queue<PII> stk;
    //     stk.emplace(0, 0);
        
    //     auto hash_function = [](const PII& o){return hash<int>()(o.first) ^ hash<int>()(o.second);};
    //     unordered_set<PII, decltype(hash_function)> seen(0, hash_function);
    //     // set<PII> seen;
    //     while(!stk.empty()){
    //         if(seen.count(stk.front())){
    //             stk.pop();
    //             continue;
    //         }
    //         seen.emplace(stk.front());
    //         PII remain = stk.front();
    //         long long remain_x = remain.first;
    //         long long remain_y = remain.second;
    //         stk.pop();
    //         if(remain_x==z||remain_y==z||remain_y+remain_x==z){
    //             return true;
    //         }

    //         stk.emplace(x, remain_y);
    //         stk.emplace(remain_x, y);
    //         stk.emplace(0, remain_y);
    //         stk.emplace(remain_x, 0);
    //         stk.emplace(remain_x-min(remain_x, y-remain_y), remain_y+min(remain_x, y - remain_y));
    //         stk.emplace(remain_x+min(remain_y, x-remain_x), remain_y-min(remain_y, x-remain_x));
    //     }
    //     return false;
    // }
};
// @lc code=end

