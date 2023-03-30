//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    bool overlap(vector<int>e1,vector<int>e2)
    {
        if(e1[0] < e2[0])
        {
            if(e2[0] <= e1[1])
            {
                return true;
            }
        }
        else if(e1[0] > e2[0])
        {
            if(e2[1] >= e1[0])
                return true;
        }
        else
        {
            return true;
        }
      return false;
        
    }
    vector<vector<int>> insertNewEvent(int N, vector<vector<int>> &intervals, vector<int> &newEvent) {
        
        vector<vector<int>>output;
        int n = intervals.size();
        bool newEventInserted = false;
        for(int i=0;i<n;i++)
        {
            if(overlap(intervals[i],newEvent))
            {
                newEvent[0] = min(newEvent[0],intervals[i][0]);
                newEvent[1] = max(newEvent[1],intervals[i][1]);
            }
            else
            {
                // if no overlap happen between new line and i th line
                // if new event is smaller then now way it will overlap again
                // as intervals are sorted
                if(newEvent[0] < intervals[i][0]  && !newEventInserted)
                {
                    output.push_back(newEvent);
                    newEventInserted = true;
                }
                
                
                output.push_back(intervals[i]);
            }
        }
        // edge test case I missed it
        // new event could be largest of all 
        if(!newEventInserted)
        {
            output.push_back(newEvent);
        }
        return output;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<vector<int>> intervals(N,vector<int>(2));
        for (int i = 0; i < N; i++) {
            cin >> intervals[i][0]>>intervals[i][1];
        }
        vector<int> newEvent(2);
        cin>>newEvent[0]>>newEvent[1];
        
        Solution obj;
        vector<vector<int>> ans = obj.insertNewEvent(N, intervals,newEvent);
        cout<<"[";
        for(int i=0;i<ans.size();i++){
            cout<<"["<<ans[i][0]<<','<<ans[i][1]<<']';
            if(i!=(ans.size()-1)) cout<<",";
        }
        cout<<"]"<<endl;
    }
    return 0;
}
// } Driver Code Ends
