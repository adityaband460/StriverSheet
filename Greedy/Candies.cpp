//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  // my first apporach 
  /*
        sort array of rating,index 
        so that we get indexes of of elements in order if reating were sorted
        ex : 
    rating:     1 3 0 2                   0 1 2 3
    index:      0 1 2 3  after sorting    2 0 3 1 
    
    then traverse index array and check elements neighbour and give candies , +1 if 
    his rating is greater than neighbours
  */
  
  // optimal apporach
    int minCandy(int N, vector<int> &ratings) {
        vector<int> candies(N,1);
        // travel from left to right
        // check if curr if greater than prev
        for(int i=1;i<N;i++)
        {
            if(ratings[i] > ratings[i-1])
            {
                candies[i] = candies[i-1]+1;
            }
        }
        // travel from left to right
        // check if curr if greater than next
        
        // choose max of above generated ans and temp
        for(int i= N-2;i>=0;i--)
        {
            if(ratings[i] > ratings[i+1])
            {
                int temp = candies[i+1]+1;
                candies[i] = max(temp,candies[i]);
            }
        }
        int sum =0;
        for(int i=0;i<N;i++)
        {
            sum += candies[i];
        }
        return sum;
       
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> ratings(N);
        for (int i = 0; i < N; i++) {
            cin >> ratings[i];
        }
        Solution obj;
        cout << obj.minCandy(N, ratings) << endl;
    }
    return 0;
}
// } Driver Code Ends
