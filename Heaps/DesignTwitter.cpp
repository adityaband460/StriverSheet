//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Twitter {
  public:
    int time;// to keep track of recent tweets , higer number more recent
    // user's friends
    unordered_map<int,unordered_set<int>>friendList;
    // all the tweets ever posted
    priority_queue<vector<int>>timeLine;
      // Initialize your data structure here
    Twitter() {
        time = 1;
    }

    // Compose a new tweet
    void postTweet(int userId, int tweetId) {
        timeLine.push({time,tweetId,userId});
        time++;
    }

    // Retrieve the 10 most recent tweet ids as mentioned in question
    vector<int> getNewsFeed(int userId) {
        int count = 10;
        vector<int>recentRecords;
        // vector<vector<int>>refill;
        priority_queue<vector<int>> tempTimeLine = timeLine;
        while(count > 0 && tempTimeLine.size()>0)
        {
            // cout<<tempTimeLine.top()[0]<<" --\n";
            int frnd = tempTimeLine.top()[2];
            // if it was posted by his friend or he himself
            if(friendList[userId].count(frnd) || frnd == userId)
            {
                recentRecords.push_back(tempTimeLine.top()[1]);
                count--;
            }
            tempTimeLine.pop();
        }
       
        
        return recentRecords;
        
    }

    // Follower follows a followee. If the operation is invalid, it should be a
    // no-op.
    void follow(int followerId, int followeeId) {
        friendList[followerId].insert(followeeId);
    }

    // Follower unfollows a followee. If the operation is invalid, it should be
    // a no-op.
    void unfollow(int followerId, int followeeId) {
        friendList[followerId].erase(followeeId);
    }
};

//{ Driver Code Starts.

int main() {
    Twitter obj;

    int total_queries;
    cin >> total_queries;
    while (total_queries--) {
        int query;
        cin >> query;

        // if query = 1, postTweet()
        // if query = 2, getNewsFeed()
        // if query = 3, follow()
        // if query = 4, unfollow()

        if (query == 1) {
            int userId, tweetId;
            cin >> userId >> tweetId;
            obj.postTweet(userId, tweetId);
        } else if (query == 2) {
            int userId;
            cin >> userId;
            vector<int> vec = obj.getNewsFeed(userId);
            for (int a : vec) cout << a << " ";
            cout << endl;
        } else if (query == 3) {
            int follower, followee;
            cin >> follower >> followee;
            obj.follow(follower, followee);
        } else {
            int follower, followee;
            cin >> follower >> followee;
            obj.unfollow(follower, followee);
        }
    }
    return 0;
}
// } Driver Code Ends
