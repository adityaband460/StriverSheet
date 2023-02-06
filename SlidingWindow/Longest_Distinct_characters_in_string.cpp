//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestSubstrDistinctChars (S) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends


int longestSubstrDistinctChars (string S)
{
    // your code here
    int n = S.length();
    int i = 0,j = 0;
    int maxlen = 0;
    unordered_map<char,int>freq;
    while( j < n)
    {
        while(j < n && freq.find(S[j]) == freq.end() )
        {
           
            freq[S[j]] = 1;
            j++;
           // cout<<S[j]<<" inserted\n";
            //cout<<"maxlen = "<<maxlen<<"\n";
        }
        
            maxlen = max(maxlen,j-i);
            if(j == n) break;
    
             
             
            freq[S[j]]++;
            while(freq[S[j]] != 1)
            {
                freq[S[i]]--;
                
                // imp step if frequency of a char becomes 0 then remove it
                // so that it can again be added as freq 1
                
                if(freq[S[i]] == 0)
                    freq.erase(S[i]);
                
              //  cout<<S[i]<<" erased\n";
                i++;
            }
        

        j++;
    }
    return maxlen;
}
