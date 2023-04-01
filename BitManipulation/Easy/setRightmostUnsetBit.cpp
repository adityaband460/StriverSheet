//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    int setBit(int N)
    {
        // Write Your Code here
        if(N&1)//odd
            {
                int t = N;
                int x = 0;
                while(t & 1)
                {
                    x++;
                    t = t>>1;
                }
                
                if(t > 0)
                    return N + (1<<x);
                else
                    return N;
            }
        else
            return N+1;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        Solution ob;
        int ans = ob.setBit(N);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends
