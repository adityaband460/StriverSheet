//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}
// } Driver Code Ends
//User function Template for C++    
class Solution
{
    public:
class Data{
        public :
        int val;
        int apos;
        int vpos;    
            Data(int v,int ap,int vp)
            {
                val = v;
                apos = ap;
                vpos = vp;
            }
    };
    class myComparator{
        public:
        // for min heap
        // par > child then swap
        bool operator()(const Data& d1,const Data& d2) const
        {
            return d1.val > d2.val;
        }
    };
   
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        //minheap
        priority_queue<Data,vector<Data>,myComparator> minHeap;
        
        // for all rows
       for(int i=0;i<arr.size();i++)
       {
           //push all first elements in all arrays
           minHeap.push(Data(arr[i][0],i,0));
       }
       vector<int> ans;
       
       while(minHeap.size() > 0)
       {
           Data d = minHeap.top();
           ans.push_back(minHeap.top().val);
           minHeap.pop();
           
           if(d.vpos+1 < arr[d.apos].size())
           minHeap.push(Data(arr[d.apos][d.vpos+1],d.apos,d.vpos+1));
           
       }
       return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}
// } Driver Code Ends
