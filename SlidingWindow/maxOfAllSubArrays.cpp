//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        // your code here
        deque<int> q;
        vector<int> ans;
        int i=0,j=0;
        // process 1st window
        //push indexes instead of numbers
        for(j;j<k;j++)
        {
            if(q.empty())
            {
                q.push_back(j);
            }
            else
            {
                while(!q.empty() && arr[q.back()] < arr[j])
                {
                    q.pop_back();
                }
                 q.push_back(j);
            }
        }
        j--; // to make j point at k-1 end of 1st window
        // process remaining windows
        while(j < n)
        {
            ans.push_back(arr[q.front()]);
            
            j++;
            // add j to window calculations
            if(q.empty())
            {
                q.push_back(j);
            }
            else
            {
                while(!q.empty() && arr[q.back()] < arr[j])
                {
                    q.pop_back();
                }
                 q.push_back(j);
            }
            // remove i from window calculations
            
            if(arr[q.front()] == arr[i])
            {
                q.pop_front();
            }
            i++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}
// } Driver Code Ends
