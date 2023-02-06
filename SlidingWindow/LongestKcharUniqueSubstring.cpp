//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
    int i=0,j=0;
    int maxlen = -1;
    unordered_map<char,int>freq;// keep track of frequency of chars
    int n = s.length();
    
        while(j < n)
        {
            // just add chars to map
            if(freq.find(s[j]) == freq.end())
            {
                freq[s[j]] = 1;
            }
            else
            {
                freq[s[j]]++;
            }
            
            // num of chars in curr substring is less than k
            // so we can add more chars by increasing window size
            if(freq.size() < k)
            {
                j++;
            }
            // num of chars in curr substring is more than k
            // so we increment i to reduce dist chars in substring
            else if(freq.size() > k)
            {
                
                while(freq.size() > k)
                {
                    freq[s[i]]--;
                    //if freq of char becomes 0 remove that char
                    // from map
                    if(freq[s[i]] <= 0)
                    {
                        freq.erase(s[i]);
                    }
                    i++;
                }
                // increment j so that it wont and current j again to freq map again
                j++;
            }
            else // num of distinct ele in substring is = k
            {
                maxlen = max(maxlen,j-i+1);
                j++;
            }
        }
        return maxlen;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends
