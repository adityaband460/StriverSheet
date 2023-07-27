class Solution {
public:
    //----------------------------------------
    // memoization
    //----------------------------------------
    int solve(int n,int amount,vector<int>&coins,vector<vector<int>>&dp)
    {
        if(amount==0) return 0;
        if(n==0 && amount > 0) return 1e9;

        if(dp[n][amount] != -1) return dp[n][amount];
        int pick = 1e9,notpick=1e9;
        if(coins[n-1] <= amount)
        {
            pick = 1+solve(n,amount-coins[n-1],coins,dp);
        }
        notpick = solve(n-1,amount,coins,dp);
        return dp[n][amount] = min(pick,notpick);
    }
    //----------------------------------------
    // Tabulation
    //----------------------------------------
    int solveTab(int n,int amount,vector<int>&coins,vector<vector<int>>&dp)
    {
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<amount+1;j++)
            {
                dp[i][j] = 1e9;
            }
        }
        //base case
        for(int i=0;i<n+1;i++)
        {
            dp[i][0] = 0;
        }
        for(int amt=1;amt<amount+1;amt++)
        {
            dp[0][amt] = 1e9;
        }
        
        for(int ind = 1;ind<n+1;ind++)
        {
            for(int amt = 1;amt<amount+1;amt++)
            {
                int pick = 1e9;
                if(coins[ind-1]<=amt)
                {
                    pick = 1 + dp[ind][amt-coins[ind-1]];
                }
                int notpick = dp[ind-1][amt];
                dp[ind][amt] = min(pick,notpick);
            }
           
        }

        return dp[n][amount] ;
    }
    //----------------------------------------
    // space optimization
    //----------------------------------------
    int solveSpaceOpti(int n,int amount,vector<int>&coins,
    vector<vector<int>>&dp)
    {
        vector<int>prev(amount+1,1e9),cur(amount+1,1e9);
        //base case
        prev[0] = 0;    // size of coins = 0 and make amount = 0 
        // 0 coins needed
        for(int ind = 1;ind<n+1;ind++)
        {
            for(int amt = 0;amt<amount+1;amt++)
            {
                int pick = 1e9;
                if(coins[ind-1]<=amt)
                {
                    pick = 1 + cur[amt-coins[ind-1]];
                }
                int notpick = prev[amt];
                cur[amt] = min(pick,notpick);
            }
            prev = cur;
        }

        return cur[amount] ;
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        int ans = solveSpaceOpti(n,amount,coins,dp);
        if(ans >=1e9)return -1;
        else return ans;
    }
};
