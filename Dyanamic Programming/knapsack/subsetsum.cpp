//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool f(vector<int>arr,int sum,int n,vector<vector<int>>&table)
    {
        if(n ==0 && sum != 0)
        { 
            return table[n][sum] = 0;
        }
        if(sum == 0)
        {
             return table[n][sum]= 1;
        }
        if(table[n][sum] != -1)
        {
            return table[n][sum];
        }
        if(arr[n-1] <= sum)
        {
            return table[n][sum] = (f(arr,sum-arr[n-1],n-1,table) || f(arr,sum,n-1,table));
        }
        else
        {
            return table[n][sum] = f(arr,sum,n-1,table);
        }
            
    }

    
    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        vector<vector<int>>table(arr.size()+1,vector<int>(sum+1,-1));
        
        for(int i=0;i<sum+1 ;i++ )
        {
            table[0][i] = false;
        }
        for(int i=0;i<n+1 ;i++ )
        {
            table[i][0] = true;
        }
        // i j = n sum
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<sum+1;j++)
            {
                if(arr[i-1] <= sum)
                {
                    table[i][j] = table[i-1][j-arr[i-1]] || table[i-1][j];
                }
                else
                    table[i][j] = table[i-1][j];
            }
        }
        return table[n][sum];
    //   return f(arr,sum,arr.size(),table);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends
