//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    void fNSR(long long arr[] ,int n,vector<long long> &NSR){
        
        stack<long long>st;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty()&& arr[st.top()]>= arr[i])
            {
                st.pop();
            }
            if(st.empty())
            {
                NSR[i] = n;
            }
            else
            {
                NSR[i] = st.top();
            }
            st.push(i);
        }
    }
    void fNSL(long long arr[] ,int n,vector<long long> &NSL)
    {
        stack<long long >st;
        for(int i=0;i<n;i++)
        {
            //we want smaller element so remove larger ones from stack
            while(!st.empty() && arr[st.top()] >= arr[i])
            {
                st.pop();
            }
            if(st.empty())
            {
                NSL[i] = -1;
            }
            else
                NSL[i] = st.top();
                
            st.push(i);
        }
    }
    
    
    long long getMaxArea(long long arr[], int n)
    {
        vector<long long >NSR(n) ;
        vector<long long >NSL(n) ;
        
        fNSR(arr,n,NSR);
        fNSL(arr,n,NSL);
     
        long long maxarea = -1;
        for(int i=0;i<n;i++)
        {
            // width of rect = NSR - NSL - 1
            // height of rect = arr[i]
            long long area = (NSR[i]-NSL[i]-1) * arr[i];
            maxarea = max(maxarea,area);
        }
        return maxarea;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends
