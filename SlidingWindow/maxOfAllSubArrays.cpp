vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        // to store indexs of max numbers
        deque<int>dq;
        int i=0,j=0;
        while(j-i+1 <= k)
        {
            //pop back un-necessary element in dq
            while(!dq.empty() && nums[dq.back()] <= nums[j])// try with < op
            {
                dq.pop_back();
            }
            dq.push_back(j);
            j++;
        }
        
        ans.push_back(nums[dq.front()]);
        int n = nums.size();
        while( j < n)
        {
            // invalid due to window sliding further
            if(!dq.empty() && dq.front()== i)
            {
                dq.pop_front();
            }
            i++;
            //pop back smaller than nums[j] from dq
            while(!dq.empty() && nums[dq.back()]<= nums[j])
            {
                dq.pop_back();
            }
            dq.push_back(j);
            
            ans.push_back(nums[dq.front()]);
            j++;
        }
        return ans;
    }
