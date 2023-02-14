//{ Driver Code Starts
// Initial Template for C++



#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int pageFaults(int N, int C, int pages[]){
        // code here
        unordered_map<int,int>frames;
        for(int i=1;i<=C;i++)
        {
            frames[-i] = -1;
        }
        int pageFaults = 0;
        for(int i=0;i<N;i++)
        {
            if(frames.find(pages[i]) == frames.end())
            {
                pageFaults++;
                // search a correct position for current page
                int minIndex = N ,evictedPage;
                for(auto ele : frames)
                {
                    if(ele.second < minIndex)
                    {
                        minIndex = ele.second;
                        evictedPage = ele.first;
                    }
                }
                
                frames.erase(evictedPage);
                frames[pages[i]] = i;
            }
            else
            {
                frames[pages[i]] = i;
            }
        }
        return pageFaults;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, C;
        cin>>N;
        int pages[N];
        for(int i = 0;i < N;i++)
            cin>>pages[i];
        cin>>C;
        
        Solution ob;
        cout<<ob.pageFaults(N, C, pages)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
