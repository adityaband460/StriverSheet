//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string removeKdigits(string S, int K) {
        int k=K;
        stack<int> st;
        //keep stack in increasing order
        for(int i=0;i<S.length();i++)
        {
            int currElement = S[i] - '0';
            if(st.empty() && currElement!=0)
            {
                st.push(currElement);
            }
            else if(!st.empty())
            {
                if(currElement >= st.top() )
                {
                    st.push(currElement);
                }
                else
                {
                    while(!st.empty() && k > 0 && st.top() > currElement)
                    {
                        st.pop();
                        k--;
                    }
                    
                    if(st.empty() && currElement!=0)
                    {
                        st.push(currElement);
                    }
                    
                   else if(!st.empty())
                    {
                        st.push(currElement);
                    }
                    
                }
            }
        }
        
        while( !st.empty() && k > 0)
        {
            st.pop();
            k--;
        }
        
        if(st.empty())
        {
            st.push(0);
        }
        
        string ans;
        while(!st.empty())
        {
            char t = st.top()+'0';
            ans.push_back(t);
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;
        Solution obj;
        cout << obj.removeKdigits(S, K) << endl;
    }
    return 0;
}

// } Driver Code Ends