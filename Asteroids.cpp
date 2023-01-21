//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> asteroidCollision(int N, vector<int> &asteroids) {
        
        stack<int> st;
        
        for(int i=0;i<N;)
        {
            if(st.empty())
            {
                st.push(asteroids[i]);
                i++;
            }
            else
            {
                int a = st.top();
                int b = asteroids[i];
                if( a > 0 && b < 0)  // collision
                {
                    if(a + b > 0)
                    {
                        i++;
                    }
                    else if( a + b < 0)
                    {
                        st.pop();
                    }
                    else
                    {
                        st.pop();
                         i++;
                    }
                }
                else
                {
                    st.push(asteroids[i]);
                    i++;
                }
            }
            
        }
        vector<int> ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
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
        int N;
        cin >> N;

        vector<int> asteroids(N);
        for (int i = 0; i < N; i++) cin >> asteroids[i];

        Solution obj;
        vector<int> ans = obj.asteroidCollision(N, asteroids);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends