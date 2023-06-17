//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        
        // build heap O(n)
        // we can use multiset also 
        // operations in multiset take log n time
        priority_queue<long long,vector<long long>,greater<long long>>minHeap(arr,arr+n);
        
        // as we want min 2 elements always
        // also push their sum and again find min 2 elements
        // pop pop push
        
        long long ans = 0;
        while(minHeap.size() > 1)
        {
            long long a = minHeap.top();
            // cout<<a<<" was popped \n";
            minHeap.pop();
            
            long long b = minHeap.top();
            minHeap.pop();
            //  cout<<b<<" was popped \n";
            ans += a + b;
            minHeap.push(a+b);
        }
        return ans;
        
    }
};


//{ Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends
