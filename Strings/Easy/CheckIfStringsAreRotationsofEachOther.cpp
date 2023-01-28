//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if two strings are rotations of each other or not.
    bool areRotations(string s1,string s2)
    {
        // Your code here
        if(s1.length() != s2.length())
            return false;
            
        int n = s1.length();
        int count = 0;
        int i=0,j=0;
        int prevJ =0;
        while(j < n)
        {
            
            while(s1[i] == s2[j])
            {
                i =  (i+1)%n;
                j =  (j+1)%n;
                count++;
                 if(count == n && s1[i] == s2[j]) // last Character should also match
                    return true;
                 else if(count == n && s1[i] != s2[j])
                    return false;
                // if(s1[i] != s2[j])
                //     j = (j-1)%n;
            }
            i = 0;
            count = 0;
            j = prevJ + 1;
            prevJ++;
        }
        return false;
        
    }
};
// another way
/* bool areRotations(string s1,string s2)
    {
        if(s1.length()!=s2.length())
            return false;
        else
        {
            //we concatenate first string to itself and check if other 
            //string occurs in it as substring. If yes, then it 
            //is rotated version and we return true else false.
            string concated=s1+s1;
            if(concated.find(s2)!=string::npos)
                return true;
            else
                return false;
        }
    }
*/


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s1;
        string s2;
        cin>>s1>>s2;
        Solution obj;
        cout<<obj.areRotations(s1,s2)<<endl;

    }
    return 0;
}

// } Driver Code Ends
