//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        // Complete the function
        int sum = 0;
        int maxlen = 0;
        unordered_map<int,int> map;// sum , index
        for(int i=0;i<N;i++)
        {
            // prefix sum
            sum += A[i];
            
             // when subarray starts from index '0' 
            if(sum == K)
            {
                maxlen = i+1;
            }
            // find sum -k in map so that 
            // current prefix sum is sum and sum-k is also present
            // means in that range of subarray has sum k
            if(map.find(sum-K) != map.end())
            {
                maxlen = max(maxlen , i - map[sum-K]);
            }
            // we wiil put the first occurance of sum in map
            // to maximize the size of subarray
            if(map.find(sum) == map.end())
            {
                map[sum] =  i;
            }
            
        }
        return maxlen;
    
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends
