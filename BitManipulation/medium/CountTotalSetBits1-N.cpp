//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    
   
    
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits(int n)
    {
        if(n==0 || n==1)
            return n;
            
        int sum = 0;
        //1)find greatest power of 2 less than or equal to n
        int t = n;
        int x = 0;
        while(t>0)
        {
            x++;
            t = (t>>1);
        }
        x--;
        int twoPowerx = 1<<x;
       
        
        //2) calculate ans for ((2^x) - 1)
        
        sum += (twoPowerx/2) * x;
        
        //3) calculate from that 2^x to n
        
        sum += (n - twoPowerx + 1); // all 1's at msb position
        
        // then remaining will look like from 000 to some number
        // calculate recursively
         sum += countSetBits(n - twoPowerx);
        
        return sum;
        
    }
};


//{ Driver Code Starts.

// Driver code
int main()
{
	 int t;
	 cin>>t;// input testcases
	 while(t--) //while testcases exist
	 {
	       int n;
	       cin>>n; //input n
	       Solution ob;
	       cout << ob.countSetBits(n) << endl;// print the answer
	  }
	  return 0;
}

// } Driver Code Ends
