class Solution {
public:
    int memoization(vector<int>coins,int n,int sum,vector<vector<int>> &table)
    {
        // notice the base case it is different
         //base case
         if(n==0)
            return 1e9;
        if(n==1)
        {
            
            if(sum % coins[n-1] == 0)
            {
                return table[n][sum] = sum/coins[n-1];
            }
            else
                return table[n][sum] = 1e9;
        }
        if(sum == 0)
            return table[n][sum] = 0;
        
         //rec case

        if(table[n][sum] != -1)
            return table[n][sum];

        if(coins[n-1] <= sum)
        {
            int take = 1 + solve(coins,n,sum-coins[n-1],table);
            int notTake = solve(coins,n-1,sum,table);

            return table[n][sum] = min(take,notTake);
        }
        else
        {
            int notTake = solve(coins,n-1,sum,table);

            return table[n][sum] = notTake;
        }
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>table(n+1,vector<int>(amount+1,-1));
        // fill first 2 rows as base case
        // intitalization
        for(int i=0;i<amount+1;i++)
        {
            table[0][i] = 1e9;
        }
        // 2nd row intialization
        // considering we have only 1 coin
        for(int i=0;i<amount+1;i++)
        {
            if(i % coins[0] == 0)
            {
                table[1][i] = i/coins[0];
            }
            else
            {
                table[1][i] = 1e9;
            }
        }
        // initialize 1st column as 0 
        // we can get 0 amount by giving 0 coins
        for(int i=0;i<n+1;i++)
        {
            table[i][0] = 0;
        }
        // remaining cases
        for(int i=2;i<n+1;i++)
        {
            for(int j =1; j<amount+1;j++)
            {
                if( coins[i-1] <= j)
                {
                    table[i][j] = min(table[i-1][j],1+table[i][j-coins[i-1]]);
                }
                else
                {
                    table[i][j] = table[i-1][j]; 
                }
            }
        }
        int ans = table[n][amount];
        // int ans =  solve(coins,n,amount,table);

        if(ans >= 1e9)
            return -1;
        else
            return ans;
    }
};
