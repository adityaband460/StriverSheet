//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    priority_queue<int>maxHeap; // to store the left sorted half
    priority_queue<int,vector<int>,greater<int>>minHeap;  // to store the right sorted half
    //Function to insert heap.
  // here we are keeping extra element always in maxHeap so in case of odd numbers median is maxHeap.top();
  // max Heap has smallest elements and min heap has greatest elements
  //
  
    void insertHeap(int &x)
    {
      // initially max heap will be empty or
      // if new element is less than or equal to (gretest among smaller half elements) then it can change the left smallest sorted half ,
      //no way it can go in greater half also
      
      //     6
      // 3 5  7  8            9 10 11 12
      //  left half            right half
        if(maxHeap.empty() || x <= maxHeap.top())
        {
            maxHeap.push(x);
        }
      // if it is greater then it will go in right half
        else
        {
            minHeap.push(x);
        }
        balanceHeaps();
        
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
      //when toatal numbers that we have = n , n is odd then we want extra element in only maxHeap
      // so remove it from minheap and put in max Heap
         if(minHeap.size() > maxHeap.size())
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
      // when maxheap has 2 extra elements then extra can go to min Heap
        if(maxHeap.size() == minHeap.size()+2)
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
    }
    
    //Function to return Median.
    double getMedian()
    {
        if(minHeap.size() == maxHeap.size())
        {
            // cout<<"min top,max top :"<<minHeap.top()<<" "<<maxHeap.top();
            return double(minHeap.top()+maxHeap.top())/2.0;
        }
        else
        {
            return maxHeap.top();
        }
    }
};


//{ Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}
// } Driver Code Ends
