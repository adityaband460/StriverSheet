//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        
        unordered_map<char,int>freq;
        int n = p.length();
        
        // store char and theire freq in freq map
        for(int i=0;i<n;i++)
        {
            freq[p[i]]++;
        }
        // now n is length of string s
        
        int i=0,j=0;
        n = s.length();
        int minlen = n+1;
        string minstr = "-1";
        // count of unique chars in map
        int count = freq.size();
        while(j < n)
        {
            if(freq.find(s[j]) ==  freq.end() )
            {
                j++;
            }
            else
            {
                freq[s[j]]--;
                // if after reducint char freq is becomes zero then
                // reduce the count
                if(freq[s[j]] == 0)
                { 
                    count--;
                }
                // if count becomes 0 then substring has P
                // now move i till count becomes non zero again
                while(count == 0)
                {
                    //minlen = min(minlen , j-i+1);
                    // if window size is less than minlen then update it
                    // also update minstr
                    if(minlen > j-i+1)
                    {
                        minstr = s.substr(i,j-i+1);
                        minlen = j-i+1;
                    }
                    // if letter is not in freq map then just move on
                    if(freq.find(s[i]) == freq.end())
                    {
                        i++;
                    }
                    // if found then increase freq of that char
                    // freq of char is -ve means we have extra chars and window size can
                    // be reduced by increasing i
                    // so if freq of char get to 1 
                    // then count will increase as we need that char 1 time in that window
                    // 
                    else
                    {
                        freq[s[i]]++;
                        
                        if(freq[s[i]] == 1)
                        {
                            count++;
                        }
                        i++;
                    }
                }
                
                j++;
            }
        }
        //cout<<minlen<<endl;
        return minstr;
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
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends
