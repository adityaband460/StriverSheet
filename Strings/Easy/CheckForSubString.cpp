//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int strstr(string ,string);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string a;
        string b;
        
        cin>>a;
        cin>>b;
        
        cout<<strstr(a,b)<<endl;
    }
}

// } Driver Code Ends


//Function to locate the occurrence of the string x in the string s.
int strstr(string s, string x)
{
    int j =0;
    int i = 0;
    int previ = 0;
    while(i<s.length())
    {
        while(s[i] == x[j])
        {
            
            i++;
            j++;
            
            if(j==x.length())
            {
                return i-j;
            }
        }
        previ++;
        i = previ;
        j = 0;
    }
    return -1;
}
