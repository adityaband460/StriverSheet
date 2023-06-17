//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> kthLargest(int k, int arr[], int n) {
        // minHeap
        priority_queue<int,vector<int>,greater<int>> minHeap;
      /*  
        An Efficient Solution is to use Min Heap of size k to store k largest elements of 
        stream. Thr k'th largest element is always at root and can be found in O(1) time.
        How to process a new element of stream?
        Compare the new element with root of heap.
        If new element is smaller, then ignore it.
        Otherwise replace root with new element and call 
        heapify for the root of modified heap. */
                vector<int> ans;
        for(int i=0;i<n;i++)
        {
           if(minHeap.size() < k)
           {
               minHeap.push(arr[i]);
           }
           else // either size will be less than k or k
           {
               // insert only if new element is greater than kth largest
               // i.e. element on top of min heap
               if(arr[i] > minHeap.top())
               {
                   minHeap.pop();
                   minHeap.push(arr[i]);
                   // minHeap size will be k now and kth largest in on top
               }
           }
           
           if(minHeap.size() < k)
                ans.push_back(-1);
            else
                ans.push_back(minHeap.top());
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int k,n;
        cin>>k>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];

        Solution ob;
        vector<int> v = ob.kthLargest(k,arr,n);
        for(int i : v)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
