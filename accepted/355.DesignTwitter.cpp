#include"mytest.h"
#include<limits.h>


class Twitter {
public:

    unordered_map<int, unordered_set<int> > followed;       //userID - set of userID

    unordered_map<int, vector<pair<int, int> > > tweets;    //userID - posted tweets(time-id)

    int time;


    /** Initialize your data structure here. */
    Twitter() {
        time = 0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back(pair<int,int>(time++, tweetId));
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        unordered_set<int>& f = followed[userId];
        priority_queue<pair<int,int> > s;      //latest time - user id
        unordered_map<int,int> retrievedAmount;
        for(int user : f){
            int tweetQuant = tweets[user].size();
            //s push latest tweet time, userId)
            if(tweetQuant > 0)
                s.push(pair<int,int>(tweets[user][tweetQuant-1].first, user));
        }
        int tweetQuant_self = tweets[userId].size();
        if(tweetQuant_self > 0)
            s.push(pair<int,int>(tweets[userId][tweetQuant_self-1].first, userId));

        vector<int> ans;
        for(int i = 0; !s.empty() && i < 10; i ++) {
            int user = s.top().second;
            s.pop();
            int tweetQuant = tweets[user].size();
            ans.push_back(tweets[user][tweetQuant - 1 - retrievedAmount[user]].second);
            retrievedAmount[user] ++;

            if(retrievedAmount[user] < tweetQuant)
                s.push(pair<int,int>(tweets[user][tweetQuant-1-retrievedAmount[user]].first, user));
        }

        return ans;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if(followerId == followeeId) return;
        followed[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        followed[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */



int main() {
	srand(time(NULL));




    return 0;
}
