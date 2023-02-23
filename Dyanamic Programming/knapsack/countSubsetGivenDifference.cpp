//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int mod = 1e9+7;
    int countSubsetSum(int n ,int sum,vector<vector<int>>&table,vector<int>& arr)
    {
       if(n == 0)
        {
            if(sum == 0)
                return 1;
            if(sum != 0)
                return 0;
        }
        if(table[n][sum] != -1)
        {
            return table[n][sum];
        }
        
        if(arr[n-1] <= sum)
        {
            return table[n][sum] = (countSubsetSum(n-1,sum-arr[n-1],table,arr) + 
                    countSubsetSum(n-1,sum,table,arr) )%mod;
        }
        else
        {
            return table[n][sum] = countSubsetSum(n-1,sum,table,arr);
        }
        
    }
    
    int countPartitions(int n, int d, vector<int>& arr) {
       int sum =0;
       for(int i=0;i<n;i++)
       {
            sum += arr[i];
       }
       // problem has no solution when
    //   sum-d cant be divided into 2 equal parts so we get diff= d by adding d
    //   to first subset
    //  {s2} - {s1} = 0 , sum s2 + sum s1 = Sum of arr - d
    // then just add remaining d sum to s2
    
    //  also no solution when difference is greater than sum of arr
    // as max diff possible is sum of arr only
     
       if((sum - d)%2 != 0 )
        {
            return 0;
        }
        // sum-d should lie between 0 and 2*sum
        int val = sum-d;
        if( !(val <= 2*sum && val >= 0) )
            return 0;
        // else do the calculations
          vector<vector<int>> table(n+1,vector<int>(sum+1,-1));
          int partSumS1 = (sum - d )/2;
          // cout<<sum<<"  <--\n";
          return countSubsetSum(n,partSumS1,table,arr);
        
      
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends
