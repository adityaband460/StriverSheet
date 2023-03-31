//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int power2(int i)
    {
        return 1<<i;
    }
    void bitManipulation(int num, int i) {
        int mask = power2(i-1);
        int a1;
        
        //get i the bit
        if((num & mask) == 0)
        {
            a1 = 0;
        }
        else
        {
            a1 = 1;
        }
        // set i ith bit
        int a2 = num | mask;
        // clear i the bit
        
        int a3 = num & ~mask;
        
        cout<<a1<<" "<<a2<<" "<<a3;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n >> i;
        Solution ob;
        ob.bitManipulation(n, i);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
