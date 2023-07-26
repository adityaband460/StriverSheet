class Solution {
  public:
    int mod = 1e9+7;
    
    //space optimization
    int spaceOpti(int n,int sum,vector<int>&arr,
    vector<vector<int>>&dp)
    {
        vector<int>prev(sum+1,0);
        //base case
        prev[0] = 1;
        // copy recurrence
        for(int ind = 1;ind<n+1;ind++)
        {
            vector<int>cur(sum+1,0);
            for(int target = 0;target <sum+1;target++)
            {
                int pick = 0,notpick=0;
                if(arr[ind-1] <= target)
                {
                    pick = prev[target-arr[ind-1]];
                }
                notpick = prev[target];
                cur[target] = (pick + notpick)%mod;
            }
            prev = cur;
        }
        return prev[sum];
    }
    int countSubsetSumTabulation(int n,int sum,vector<int>&arr,
    vector<vector<int>>&dp)
    {
        //tabulation
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<sum+1;j++)
            {
                dp[i][j] = 0;
            }
        }
        //base case
        dp[0][0] = 1;
        // copy recurrence
        for(int ind = 1;ind<n+1;ind++)
        {
            for(int target = 0;target <sum+1;target++)
            {
                int pick = 0,notpick=0;
                if(arr[ind-1] <= target)
                {
                    pick = dp[ind-1][target-arr[ind-1]];
                }
                notpick = dp[ind-1][target];
                dp[ind][target] = (pick + notpick)%mod;
            }
        }
        return dp[n][sum];
    }
    int countSubsetSum(int n,int target,vector<int>&arr,vector<vector<int>>&dp)
    {
        // memoization
        if(n==0)
        {
            if(target==0) 
                return 1;
            else 
                return 0;
        }
        if(dp[n][target] != -1) return dp[n][target];
        int pick = 0,notpick=0;
        if(arr[n-1] <= target)
        {
            pick = countSubsetSum(n-1,target-arr[n-1],arr,dp);
        }
        notpick = countSubsetSum(n-1,target,arr,dp);
        return dp[n][target] = (pick + notpick)%mod;
        
        
        
    }
  
    int countPartitions(int n, int d, vector<int>& arr) {
        int sum = 0;
        for(int i=0;i<n;i++)
        {
            sum += arr[i];
        }
        int target;
        
        if(sum - d >=0 && (sum-d)%2==0)
            target = (sum-d)/2;
        else
            return 0;
            
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        return spaceOpti(n,target,arr,dp);
    }
};
