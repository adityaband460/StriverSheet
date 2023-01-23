//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool lemonadeChange(int N, vector<int> &bills) {
        // code here
    
        int change5 =0;
        int change10 =0;
        
        for(int i=0;i<N;i++)
        {
            if(bills[i]==5)
            {
                change5++;
            }
            else if(bills[i]==10)
            {
                change10++;
                change5--;
                
                if(change5 < 0)
                    return false;
            }
            else if(bills[i]==20)
            {
                if(change10 > 0 && change5 > 0)
                {
                    change10--;
                    change5--;
                }
                else if(change5 >= 3 )
                {
                    change5 -=3;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> bills(N);
        for (int i = 0; i < N; i++) cin >> bills[i];

        Solution obj;
        int ans = obj.lemonadeChange(N, bills);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends
