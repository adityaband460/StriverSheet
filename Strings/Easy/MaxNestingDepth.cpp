//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int maxDepth(string s) {
        // code here
        int count = 0;
        int depth = 0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i] =='(')
            {
                count++;
            }
            if(s[i]==')')
            {
                count--;
            }
            depth = count > depth ? count : depth;
        }
        return depth;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution obj;
        int ans = obj.maxDepth(s);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends
