//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  // assume that we have infinite supply means unbounded ksack
  // & is important
    long long int solve(int coins[],int n,int sum,vector<vector<long long int>> &table)
    {
        // base case
        if(n == 0 && sum !=0)
            return 0;
        if(sum == 0)
            return 1;
         // rec case
         
         if(table[n][sum] != -1)
            return table[n][sum];
            
         // we can take n th coin if it is less than or equal to sum
         if(coins[n-1] <= sum)
         {
             return table[n][sum] = solve(coins,n,sum-coins[n-1],table) + solve(coins,n-1,sum,table);
         }
         else
         {
             return table[n][sum] = solve(coins,n-1,sum,table);
         }
            
    }
    long long int count(int coins[], int N, int sum) {
        vector<vector<long long int>>table(N+1,vector<long long int>(sum+1,-1));
        
        return solve(coins,N,sum,table);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends
