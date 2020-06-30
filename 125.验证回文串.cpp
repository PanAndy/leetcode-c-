/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */

// @lc code=start

#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string sgood;
        for(char ch:s)
        {
            if(isalnum(ch))
            {
                sgood+=tolower(ch);
            }
        }
        string sgood_rev(sgood.rbegin(),sgood.rend());
        return sgood==sgood_rev;
    }
    // bool isPalindrome(string s) {
    //     auto i=s.begin(),j=s.end()-1;

    //     while(i<j){
    //         if(isalpha(*i)||isdigit(*i)){
    //             if(isalpha(*i)){
    //                 *i = tolower(*i);
    //             }
    //         }else{
    //             ++i;
    //         }
    //         if(isalpha(*j)||isdigit(*j)){
    //             if(isalpha(*j)){
    //                 *j = tolower(*j);
    //             }
    //         }else{
    //             --j;
    //         }

    //         if((isalpha(*i)||isdigit(*i))&&(isalpha(*j)||isdigit(*j))){
    //             if(isalpha(*i)){
    //                 *i = tolower(*i);
    //             }
    //             if(isalpha(*j)){
    //                 *j = tolower(*j);
    //             }
    //             if(*i!=*j)
    //             {
    //                 cout<<*i<<endl;
    //                 cout<<*j<<endl;
    //                 return false;
    //             }
    //             ++i;
    //             --j;
    //         }
            
    //     }
    //     return true;
    // }
};
// @lc code=end

