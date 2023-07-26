    int solveSuperSaiyan(int n,int cap ,int wt[],int val[],vector<vector<int>>&dp)
    {
        vector<int>cur(cap+1,0);
        //base case will be covered as all are 0's
       
       for(int size = 1;size<n+1;size++)
       {
           for(int capacity = cap;capacity>=1;capacity--)
           {
            int pick=0,notpick=0;
            //pick : value of that item added but cap decreases
            if(wt[size-1] <= capacity)
            {
                pick = val[size-1] + cur[capacity-wt[size-1]];
            }
            // notpick : value not added ,cap remains same
            notpick = cur[capacity];
            cur[capacity] = max(pick,notpick);
           }
           
       }
        return cur[cap];
    }
    
    int solveSpaceOpti(int n,int cap ,int wt[],int val[],vector<vector<int>>&dp)
    {
        vector<int>prev(cap+1,0);
        vector<int>cur(cap+1,0);
        //base case will be covered as all are 0's
       
       for(int size = 1;size<n+1;size++)
       {
           for(int capacity = 1;capacity<cap+1;capacity++)
           {
            int pick=0,notpick=0;
            //pick : value of that item added but cap decreases
            if(wt[size-1] <= capacity)
            {
                pick = val[size-1] + prev[capacity-wt[size-1]];
            }
            // notpick : value not added ,cap remains same
            notpick = prev[capacity];
            cur[capacity] = max(pick,notpick);
           }
           prev = cur;
       }
        return prev[cap];
    }
    //Function to return max value that can be put in knapsack of capacity W.
    int solveTabulation(int n,int cap ,int wt[],int val[],vector<vector<int>>&dp)
    {
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<cap+1;j++)
            {
                dp[i][j] = 0;
            }
        }
        //base case will be covered as all are 0's
       
       for(int size = 1;size<n+1;size++)
       {
           for(int capacity = 1;capacity<cap+1;capacity++)
           {
            int pick=0,notpick=0;
            //pick : value of that item added but cap decreases
            if(wt[size-1] <= capacity)
            {
                pick = val[size-1] + dp[size-1][capacity-wt[size-1]];
            }
            // notpick : value not added ,cap remains same
            notpick = dp[size-1][capacity];
            dp[size][capacity] = max(pick,notpick);
           }
       }
        return dp[n][cap];
    }
    int solve(int n,int cap ,int wt[],int val[],vector<vector<int>>&dp)
    {
        //base case
        if(n == 0 || cap == 0)
        {
            return 0;
        }
        if(dp[n][cap] != -1) return dp[n][cap];
        int pick=0,notpick=0;
        //pick : value of that item added but cap decreases
        if(wt[n-1] <= cap)
        {
            pick = val[n-1] + solve(n-1,cap-wt[n-1],wt,val,dp);
        }
        // notpick : value not added ,cap remains same
        notpick = solve(n-1,cap,wt,val,dp);
        return dp[n][cap] = max(pick,notpick);
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        vector<vector<int>>dp(n+1,vector<int>(W+1,-1));
        return solveSuperSaiyan(n,W,wt,val,dp);
    }
