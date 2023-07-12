bool isPossible(int A[],int N,int mid,int stud)
    {
        int sum = A[0];
        stud--;
        for(int i=1;i<N;i++)
        {
            if(sum + A[i] > mid)
            {
                stud--;
                sum = A[i];
            }
            else
            {
                sum += A[i];
            }
        }
        if(stud < 0) return false;
        
        return true;
    }
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        if(M > N) return -1;
        
        int sum = A[0], maxPages=A[0];
        for(int i=1;i<N;i++)
        {
            sum += A[i];
            maxPages = max(A[i],maxPages);
        }
        
        int low = maxPages , high = sum;
        int ans = -1;
        while(low <= high)
        {
            int mid = (low+high)/2;
            
            if(isPossible(A,N,mid,M))
            {
                //go left
                ans = mid;
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }
        return ans;
    }
