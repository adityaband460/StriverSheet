//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
  
    bool equalPartition(int arr[],int n,int sum,vector<vector<int>>&table)
    {
        for(int j=0;j<sum+1;j++)
        {
            table[0][j] = 0;
        }
        for(int i=0;i<n+1;i++)
        {
            table[i][0] = 1;
        }
        
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<sum+1;j++)
            {
                if(arr[i-1] <= j)
                {
                    table[i][j] = (table[i-1][j-arr[i-1]] ||table[i-1][j]);
                }
                else
                {
                    table[i][j] = table[i-1][j];
                }
            }
        }
        return table[n][sum];
    }
	int minDifference(int arr[], int n)  { 
	  
	   int sum = 0;
	   for(int i=0;i<n;i++)
	   {
	       sum += arr[i];
	   }
	   vector<vector<int>> table(n+1,vector<int>(sum+1,-1));
	   equalPartition(arr,n,sum,table);
	   
	   
	   // scan the last row
	   // it will give all possible sums considering n elements
	   // choose sum which give minimum difference
	   // closest to sum/2;
	   int partition1 = sum/2;
	   int mindiff = INT_MAX;
	   for(int i=partition1;i>=0;i--)
	   {
	       if(table[n][i] > 0)
	       {
	           return (sum - 2*i);
	       }
	   }
	   //return mindiff;
	    
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends
