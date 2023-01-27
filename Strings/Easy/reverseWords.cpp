//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    void swap(string &s1,string &s2)
    {
        string temp = s1;
        s1 = s2;
        s2 = temp;
    }
    //Function to reverse words in a given string.
    string reverseWords(string s) 
    { 
        // code here 
        vector<string>arr;
        string temp="";
        for(int i=0;i<s.length();i++)
        {
            
            if(s[i]=='.')
            {
                arr.push_back(temp);
                temp = "";
                continue;
            }
            temp.push_back(s[i]);
            if(i == s.length()-1)
            {
                arr.push_back(temp);
                temp = "";
            }
        }
        int n = arr.size();
        for(int i=0;i<n/2;i++)
        {
            swap(arr[i],arr[n-1-i]);
        }
        string ans = "";
        for(int i=0;i<n;i++)
        {
            ans += arr[i];
            if(i != n-1)
            ans.push_back('.');
        }
        return ans;
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends
