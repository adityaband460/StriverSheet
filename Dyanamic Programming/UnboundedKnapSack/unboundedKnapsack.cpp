//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int ksack(int n , int w,int val[],int wt[],vector<vector<int>>&table)
    {
        //base case
        if(w == 0)
            return 0;
        if(n == 0)
            return 0;
        
        if(table[n][w] != -1)
        {
            return table[n][w];
        }
        //rec case
        if(wt[n-1] <= w)
        {
            // consider we take item we give another chance to take it again
            
            int take = val[n-1] + ksack(n,w-wt[n-1],val,wt,table);
            
            // not take case we dont give n th ele chance again
            
            int nottake = ksack(n-1,w,val,wt,table);
            
            return table[n][w] = max(take , nottake);
        }
        else
        {
            int nottake= ksack(n-1,w,val,wt,table);
            return table[n][w] = nottake;
        }
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>> table(N+1,vector<int>(W+1,-1));
        return ksack(N,W,val,wt,table);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends
