//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
  bool static compare(pair<int,int> a , pair<int,int> b)
  {
        if(a.first != b.first)
        {
            //min heap greater<int> use  a > b
            return a.first > b.first;
        }
        else
        {
            //descending order
            return a.second > b.second;
        }
  }
    vector<int> topK(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            freq[nums[i]]++;
        }
        //min heap
        priority_queue<pair<int,int>,vector<pair<int,int>>,
        decltype(&compare)>minH(&compare);
        // for(const auto&pair : freq)// pass by ref to avoid copies
        // {
        //     cout<<pair.first<<" ";
        // }cout<<endl;
        
        for(const auto&pair : freq)// pass by ref to avoid copies
        {
            minH.push({pair.second,pair.first});
            
            if(minH.size() > k)
            {
                // cout<< minH.top().second<<" is poped \n";
                minH.pop();
            }
        }
        vector<int> ans;
        while(minH.size()>0)
        {
            ans.push_back(minH.top().second);
            
            minH.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (auto &i : nums) cin >> i;
        int k;
        cin >> k;
        Solution obj;
        vector<int> ans = obj.topK(nums, k);
        for (auto i : ans) cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
