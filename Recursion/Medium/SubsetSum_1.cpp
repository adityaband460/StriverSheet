    void ssum(vector<int>arr,int sum,int i,vector<int>&ans)
    {
        if(i>=arr.size())
        {
            ans.push_back(sum);
            return;
        }
        
        sum += arr[i];
        ssum(arr,sum,i+1,ans);
        sum -= arr[i];
        
        
        ssum(arr,sum,i+1,ans);
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
       vector<int>ans;
       ssum(arr,0,0,ans);
       return ans;
    }
