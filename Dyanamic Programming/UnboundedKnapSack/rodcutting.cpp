//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
  // &table is very important
    int unboundedKsack(int price[],int n,int cap,vector<vector<int>>&table) 
    {
        //base case
        if(n == 0)
        {
            return 0;
        }
        if(cap == 0)
        {
            return 0;
        }
        
        if(table[n][cap] != -1)
            return table[n][cap];
        //rec case
        // if we afford to take that item
        // take it or leave it
        if( n <= cap)
        {
            int take = price[n-1] + unboundedKsack(price,n,cap-n,table);
            int notTake = unboundedKsack(price,n-1,cap,table);
            return table[n][cap] = max(take,notTake);
        }
        else
        {
            int notTake = unboundedKsack(price,n-1,cap,table);
            return table[n][cap] = notTake;
        }
    }
  
    int cutRod(int price[], int n) {
        // table of (n+1) x (n+1) 
        // n elements and n as capacity
        vector<vector<int>>table(n+1,vector<int>(n+1,-1));
        
        // capacity = n also num of ele = n
        return unboundedKsack(price, n, n ,table);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends
