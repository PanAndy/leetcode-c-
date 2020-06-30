/*
 * @lc app=leetcode.cn id=969 lang=cpp
 *
 * [969] 煎饼排序
 */

// @lc code=start
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> res;
    vector<int> pancakeSort(vector<int>& A) {
        res.clear();
        sort(A, A.size());
        return res;
    }
    void sort(vector<int>& A, int n){
        if(n==1)return;
        int maxCake = 0;
        int maxCakeIndex = 0;
        for(int i=0;i<n;i++){
            if(A[i] > maxCake){
                maxCakeIndex = i;
                maxCake = A[i];
            }
        }
        reverse(A, 0, maxCakeIndex);
        res.push_back(maxCakeIndex+1);

        reverse(A, 0, n-1);
        res.push_back(n);

        sort(A, n-1);
    }

    void reverse(vector<int>& arr, int i, int j){
        while (i < j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
        
    }
};
// @lc code=end

