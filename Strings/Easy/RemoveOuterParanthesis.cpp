//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    string removeOuter(string& s) {
        // code here
        string ans;
        bool copyOn = false;
        bool inner = false;
        int counter = 0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i] == '(')
            {
                counter++;
            }
            else if(s[i] == ')')
            {
                counter--;
            }
            if(s[i] =='(' && counter > 1)
            {
                ans.push_back('(');
            }
            if(s[i] ==')' && counter >= 1)
            {
                ans.push_back(')');
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
        string s;
        cin >> s;
        Solution obj;

        cout << obj.removeOuter(s) << "\n";
    }
}
// } Driver Code Ends
