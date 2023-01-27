//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    
    string longestCommonPrefix (string arr[], int N)
    {
        // your code here
        string prefix = arr[0];
        for(int i=1;i<N;i++)
        {
            string temp = arr[i];
            int n = min(temp.size(),prefix.length());
            prefix = prefix.substr(0,n);
            for(int j=0;j<n;j++)
            {
                if(temp[j] != prefix[j])
                {
                    
                    prefix = prefix.substr(0,j);
                    break;
                }
            }
        }
        if(prefix == "")
        return "-1";
        else
        return prefix;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends
