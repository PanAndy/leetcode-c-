/*
 * @lc app=leetcode.cn id=378 lang=cpp
 *
 * [378] 有序矩阵中第K小的元素
 */

// @lc code=start

#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;


struct point{
    int val = INT_MAX;
    int x;
    int y;
    point(int val, int x, int y):val(val), x(x), y(y){}
    point(){}
};

bool operator > (const point &l, const point &r){
    return l.val > r.val;
}
class Solution {
public:

    bool check(vector<vector<int> > & matrix, int mid, int k, int n)
    {
        int i = n - 1;
        int j = 0;

        int num = 0;
        while(i >= 0 && j < n)
        {
            if(matrix[i][j] <= mid)
            {
                num += i + 1;
                j++;
            }
            else{
                i--;
            }
        }
         return num >= k;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();

        int left = matrix[0][0];
        int right = matrix[n-1][m-1] + 1;

        while(left < right)
        {
            int mid = left + ((right - left) >> 1);
            if(check(matrix, mid, k, n))
            {
                right = mid;
            }else{
                left = mid + 1;
            }
        }
        return left;
    }
    // int kthSmallest(vector<vector<int>>& matrix, int k) {
    //     int m = matrix.size();
    //     int n = matrix[0].size();

    //     vector<vector<bool>> v(m, vector<bool>(n, false));
    //     v[0][0] = true;
    //     priority_queue<point, vector<point>, greater<point>> q;
    //     point p(matrix[0][0], 0, 0);
    //     point MIN = p;
    //     q.push(p);
    //     while(k--)
    //     {
    //         MIN = q.top();
    //         q.pop();

    //         if(MIN.x+1 < m && v[MIN.x+1][MIN.y] == false){
    //             q.emplace(matrix[MIN.x+1][MIN.y], MIN.x+1, MIN.y);
    //             v[MIN.x+1][MIN.y] = true;
    //         }
    //         if(MIN.y+1 < n && v[MIN.x][MIN.y+1] == false){
    //             q.emplace(matrix[MIN.x][MIN.y+1], MIN.x, MIN.y+1);
    //             v[MIN.x][MIN.y+1] = true;
    //         }
    //     }  
    //     return MIN.val;
    // }
    // 自己设计的
    // int kthSmallest(vector<vector<int>>& matrix, int k) {
    //     int m = matrix.size();
    //     int n = matrix[0].size();
    //     vector<vector<bool> > v(m, vector<bool>(n, false));

    //     vector<point> travse;
    //     point p(matrix[0][0], 0, 0);
    //     travse.push_back(p);
    //     v[0][0] = true;
        
    //     while(k>1)
    //     {
    //         point MIN;
    //         for(point p : travse)
    //         {
    //             if(p.x + 1 < m && v[p.x+1][p.y] == false){
    //                 point t(matrix[p.x+1][p.y], p.x+1, p.y);
    //                 MIN = min(MIN, t, less<point>());
    //             }
    //             if(p.y+1 < n && v[p.x][p.y+1] == false)
    //             {
    //                 point t(matrix[p.x][p.y+1], p.x, p.y+1);
    //                 MIN = min(MIN, t, less<point>());
    //             }
    //         }
    //         v[MIN.x][MIN.y] = true;
    //         travse.push_back(MIN);
    //         k--;
    //     }  
    //     return travse.back().val;
    // }
    // int kthSmallest(vector<vector<int>>& matrix, int k) {
    //     struct point{
    //         int val, x, y;
    //         point(int val, int x, int y): val(val), x(x), y(y){}
    //         bool operator > (const point &a) const {return this->val > a.val;}
    //     };
    //     int m = matrix.size();
    //     int n = matrix[0].size();

    //     priority_queue<point, vector<point>, greater<point>> que;
    //     for(int i=0;i<m;i++){
    //         que.emplace(matrix[i][0], i, 0);
    //     }
        
    //     // 左下方最小的元素由queue自动维护了
    //     // 只用考虑左下方和上面最小元素右边一个元素即可
    //     for(int i=0;i<k-1;i++)
    //     {
    //         point now = que.top();
    //         que.pop();
    //         if(now.y != n-1){
    //             que.emplace(matrix[now.x][now.y+1], now.x, now.y + 1);
    //         }
    //     }
    //     return que.top().val;

    // }
    // int kthSmallest(vector<vector<int>>& matrix, int k) {
    //     int m = matrix.size();
    //     int n = matrix[0].size();

    //     vector<int> tmp;
    //     for(int i = 0; i < m; ++i)
    //     {
    //         for(int j = 0; j < n; ++j){
    //             tmp.push_back(matrix[i][j]);
    //         }
    //     }
    //     sort(tmp.begin(), tmp.end());
    //     return tmp[k-1];
    // }
};
// @lc code=end

