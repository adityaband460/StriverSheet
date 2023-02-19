//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    
    int kSack(int W, int wt[], int val[], int n, int table[][1002])
    {
        // base case
      if(n==0 || W==0)
        return 0;
       
      if(table[n][W] != -1)
            return table[n][W];
      // recursive case
      if(wt[n-1] <= W)// we can have 2 choices
      {
          return table[n][W] = max(
                (val[n-1]+ kSack(W-wt[n-1],wt,val,n-1,table)) ,
                kSack(W,wt,val,n-1,table) 
                );
      }
      else if( wt[n-1] > W)
      {
          return table[n][W] =  kSack(W,wt,val,n-1,table);
      }
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        int table[1002][1002];// n X W
        memset(table,-1,sizeof(table));
    
    
        for(int i=0;i<=W;i++)
        {
            table[0][i] = 0;
        }
        for(int i=0;i<=n;i++)
        {
            table[i][0] = 0;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=W;j++)
            {
                if(wt[i-1] <= j)// 
                {
                    table[i][j] = max( val[i-1] + table[i-1][j - wt[i-1]] , 
                                        table[i-1][j]);
                }
                else
                {
                    table[i][j] = table[i-1][j];
                }
            }
        }
        return table[n][W];
      //   return kSack(W,wt,val,n,table);
       
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends
