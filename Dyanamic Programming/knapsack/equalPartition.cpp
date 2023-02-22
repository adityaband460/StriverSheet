//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool subsetSum(int arr[],int sum ,int n,vector<vector<int>> &table)
        {
        // for(int j = 0; j<sum+1;j++)
        // {
        //     table[0][j] = false;
        // }
        // for(int i=0;i<n+1;i++)
        // {
        //     table[i][0] = true;
        // }
        
        // for(int i=1;i<n+1;i++)
        // {
        //     for(int j=1;j<sum+1;j++)
        //     {
        //         if(arr[i-1] <= j)
        //         {
        //             table[i][j] = (table[i-1][j-arr[i-1]] || table[i-1][j]);
        //         }
        //         else
        //         {
        //             table[i][j] = table[i-1][j];
        //         }
        //     }
        // }
        // return table[n][sum];
        //base case
        if(n == 0 && sum != 0)
        {
            return false;
        }
        if(sum == 0)
        {
            return true;
        }

        if(table[n][sum] != -1)
            return table[n][sum];

        //rec case
        if(arr[n-1] <= sum)
        {
            return table[n][sum] = (subsetSum(arr,sum-arr[n-1],n-1,table) 
            || subsetSum(arr,sum,n-1,table));
        }
        else
        {
            return table[n][sum] = subsetSum(arr,sum,n-1,table);
        }
    }
    int equalPartition(int N, int arr[])
    {
        int sum = 0;
       for(int i=0;i<N;i++)
       {
           sum += arr[i];
       }
        vector<vector<int>> table(N+1,vector<int>(sum+1,-1));
       if(sum %2 == 0)
       {
           // send sum/2 if it exists means another partition also exist with sum/2
           return subsetSum(arr,sum/2,N,table);
       }
       else
       {
           return 0;
       }
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends
