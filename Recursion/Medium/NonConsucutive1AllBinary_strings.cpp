//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    void helper(int num,int i,string temp,vector<string>&output,char prev)
    {
        if(i>num)
        {
            output.push_back(temp);
            return;
        }
        
        
        //rec case
        // no restriction on 0s
    
        temp.push_back('0');
        helper(num,i+1,temp,output,'0');
        temp.pop_back();
        
        
        
        // but if prev == 1 then don't call on 1
        //cout<<prev<<" prev is this\n";
        if(prev != '1')
        {
            temp.push_back('1');
            helper(num,i+1,temp,output,'1');
        }
        
    }
    void generateBinaryStrings(int num){
        
        vector<string>output;
        helper(num,1,"",output,'#');
        for(int i=0;i<output.size()-1;i++)
        {
            cout<<output[i]<<" ";
        }
        cout<<output[output.size()-1];
        
    }
};

//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;


    while(t--){
        //Input
        int n; cin >> n;

        Solution obj;
        obj.generateBinaryStrings(n);
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends
