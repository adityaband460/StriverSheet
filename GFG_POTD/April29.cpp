//{ Driver Code Starts
//Initial Template for C++
// https://practice.geeksforgeeks.org/problems/35bff0ee40090b092e97b02f649085bf1390cc67/1
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    // find n th number which is d digits
    void fun(long long n,string &ans,char arr[],long long p)
    {
        // cout<<"n = "<<n<<" p = "<<p<<endl;
        //base case
        if(p == 0){ return;};
        //rec case
        
        // p = p / 5;
        int k = 1;
        while(n > p)
        {
            n = n - p;
            k++;
        }
        ans.push_back(arr[k-1]);
        
        fun(n,ans,arr,p/5);
    }
    long long findNumber(long long N){
        // find closest 5 power to number N
        char odd[] = {'1','3','5','7','9'};
        long long p = 5,k=1;
        while(N > p)
        {
            N = N - p;
            p = p * 5;
            k = k + 1;
        }
        string ans="";
        fun(N,ans,odd,p/5);
        // cout<<ans<<endl;
        long long realans = 0;
        realans = stol(ans);
        return realans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long long N;
        cin>>N;
        Solution ob;
        cout<<ob.findNumber(N)<<endl;
    }
    return 0;
}
// } Driver Code Ends
