	void shortest_distance(vector<vector<int>>&matrix){
	    
	    int n = matrix.size();
	    
	    for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]== -1)
                    matrix[i][j] = 1e9;
            }
            
            matrix[i][i] = 0;
        }
        // floyd warshall all pair shortest
        // adj matrix
	    // go via 0 , 1 ,2 ... n
	    for(int via = 0; via <n;via++)
	    {
	        // travel matrix for each via
	        for(int i=0;i<n;i++)
	        {
	            for(int j=0;j<n;j++)
	            {
	               if(matrix[i][via] != 1e9 and matrix[via][j] != 1e9)
                   {
                    matrix[i][j] = min(matrix[i][j],
                    matrix[i][via] + matrix[via][j]);
                   }
	            }
	        }
	    }
	     for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]== 1e9)
                    matrix[i][j] = -1;
            }
        }
	}
