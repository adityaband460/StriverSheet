class Solution {
public:

    int countSubsetSum(vector<int>&nums,int sum,int n, vector<vector<int>> &table)
    {
        if(n==0)
        {
            if(sum ==0)
                return 1;
            else
                return 0;
        }
        if(table[n][sum] != -1)
            return table[n][sum];
        
        if(nums[n-1] <= sum)
        {
            return table[n][sum] = countSubsetSum(nums,sum-nums[n-1],n-1,table)+
                                        countSubsetSum(nums,sum,n-1,table);
        }
        else
        {
            return table[n][sum]= countSubsetSum(nums,sum,n-1,table);
        }
    }
    int findTargetSumWays(vector<int>& nums, int target) 
    {
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum += nums[i];
        }    

        if((sum - target)%2 != 0 )
        {
            return 0;
        }
        // sum-target should lie between 0 and 2*sum
        int val = sum-target;
        if( !(val <= 2*sum && val >= 0) )
            return 0;
        // else do the calculations
        int n = nums.size();
        vector<vector<int>> table(n+1,vector<int>(sum+1,-1));
        int partitionsum1 = (sum-target) / 2;
            return countSubsetSum(nums,partitionsum1,n,table);


    }
};
