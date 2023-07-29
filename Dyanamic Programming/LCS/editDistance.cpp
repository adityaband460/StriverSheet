class Solution {
public:
    //memoization
    int solve(int n,int m ,string &s1,string &s2,vector<vector<int>>&dp)
    {
        if(n==0 )return m;
        if(m==0) return n;

        if(dp[n][m] != -1) return dp[n][m];
        if(s1[n-1]==s2[m-1])
        {
            return dp[n][m] = solve(n-1,m-1,s1,s2,dp);
        }
        else
        {
            int i = 1 + solve(n,m-1,s1,s2,dp);
            int d = 1 + solve(n-1,m,s1,s2,dp);
            int r = 1 + solve(n-1,m-1,s1,s2,dp);
            return dp[n][m] = min(i,min(d,r));
        }
    }
    //tabulation
    int solveTab(int n,int m ,string &s1,string &s2,vector<vector<int>>&dp)
    {
        for(int i=0;i<n+1;i++)
        {
            dp[i][0] = i;
        }
        for(int j=0;j<m+1;j++)
        {
            dp[0][j] = j;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s1[i-1]==s2[j-1])
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                else
                {
                    int in = 1 + dp[i][j-1];
                    int d = 1 + dp[i-1][j];
                    int r = 1 + dp[i-1][j-1];
                    dp[i][j] = min(in,min(d,r));
                }
            }
        }
        return dp[n][m];
    }
     //space opti
    int solveSpaceopti(int n,int m ,string &s1,string &s2,vector<vector<int>>&dp)
    {
        vector<int>prev(m+1,0),cur(m+1,0);
        for(int j=0;j<m+1;j++)
        {
            prev[j] = j;
        }
        for(int i=1;i<=n;i++)
        {
            cur[0] = i;
            for(int j=1;j<=m;j++)
            {
                if(s1[i-1]==s2[j-1])
                {
                    cur[j] = prev[j-1];
                }
                else
                {
                    int in = 1 + cur[j-1];
                    int d = 1 + prev[j];
                    int r = 1 + prev[j-1];
                    cur[j] = min(in,min(d,r));
                }
            }
            prev = cur;
        }
        return prev[m];
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solveSpaceopti(n,m,word1,word2,dp);
    }
};
