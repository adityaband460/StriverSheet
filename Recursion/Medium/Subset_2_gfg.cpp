//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {

  public:
    void uSubsets(vector<int>nums,int ind,vector<int>temp,vector<vector<int>>&output)
    {
        int n = nums.size();
        //base case
        if(ind == n)
        {
          // pushing leaves of tree
            output.push_back(temp);
            return;
        }
        
        //rec case
        // for pushing null and internal nodes of tree
        output.push_back(temp);
      
        for(int i=ind;i<n;i++)
        {
          // except 1st element , choose only distinct elements
            if(i != ind && nums[i] == nums[i-1])continue;
            
          // take it every time ;(leave it) possibilities are covered by other iterations of for loop
            temp.push_back(nums[i]);
            uSubsets(nums,i+1,temp,output);
            temp.pop_back();
        }
        
    }
    vector<vector<int>> printUniqueSubsets(vector<int>& nums) {
        // Write your code here
        sort(nums.begin(),nums.end());
        vector<vector<int>> output;
        vector<int>temp;
        uSubsets(nums,0,temp,output);
        return output;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        // char marker;
        // cin >> marker;

        Solution obj;
        vector<vector<int>> ans = obj.printUniqueSubsets(nums);
        sort(ans.begin(), ans.end());
        //   printAns(ans);
        cout << "[ ";
        for (int i = 0; i < ans.size(); i++) {
            cout << "[ ";
            for (int j = 0; j < ans[i].size(); j++) cout << ans[i][j] << " ";
            cout << "]";
        }
        cout << " ]\n";

        // cout<< "~\n";
    }

    return 0;
}

// } Driver Code Ends
