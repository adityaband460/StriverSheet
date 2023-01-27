//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    string maxOdd(string s) {
        // your code here
        int n = s.length();
        int lastOddIndex = -1;
        for(int i=n-1;i>=0;i--)
        {
            if( (s[i]-'0') % 2 == 1)
            {
                lastOddIndex = i;
                break;
            }
        }
        if(lastOddIndex ==-1)
            return "";
        
        return s.substr(0,lastOddIndex+1);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;

        cout << ob.maxOdd(s) << endl;
    }
}

// } Driver Code Ends
