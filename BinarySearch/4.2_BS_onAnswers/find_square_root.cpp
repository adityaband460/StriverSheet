long long int floorSqrt(long long int x) 
    {
        if(x==1||x==2 || x== 3)return 1;
        
        long long low = 1,high = x-1;
        long long ans = 1;
        while(low<=high)
        {
            long long mid = (low+high)/2;
            
            if(mid * mid == x)
            {
                return mid;
            }
            else if(mid*mid < x)
            {
                ans = mid;
                low = mid+1;
            }
            else
            {
                high = mid-1;
            }
        }
        return ans;
    }
