class Solution {
public:
    //----------------------------------------
    // space optimized one
    //----------------------------------------
   
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

       vector<int>table(amount+1,1e9);
       table[0] = 0; // n==0 and sum ==0 
       
       for(int i=1;i<n+1;i++)
       {
           for(int j=0;j<amount+1;j++)
           {
               if(coins[i-1] <= j)
               table[j] = min (table[j],1+table[j-coins[i-1]]);
           }
       }
        int ans = table[amount];
        if(ans >= 1e9)
            return -1;
        else
            return ans;
    }
};
/*
In the tabulation approach, the line of code that considers the case of not taking a coin is:
table[i][j] = table[i-1][j]; 
This line of code updates the table at position [i][j] by taking the value from the previous row i-1 and the same column j, which represents the case where we do not include the i-th coin in the solution.

For example, let's say we have the following coins: [1, 2, 5] and the target amount is 7. When we are calculating the table entry table[2][7], which represents the case where we are considering the first two coins [1, 2] and the target amount is 7, we have two options: either we include the second coin 2 or we don't.

If we don't include the second coin, then the solution is the same as the previous row table[1][7], which corresponds to the case where we only consider the first coin [1] and the target amount is 7. On the other hand, if we include the second coin, then we need to consider the remaining amount 5 and the same set of coins [1, 2], which corresponds to the table entry table[2][5]. We then add 1 to this value to account for the inclusion of the second coin.

By taking the minimum of these two values, we can obtain the optimal solution for the current row and column.




Aditya Band
why j-coins[i] will be good index
If we want to make a sum of j and we have a coin of value coins[i], then to make the sum of j using the coin of coins[i] we will need to use the optimal number of coins required to make a sum of j-coins[i] and then add 1 to it (since we are using 1 more coin of value coins[i]).

Therefore, for a given i and j, if we know the optimal number of coins required to make a sum of j-coins[i] (i.e., table[i][j-coins[i]]), then we can easily compute the optimal number of coins required to make a sum of j using the coin of coins[i] (i.e., 1+table[i][j-coins[i]]). Hence, j-coins[i] is a good index for computing the optimal number of coins required to make a sum of j using the coin of coins[i].






*/
