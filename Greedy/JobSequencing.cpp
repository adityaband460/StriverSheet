//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    
    static bool SortByProfit(Job a,Job b)
    {
        if(a.profit != b.profit)
        {
            return (a.profit > b.profit);
        }
        else
        {
            return (a.dead < b.dead);
        }
      
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        vector<int>JobQ(n+1,-1);
        int profit=0,noOfJobs=0;
         sort(arr,arr+n,SortByProfit);
         
        //   for(int i=0;i<n;i++)
        // {
        //     cout<<arr[i].profit<<" ";
        // }cout<<endl;
        for(int i=0;i<n;i++)
        {
            int deadline = arr[i].dead;
            bool scheduled = false;
            for(int j=deadline;j>=1;j--)
            {
                if(JobQ[j]==-1)
                {
                    JobQ[j] = arr[i].id;
                    scheduled = true;
                    break;
                }
            }
            if(scheduled)
            {
                noOfJobs++;
                profit += arr[i].profit;
            }
        }
        vector<int> ans(2,0);
        ans[0] = noOfJobs;
        ans[1] =  profit;
        return ans;
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends
