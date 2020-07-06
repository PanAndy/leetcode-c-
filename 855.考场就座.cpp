/*
 * @lc app=leetcode.cn id=855 lang=cpp
 *
 * [855] 考场就座
 */

// @lc code=start
#include<map>
#include<set>

#include<vector>

using namespace std;




class ExamRoom {
public:
    class cmp{
        public:
            bool operator () (const vector<int> &l, const vector<int> &r){
                int distA = distance(l);
                int distB = distance(r);
                if(distA == distB){
                    return r[0] - l[0];
                }
                return distA - distB;
            }
    };

    int N;
    map<int,vector<int> > startMap;
    map<int, vector<int> > endMap;
    set<vector<int>, cmp> pq;

    static int distance(vector<int> intv){
        int x = intv[0];
        int y = intv[1];
        int N = intv[2];
        if(x == -1)return y;
        if(y == N) return N - 1 - x;
        return (y - x) / 2;
    }
    ExamRoom(int N) {
        this->N = N;
    }
    void removeInterval(vector<int> intv){
        pq.erase(intv);
        startMap.erase(intv[0]);
        endMap.erase(intv[1]);
    }

    void addInterval(vector<int> intv){
        pq.insert(intv);
        startMap[intv[0]] = intv;
        endMap[intv[1]] = intv;
    }

    int seat() {
        vector<int> longest = *(pq.begin());
        int x = longest[0];
        int y = longest[1];
        int seat;
        if(x == -1){
            seat = 0;
        }else if(y == N){
            seat = N - 1;
        }else{
            seat = (y - x) / 2 + x;
        }

        vector<int> left = {x, seat, N};
        vector<int> right = {seat, y, N};
        removeInterval(longest);
        addInterval(left);
        addInterval(right);
        return seat;
    }
    
    void leave(int p) {
        vector<int> right = startMap[p];
        vector<int> left = endMap[p];
        vector<int> merged = {left[0], right[1], N};
        removeInterval(left);
        removeInterval(right);
        addInterval(merged);
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(N);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */
// @lc code=end

