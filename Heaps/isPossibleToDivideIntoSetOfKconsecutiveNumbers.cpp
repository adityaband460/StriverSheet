//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
   bool isPossibleDivide(vector<int>& nums, int k) {
        unordered_map<int,int>freqMap;
      // Count the occurrences of each number
        for(int i=0;i<nums.size();i++)
        {
            freqMap[nums[i]]++;
        }
// Sort the numbers in ascending order
        sort(nums.begin(),nums.end());
        // Iterate through the numbers
        for(int i=0;i<nums.size();i++)
        {
            if(freqMap[nums[i]] == 0)
            {
                continue;
            }
// Check consecutive numbers
            for(int j = nums[i];j < nums[i]+k ;j++)
            {
                if(freqMap[j] == 0)
                    return false;
                freqMap[j]--;
            }
        }
        return true;
    }
    bool isStraightHand(int N, int groupSize, vector<int> &hand) {
       
         return isPossibleDivide(hand,groupSize);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, groupSize;
        cin >> N >> groupSize;

        vector<int> hand(N);
        for (int i = 0; i < N; i++) cin >> hand[i];

        Solution obj;
        int ans = obj.isStraightHand(N, groupSize, hand);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends
