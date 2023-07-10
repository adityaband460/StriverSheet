int totalHours(vector<int>&piles,long long banPerHr,long long limit)
    {
        int ans = 0;
        for(int i=0;i<piles.size();i++)
        {
            ans += ceil((double) piles[i]/ (double)banPerHr);
            if(ans > limit) return 0;
        }
        return 1;
    }
    int Solve(int N, vector<int>& piles, int H) {
         if(N>H)return -1;
        int maxn=piles[0],minn=piles[0];
        
        for(int i=0;i<N;i++)
        {
            if(piles[i]<minn)
            {
                minn = piles[i];
            }
            else if(maxn < piles[i])
            {
                maxn = piles[i];
            }
        }
        
        int low = 1,high = maxn;
        int ans = maxn;
        while(low<=high)
        {
            int mid = (low+high)/2;
            
            if(totalHours(piles,mid,H) == 1)//total eating hrs finshed under H time
            {
                ans = mid;
                high = mid -1;
            }
            else
            {
                low = mid+1;
            }
        }
        // cout<<ans<<" \n";
        return ans;
    }
