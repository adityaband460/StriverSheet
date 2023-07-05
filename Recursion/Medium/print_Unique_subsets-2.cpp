    void printUniqSubset(vector<vector<int>>&ans,vector<int>nums,int ind,vector<int>&curr)
    {
        ans.push_back(curr);
        for(int i=ind;i<nums.size();i++)
        {
            if(ind != i && nums[i]==nums[i-1]) continue;
            curr.push_back(nums[i]);
            printUniqSubset(ans,nums,i+1,curr);
            curr.pop_back();
        }
    }
    vector<vector<int>> printUniqueSubsets(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>curr;
        printUniqSubset(ans,nums,0,curr);
        return ans;
    }
