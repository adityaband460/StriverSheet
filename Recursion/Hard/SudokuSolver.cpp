//Function to find a solved Sudoku. 
    int N= 9;
    bool isValid(int grid[N][N],int i,int j,int num)
    {
        //row
        for(int k=0;k<N;k++)
        {
            if(grid[i][k] == num)return false;
        }
        //col
        for(int k=0;k<N;k++)
        {
            if(grid[k][j] == num)return false;
        }
        //3x3 box
        int ri = i-i%3;
        int rj = j-j%3;
        for(int row=0+ri;row<=2+ri;row++)
        {
            for(int col=0+rj;col<=2+rj;col++)
            {
                if(grid[row][col]==num)
                    return false;
            }
        }
        return true;
    }
    
    bool solve(int grid[N][N],int i,int j)
    {
        
        //base
        if(i==N-1 && j==N)
        {
            // printGrid (grid); cout<<endl;
            return true;
        }
        if(j==N)
        {
            i++;
            j=0;
        }
        if(grid[i][j] != 0)
        {
            return solve(grid,i,j+1);
        }
        
        for(int num=1;num<=9;num++)
        {
            if( isValid(grid,i,j,num))
            {
                grid[i][j] = num;
                if(solve(grid,i,j+1))
                    return true;
                else
                    grid[i][j] = 0;
            }
    
       
        }
        
        return false;
       
    }
    bool SolveSudoku(int grid[N][N])  
    { 
       return solve(grid,0,0);
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                cout<<grid[i][j]<<" ";
            }
        }
    }
