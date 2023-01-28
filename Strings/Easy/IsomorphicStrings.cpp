//{ Driver Code Starts
// C++ program to check if two strings are isomorphic


#include<bits/stdc++.h>


using namespace std;
#define MAX_CHARS 256

// } Driver Code Ends
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        if(str1.length() != str2.length())
            return 0;
       
        unordered_map <char,char> encoding1;
        unordered_map <char,char> encoding2;
        
        for(int i=0;i<str1.length();i++)
        {
            if(encoding1.find(str1[i]) == encoding1.end())
            {
               encoding1[str1[i]] = str2[i];
            }
            else
            {
                if(encoding1[str1[i]] != str2[i] )
                    return false;
            }
            if(encoding2.find(str2[i]) == encoding2.end())
            {
               encoding2[str2[i]] = str1[i];
            }
            else
            {
                if(encoding2[str2[i]] != str1[i] )
                    return false;
            }
        }
        
        return true;
        
    }
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}
// } Driver Code Ends
