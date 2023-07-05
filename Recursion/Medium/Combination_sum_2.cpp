void csum2(int ind,int target,vector<int>temp,vector<vector<int>>&output,
    vector<int>arr)
    {
        if(target == 0)
        {
            output.push_back(temp);
            return;
        }
        int n = arr.size();
        if(ind == n)return;
        
        for(int i=ind;i<n;i++)
        {
            
            if(i != ind && arr[i]==arr[i-1]) continue;
            // check if that ele is capable of getting inserted
            
            if(arr[i]<=target)
            {
                temp.push_back(arr[i]);
                csum2(i+1,target-arr[i],temp,output,arr);
                temp.pop_back();
            }
            else
                break;
        }
        
        
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>output;
        vector<int>temp;
        csum2(0,target,temp,output,candidates);
        return output;
        
    }
