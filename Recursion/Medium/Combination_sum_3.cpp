 void csum3(int ind,int sum,int k,vector<int>temp,vector<vector<int>>&output)
    {
        //base case
        //way to end recursion is either ind becomes 10 or digits get 0
        if(ind == 10 ||k==0)
        {
            //only if we have exact k digitss and all add up to N
            if(k==0 && sum == 0)
            {
                output.push_back(temp);
            }
            return;
        }
        
        //rec case
        if(ind <= sum)
        {
        //take it
            temp.push_back(ind);
            csum3(ind+1,sum-ind,k-1,temp,output);
            temp.pop_back();
        }
        
            //leave it
            csum3(ind+1,sum,k,temp,output);
        
        
    }
    vector<vector<int>> combinationSum(int K, int N) {
        
        //vector<int>arr = {1,2,3,4,5,6,7,8,9};
        vector<vector<int>>output;
        vector<int>temp;
        csum3(1,N,K,temp,output);
        
        return output;
    }
