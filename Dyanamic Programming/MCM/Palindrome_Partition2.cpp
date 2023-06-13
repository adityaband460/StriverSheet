//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
// function to check palindrome
    bool isPalindrome(string &str,int i,int j)
    {
        while(i<j)
        {
            if(str[i] != str[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    int mincuts(int i,string &str,vector<int > &dp)
    {
        int n = str.length();
        //base case
        if(dp[i] != -1) return dp[i];
        
        if(isPalindrome(str,i,n-1)) // is string is already pali 0 cuts needed
            return 0;
        // if(i==n-1) // at end f(n-1,str) will be called//no need to be honest
        // return 0; // as 1 letter will be palindrome so returned by above condition
        
       int mini = 1e9;
       //rec case
       for(int ind=i+1;ind<n;ind++)
       {
           // call only if left partion is palindrome
           if(isPalindrome(str,i,ind-1)) 
           {
               //then total cuts= 1for partion + cuts for right partition
               int cuts = 1 + mincuts(ind,str,dp);
               mini = min(mini,cuts);
           }
           
       }
       return dp[i] = mini;
    }
    int palindromicPartition(string str)
    {
        // int n = str.length();
        // vector<int>dp(n,-1);
        // return mincuts(0,str,dp);
        
        //tabulation
        
        //to make it O(n*n)
        // precompute all substrings whether they are palindrome or not
        // then just look up from that 2d array in O(1)
        int n = str.length();
        vector<int>dp(n,1e9);
        vector<vector<bool>>palicheck(n,vector<bool>(n,false));
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                palicheck[i][j] = isPalindrome(str,i,j);
            }
        }
        
        
        for(int i=n-1;i>=0;i--)
        {
            //base case
            if(palicheck[i][n-1]) // is string is already pali 0 cuts needed
            {
                dp[i] = 0;
                continue;
            }
           //rec case
            int mini = 1e9;
            for(int ind=i+1;ind<n;ind++)
            {
             
              // call only if left partion is palindrome
              if(palicheck[i][ind-1]) 
              {
                  //then total cuts= 1for partion + cuts for right partition
                  int cuts = 1 + dp[ind];
                  mini = min(mini,cuts);
              }
               
            }
            dp[i] = mini;
        }

        return dp[0];
        
    }

};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
