//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxChildren(int N, int M, vector<int> &greed, vector<int> &sz) {
        // code here
        sort(greed.begin(),greed.end(),greater<int>());
        sort(sz.begin(),sz.end(),greater<int>());
        
        int i = 0 , j = 0;
        int ans=0;
        
        while(i<greed.size() && j<sz.size())
        {
            if(greed[i] <= sz[j])
            {
                i++;
                j++;
                ans++;
            }
            else
            {
                i++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;

        vector<int> greed(N), sz(M);
        for (int i = 0; i < N; i++) {
            cin >> greed[i];
        }
        for (int i = 0; i < M; i++) {
            cin >> sz[i];
        }
        Solution obj;
        cout << obj.maxChildren(N, M, greed, sz) << endl;
    }
    return 0;
}
// } Driver Code Ends