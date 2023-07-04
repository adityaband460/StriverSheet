int mod = 1e9+7;
	int psum(int arr[],int n, int sum, vector<vector<int>> &table)
	{
	    // so that we will always cover all possibilities
	    // even if input is 0 0 1
	    // we will go till 0 the element
	    // if sum = 0 means we will take that set
	    // if sum !=0 means with no elements we can't subset of elements with sum !=0
	    if(n==0)
	    {
	        if(sum != 0)
	            return 0;
	        if(sum == 0)
	            return 1; 
	    }
        
	   //recursive case
	   if(table[n][sum] != -1)
	        return table[n][sum];
	   if(arr[n-1] <= sum )
	   {
	       return (table[n][sum] =
	       ( psum(arr,n-1,sum-arr[n-1],table) + 
	       psum(arr,n-1,sum,table))%mod);
	   }
	   else
	   {
	       return table[n][sum] = psum(arr,n-1,sum,table);
	   }
	   
	}
	int perfectSum(int arr[], int n, int sum)
	{
	    vector<vector<int>> table(n+1, vector<int>(sum+1, -1));
	   
	    // fill the 1st row
	    for(int i=0;i<sum+1;i++)
	    {
	        if(i == 0)
	            table[0][i] = 1;
	        else
	            table[0][i] = 0;
	    }
	   // for(int i=0;i<n+1;i++)
	   // {
	   //     table[i][0] = 1;
	   // }
	    
	    // fill remaining table
	    for(int i=1;i<n+1;i++)
	    {
	        for(int j=0;j<sum+1;j++)
	        {
	            if(arr[i-1] <= j)
	            {
	                table[i][j] = (table[i-1][j] + table[i-1][j-arr[i-1]])%mod;
	            }
	            else
	            {
	                
	             table[i][j] = table[i-1][j] ;
	            }
	        }
	    }
	    return table[n][sum];
        // return psum(arr,n,sum,table);
	}
