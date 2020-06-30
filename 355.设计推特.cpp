/*
 * @lc app=leetcode.cn id=355 lang=cpp
 *
 * [355] 设计推特
 */

// @lc code=start

#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<queue>
#include<map>

using namespace std;

class Twitter {

    static int timestamp;
    
    struct Tweet{
        int id;
        int time;
        Tweet *next;

        Tweet(int id, int time){
            this->id = id;
            this->time = time;
            this->next = NULL;
        }
    };
    struct User{
        int id;
        set<int> followed;
        Tweet* head;

        User(int userId)
        {
            this->id = userId;
            this->head = NULL;
            follow(id);
        }

        void follow(int userId){
            followed.insert(userId);
        }

        void unfollow(int userId){
            if(userId!=this->id){
                followed.erase(userId);
            }
        }

        void post(int tweetId){
            Tweet* twt = new Tweet(tweetId, timestamp);
            timestamp++;
            twt->next = head;
            head = twt;
        }

    };
    map<int, User> userMap;
public:
    /** Initialize your data structure here. */
    Twitter() {

    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        if(userMap.find(userId)==userMap.end())
        {
            userMap[userId] = User(userId);
        }
        User &u = userMap[userId];
        u.post(tweetId); 
    }
    
    static bool cmp(Tweet* a, Tweet* b){
        return b->time > a->time;
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        if(userMap.find(userId)==userMap.end())return res;
        set<int> users = userMap[userId].followed;
        priority_queue<Tweet*,vector<Tweet*>, cmp() > pq;

        for(auto it=users.begin();it!=users.end();it++){
            Tweet* twt = userMap[*it].head;
            if(twt==NULL)continue;
            pq.push(twt);
        }

        while (!pq.empty())
        {
            if(res.size()==10)break;
            Tweet *twt = pq.top();
            pq.pop();
            res.push_back(twt->id);
            if(twt->next!=NULL)
            {
                pq.push(twt->next);
            }
        }
        return res;
        
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if(userMap.find(followerId)==userMap.end()){
            userMap[followerId] = User(followerId);
        }
        if(userMap.find(followeeId) == userMap.end()){
            userMap[followeeId] = User(followeeId);
        }
        User &u = userMap[followerId];
        u.follow(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if(userMap.find(followerId)==userMap.end()){
            User &flwer = userMap[followerId];
            flwer.unfollow(followeeId);
        }
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
// @lc code=end

