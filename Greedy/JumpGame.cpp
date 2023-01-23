//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int canReach(int A[], int N) {
        // code here
        
        int currPos = 0;
        while(currPos < N-1)
        {
            int maxJump = A[currPos];
            
            //if we get zero and its not last then game over
            if(maxJump == 0 && currPos != N-1)
            return 0;
            
            int maxDigitIndex= currPos+1;
            for(int i=currPos+1;i<N && i <= currPos+maxJump;i++)
            {
                // very important check test case below
                if(i == N-1)
                    return 1;
                    
                if (A[maxDigitIndex] <= A[i])
                {
                    maxDigitIndex = i;
                }
            }
            // cout<<"max index is "<<maxDigitIndex<<"\n";
            currPos = maxDigitIndex;
        }
        return 1;
    }
};


// test case
//4
//3 1 0 0

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.canReach(A,N) << endl;
    }
    return 0;
}
// } Driver Code Ends
