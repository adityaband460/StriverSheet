/*
----------------------------------------------------------------
Most optimal Approach
K- way merge algorith

storing all followers last tweet only in Heap : max heap size = 501
----------------------------------------------------------------

using pii = pair<int,int>; // time,tweetId
class Twitter {
public: 
    // user -> {(time,tweetId),(time,tweetId),....} 
    unordered_map<int,vector<pii>> contentMap;

    // user -> {followee1, followee2,...}
    unordered_map<int,unordered_set<int>> followeeMap;

    // vector<vector<int>> followeeMap;
    int time = 0;

    Twitter() {
      
    }
    
    void postTweet(int userId, int tweetId) {
        contentMap[userId].push_back({time,tweetId});
        time++;
    }
    
    // k - way merge approach 
    
    vector<int> getNewsFeed(int userId) {
        // most recent 10 feeds of followers
        // {time,tweetId,userId,index}
        using Node = tuple<int,int,int,int>;
        priority_queue<Node> pq; // maxHeap

        if(!contentMap[userId].empty())
        {
            int idx = contentMap[userId].size()-1; // id of most recent content of user
            auto [time, tweetId] = contentMap[userId][idx]; 

            // push most recent content of user himself
            pq.push({time,tweetId,userId,idx});
        }

        for(int followee : followeeMap[userId])
        {
            if(!contentMap[followee].empty())
            {
                int idx = contentMap[followee].size() -1;
                auto [time , tweetId] = contentMap[followee][idx];

                // push most recent content of each followees
                pq.push({time,tweetId,followee,idx});
            }
        }

        vector<int>ans;

        while(!pq.empty() && ans.size() < 10)
        {
            auto [time, tweetId, user, idx] = pq.top();
            pq.pop();

            ans.push_back(tweetId);

            // based on popped user and its content ID
            // we can get same (user, id-1) content posted 1 unit time before
            // latest one
            if(idx > 0)
            {
                idx--;
                auto [prevTime, prevTweetId] = contentMap[user][idx];

                pq.push({prevTime, prevTweetId, user,idx});
            }


        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        followeeMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId != followeeId)
            followeeMap[followerId].erase(followeeId);
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


*/




/*
-------------------------------------
limiting min Heap size to 10
Max size of heap would be 11

Problem : we are scanning all tweets of all followers but we need only 10
-------------------------------------

using pii = pair<int,int>;
class Twitter {
public:

    priority_queue<pii,vector<pii>,greater<pii>> minHeap;
    unordered_map<int,vector<pii>> contentMap;
    vector<vector<int>> followeeMap;
    int time = 0;

    Twitter() {
        followeeMap =  vector<vector<int>>(501,vector<int>(501,0));
        for(int i=0;i<501;i++)
        {
            followeeMap[i][i] = 1;
        }
        
    }
    
    void postTweet(int userId, int tweetId) {
        contentMap[userId].push_back({time,tweetId});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        // most recent 10 feeds of followers
        vector<int> newsFeed;
        int k = 10;

        for(int followee=0;followee<501;followee++)
        {
            if(followeeMap[userId][followee] == 1)
            {
                for(pii content : contentMap[followee])
                {
                    minHeap.push(content);

                    if(minHeap.size() > k)
                        minHeap.pop();
                }
            }
        }

        while(minHeap.size() > 0)
        {
            newsFeed.push_back(minHeap.top().second);
            minHeap.pop();
        }
        
        reverse(newsFeed.begin(),newsFeed.end());
        return newsFeed;
    }
    
    void follow(int followerId, int followeeId) {
        followeeMap[followerId][followeeId] = 1;
    }
    
    void unfollow(int followerId, int followeeId) {
        followeeMap[followerId][followeeId] = 0;
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
*/







/*
----------------------------------------------------------------------------------
  Store Everything in Max Heap apporach later filter based on followees
  Problem is : here all 10^5 content is unnecessarily stored inside Max Heap
----------------------------------------------------------------------------------
*/


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
