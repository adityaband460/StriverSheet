//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


// } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    
    void helper(int n,int lcount,int rcount,string temp, int i,vector<string>&output)
    {
        // base case 
        // note that any bracket is not added yet
        if(i > n)
        {
            if(lcount == rcount)
            {
                output.push_back(temp);
            }
            return;
        }
        
        // no restriction for adding ( bracket
        temp.push_back('(');
        lcount++;
        helper(n,lcount,rcount,temp,i+1,output);
        
        // if lcount is greater than r count then we can add ) bracket
        temp.pop_back();
        lcount--;
        if(lcount > rcount)
        {
            temp.push_back(')');
            rcount++;
             helper(n,lcount,rcount,temp,i+1,output);
        }
       
        
    }
    vector<string> AllParenthesis(int n) 
    {
        vector<string>output;
        helper(2*n,0,0,"",1,output);
        return output;
    }
};

//{ Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 

// } Driver Code Ends
