// adj mat is given
    bool isPossible(bool graph[101][101],int color[],int n,int node,int col)
    {
        for(int k=0;k<n;k++)
        {
            // not itslef and adj node , its col matches
            if(node != k && graph[node][k]==1 && color[k]==col)
                return false;
            
        }
        return true;
    }
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool solve(bool graph[101][101],int m,int n,int color[],int node)
    {
        if(node== n)
            return true;
        
        //rec case
        for(int col =1;col<=m;col++)
        {
            if(isPossible(graph,color,n,node,col))
            {
                color[node] = col;
               if(solve(graph,m,n,color,node+1)) return true; 
                color[node] = 0;
            }
            
        }
        return false;
    }
    bool graphColoring(bool graph[101][101], int m, int n) {
        int color[n];
        memset(color,0,sizeof(color));
        return solve(graph,m,n,color,0);
    }
