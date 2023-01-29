//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    
    int checkInt(char ch)
    {
        int val = ch - '0';
        if(val >=0 && val <= 9)
            return val;
        return -1;
    }
    int atoi(string str) {
        //Your code here
        int ans = 0;
        int multiplier = 1;
        int n = str.length();
        for(int i= n-1;i>=0;i--)
        {
            int val = checkInt(str[i]);
            if(val != -1)
            {
                ans += val * multiplier;
                
            }
            else 
            {
                if(i==0 && str[i]=='-')
                    return -1*ans;
                else
                    return -1;
            }
            multiplier *= 10;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends
