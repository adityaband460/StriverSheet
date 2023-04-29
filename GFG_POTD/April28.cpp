
// https://practice.geeksforgeeks.org/problems/5a1277ffc1ec1d3a63d1a5d6b3920dd3d1294261/1
// geeks village and wells
//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void bfs(vector<vector<char>>c,vector<vector<int>>&output,
    queue<pair<pair<int,int>,int>> &q,vector<vector<int>>&visited)
    {
        while(!q.empty())
        {
            int n = c.size();
            int m = c[0].size();
            pair<pair<int,int>,int>curr = q.front();
            
            int x = curr.first.first;
            int y = curr.first.second;
            int k = curr.second;
           
            visited[x][y] = 1;
            
            q.pop();
            
            int d4i[] = {0,1,0,-1};
            int d4j[] = {1,0,-1,0};
            
            for(int i=0;i<4;i++)
            {
                int nx = x + d4i[i];
                int ny = y + d4j[i];
                
                //  cout<<"nx = "<<nx<<" ny ="<<ny<<" nk = "<<k<<endl;
                if(nx >= 0 && nx < n && ny >= 0 && ny < m 
                && visited[nx][ny] == -1 && c[nx][ny] != 'N')// valid index & not visited
                {
                    output[nx][ny] = min(output[nx][ny],k+2);
                    visited[nx][ny] = 1;
                    q.push({{nx,ny},output[nx][ny]});
                }
            }
        }
        
    }
    vector<vector<int>> chefAndWells(int n,int m,vector<vector<char>> &c){
        vector<vector<int>>output(n,vector<int>(m,1e9)),visited(n,vector<int>(m,-1));
        // i , j , distance
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(c[i][j]=='W')
                {
                    output[i][j] = 0;
                    q.push({{i,j},0});
                }
            }
        }
        if(q.size())
            bfs(c,output,q,visited);
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(c[i][j] != 'H')
                {
                    output[i][j] = 0;
                }
                if(output[i][j] == 1e9)
                {
                    output[i][j] = -1;
                }
            }
        }
        return output;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<char>> c(n,vector<char>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>c[i][j];
            }
        }
        Solution ob;
        vector<vector<int>> res=ob.chefAndWells(n,m,c);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<res[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}
// } Driver Code Ends
