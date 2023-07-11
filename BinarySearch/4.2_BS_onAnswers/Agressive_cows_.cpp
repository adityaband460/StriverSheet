 bool isPossible(vector<int> &stalls,int n ,int k,int mid)
    {
        k--;
        int prev = stalls[0]; 
        // always keep 1st cow in 1st stall
        for(int i=1;i<n;i++)
        {
            if(stalls[i]-prev >= mid)
            {
                k--;
                prev = stalls[i];
            }
            // if(k <= 0) // to handle underflow
            // {
            //     return true;
            // }
        }
        if(k <= 0) //possible
            return true;
        else   // not possible
           return false;
        
    }
    int solve(int n, int k, vector<int> &stalls) {
        sort(stalls.begin(),stalls.end());
        // with 2 cows max is possible , with n cows 1 is guaranted
        int max = stalls[n-1], min = stalls[0];
        int copyk = k;
       // possible answers
       
       int low = 1,high = max-min;
       int ans = -1;
       while(low <= high)
       {
           int mid = (low+high)/2;
           
           if(isPossible(stalls,n,k,mid))
           {
               ans = mid;
               low = mid+1;//move right
           }
           else
           {
               high = mid -1;
           }
       }
        
        
        return ans;
    }
