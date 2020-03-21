/*
 * @lc app=leetcode.cn id=733 lang=cpp
 *
 * [733] 图像渲染
 */

// @lc code=start
#include<iostream>
#include<vector>

using namespace std;
int m[51][51];
class Solution {
public:


    vector<vector<int>> dfs(vector<vector<int>>& image, int sr, int sc, int newColor){
        int oldcolor;
        if(m[sr][sc]==0){
            oldcolor = image[sr][sc];
            image[sr][sc]=newColor;
            m[sr][sc]=1;
        }else{
            return image;
        }

        if(sr-1>=0 && image[sr-1][sc]==oldcolor && m[sr-1][sc]==0){
            image = dfs(image,sr-1,sc,newColor);
        }
        if(sr+1<=image.size()-1 && image[sr+1][sc]==oldcolor && m[sr+1][sc]==0){
            image = dfs(image,sr+1,sc,newColor);
        }
        if(sc-1>=0 && image[sr][sc-1]==oldcolor && m[sr][sc-1]==0){
            image = dfs(image,sr,sc-1,newColor);
        }
        if(sc+1<=image[0].size()-1 && image[sr][sc+1]==oldcolor && m[sr][sc+1]==0){
            image = dfs(image,sr,sc+1,newColor);
        }
        return image;
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        for(int i=0;i<51;i++)
            for(int j=0;j<51;j++)
                m[i][j]=0;
        image = dfs(image, sr, sc, newColor);        
        return image;
    }
};
// @lc code=end

