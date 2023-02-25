 int solve(vector<int>& coins, int n, int sum, vector<vector<int>>& table) {
    // Base case
    if (sum == 0) {
        return 0;
    }
    if (n == 0) {
        return 1e9;
    }
    if (table[n][sum] != -1) {
        return table[n][sum];
    }
    // Recursive case
    int take = 1e9, notTake = 1e9;
    if (coins[n - 1] <= sum) {
        take = 1 + solve(coins, n, sum - coins[n - 1], table);
    }
    notTake = solve(coins, n - 1, sum, table);
    return table[n][sum] = min(take, notTake);
}
