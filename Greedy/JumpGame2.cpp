//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int arr[], int n){
        // Your code here
        
        if(n<=1)
            return 0;
        if(arr[0] ==0)
            return -1;
        
        // choose next jumptarget based on who has greater i + arr[i]
        
        int currpos = 0;
        int steps = arr[currpos];
        int maxStepIndex = currpos+1;
        int jumps = 0;
        
        while(currpos <= n-1)
        {
            steps = arr[currpos];
            maxStepIndex = currpos+1;
            
            if(arr[currpos]==0 && currpos != n-1)
            {
                return -1;
            }
            for(int i=currpos+1;i<n && i<=currpos+steps;i++)
            {
                if(i==n-1)
                {
                    return jumps+1;
                }
                if(maxStepIndex + arr[maxStepIndex] <= i + arr[i])
                {
                      maxStepIndex = i;
                }
            }
            currpos = maxStepIndex;
            // cout<<"jumped here "<<currpos<<" ";
            jumps++;
            
        }
        return -1;
        
    }
};
  // Another Solution given in gfg

    int minJumps(int arr[], int n){
            // Your code here

            if(n<=1)
                return 0;
            if(arr[0] ==0)
                return -1;

            // choose next jumptarget based on who has greater i + arr[i]

            int maxReach = arr[0];// max how much we can travel
            int steps = arr[0]; // consider steps as fuel
            int jumps = 1; // our ans
            for(int i=1;i<n;i++)
            {
                // if we reach to last pos then return jumps
                if(i== n-1)
                    return jumps;

                // update maxReach everytime each pos have chance to update maxReach    
                maxReach = max(maxReach,i+arr[i]);
                // if we travel 1 index our fuel gets depleted by 1
                steps--;

                // if fuel becomes 0 , we can refill it by the 
                // difference between i and maxReach as that much
                // we can still travel
                if(steps == 0)
                {
                    //we needed to jump as prev arr[i] fuel is over
                    jumps++;
                    if(i == maxReach) // i >= maxReach will also work
                    {
                        return -1;
                    }

                    // refill
                    steps = maxReach - i;
                }
            }
            return -1;

        }
    

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends
