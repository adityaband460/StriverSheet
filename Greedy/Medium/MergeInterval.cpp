//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

    bool static compare(vector<int>e1,vector<int>e2)
    {
        if(e1[0] != e2[0])
        {
            return e1[0] < e2[0];
        }
        
        else
        {
            return e1[1] < e2[1];
        }
    }
    bool overlap(vector<int>e1,vector<int>e2)
    {
        if(e1[0] < e2[0])
        {
            if(e2[0] <= e1[1])
                return true;
        }
        else if(e1[0] > e2[0])
        {
            if(e1[0] <= e2[1])
                return true;
        }
        else
        {
            return true;
        }
        return false;
    }
    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
         vector<vector<int>> output;
         sort(intervals.begin(),intervals.end(),compare);
         
         int n = intervals.size();
         // consider 1st interval as new interval
         vector<int>newEvent = intervals[0];
         
         for(int i=1;i<n;i++)
         {
             if(overlap(newEvent,intervals[i]))
             {
                 newEvent[0] = min(newEvent[0],intervals[i][0]);
                 newEvent[1] = max(newEvent[1],intervals[i][1]);
             }
             else
             {
                 output.push_back(newEvent);
                 newEvent = intervals[i];
             }
             
             
         }
         output.push_back(newEvent);
         
         return output;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>Intervals(n);
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			Intervals[i].push_back(x);
			Intervals[i].push_back(y);
		}
		Solution obj;
		vector<vector<int>> ans = obj.overlappedInterval(Intervals);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends
