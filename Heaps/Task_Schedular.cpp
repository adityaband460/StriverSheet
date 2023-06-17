//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends
class Solution {
  public:
    int leastInterval(int N, int K, vector<char> &tasks) {
        //as we give priority to most frequent numbers schedule those tasks first
        //max heap and queue
        priority_queue<int>maxHeap;
        queue<pair<int,int>>q; // to put back tasks again in maxHeap
      // first : how many tasks remaning
      // second : when this task will be available in future
        unordered_map<char,int>mp; // freq
        
        //calculate all frequencies
        for(int i=0;i<N;i++)
        {
            mp[tasks[i]]++;
        }
        // push all frequencies in maxHeap
        for(auto it = mp.begin();it != mp.end();it++)
        {
            maxHeap.push(it -> second);
        }
        int time = 1;
      // maxHeap is empty then put idle time
        while(maxHeap.size() > 0 || !q.empty())
        {
            if(maxHeap.size() == 0)
            {
              //idle time
                // cout<<"0 ";
                time++;
            }
            else
            {// 
                int currTask = maxHeap.top();
                maxHeap.pop();
                //excute
                // cout<<currTask<<" ";
                currTask--;
                time++;
                 //task will be available at time + K th time slot
                if(currTask > 0)
                    q.push({currTask,time + K});
            }
            if(!q.empty())
            {// only first task can come if cool down for that is over
                if(q.front().second <= time)
                {
                    maxHeap.push(q.front().first);
                    q.pop();
                }
            }
        }
        // cout<<"\n";
        return time-1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<char> tasks(N);
        for (int i = 0; i < N; i++) cin >> tasks[i];

        Solution obj;
        cout << obj.leastInterval(N, K, tasks) << endl;
    }
    return 0;
}
// } Driver Code Ends
