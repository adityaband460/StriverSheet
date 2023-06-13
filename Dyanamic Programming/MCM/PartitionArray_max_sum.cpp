class Solution {
public:
// f(0) : array from 0 to n-1
// f(i) : array from i to n-1
    int f(int i, vector<int>&arr,int k,vector<int>&dp)
    {
        int n = arr.size();
        //base case
        if(i>=n) return 0;

        if(dp[i] != -1) return dp[i];
        //rec case
        int len = 0,maxele = -1,maxi = -1;
        for(int ind = i;ind < min(i+k ,n);ind++)
        {
            len++;
            maxele = max(maxele,arr[ind]);
            int sum = len * maxele + f(ind+1,arr,k,dp);
            maxi = max(maxi,sum);
        }
        return dp[i] = maxi;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        // int n = arr.size();
        // vector<int>dp(n,-1);
        // return f(0,arr,k,dp);
        //tabulation
        int n = arr.size();
        vector<int>dp(n+1,-1);
        dp[n] = 0;
        for(int i=n-1;i>=0;i--)
        {
            int len = 0,maxele = -1,maxi = -1;
            for(int ind = i;ind < min(i+k ,n);ind++)
            {
                len++;
                maxele = max(maxele,arr[ind]);
                int sum = len * maxele + dp[ind+1];
                maxi = max(maxi,sum);
            }
             dp[i] = maxi;
        }
        return dp[0];
    }
};
