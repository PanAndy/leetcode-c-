/*
 * @lc app=leetcode.cn id=990 lang=cpp
 *
 * [990] 等式方程的可满足性
 */

// @lc code=start

#include<iostream>
#include<vector>
#include<string>

using namespace std;

class UF{
public:
    int count;
    vector<int> parent;
    vector<int> size;
    UF(int n){
        count = n;
        parent = vector<int>(n+1, 0);
        size = vector<int>(n+1, 1);
        for(int i=0;i<=n;i++)
        {
            parent[i] = i;
        }
    }

    void Union(int p, int q){
        int P = find(p);
        int Q = find(q);
        if(P == Q)return;

        if(size[P] > size[Q]){
            parent[Q] = P;
            size[P] += size[Q];
        }else{
            parent[P] = Q;
            size[Q] += size[P];
        }
    }

    bool connected(int p, int q){
        return find(p) == find(q);
    }

    int find(int x){
        while(x != parent[x])
        {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }
};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        int n = equations.size();
        if(n==0)return true;
        UF uf(26);
        for(string s : equations){
            if(s.substr(1, 2) == "==")
            {
                uf.Union(s[0] - 'a', s[3] - 'a');
            }
        }

        for(string s : equations)
        {
            if(s.substr(1,2) == "!=")
            {
                if(uf.connected(s[0] - 'a', s[3] - 'a')){
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end

