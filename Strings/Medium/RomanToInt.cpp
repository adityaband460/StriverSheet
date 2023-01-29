//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int romanToDecimal(string &str) {
       
        unordered_map<char,int>roman;
        roman['I'] = 1;
        roman['V'] = 5;
        roman['X'] = 10;
        roman['L'] = 50;
        roman['C'] = 100;
        roman['D'] = 500;
        roman['M'] = 1000;
        
        int val = 0;
        int n = str.length();
        //MCMXCIV = 1994
        
        val += roman[str[n-1]];
        // start from back till start
        for(int i=n-2;i>=0;i--)
        {
            if(roman[str[i]] >= roman[str[i+1]])
                val += roman[str[i]];
            else
                val -= roman[str[i]];
        }
        return val;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends
