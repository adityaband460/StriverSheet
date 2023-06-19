class Solution {
  public:
    vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
        
        //maxHeap
        // int,pair<int,int> is better than vector
        priority_queue<pair<int,pair<int,int>>>maxHeap;
        //set
        set<pair<int,int>>combinations;
        sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        //push sum with indices so that 
        // after popping we can calculate next 2 possible candidates
        maxHeap.push({A[N-1]+B[N-1],{N-1,N-1}});
        
        vector<int> ans;
        while(K > 0)
        {
            pair<int,pair<int,int>>temp = maxHeap.top();
            maxHeap.pop();
            ans.push_back(temp.first);
            K--;
            
            int i = temp.second.first;
            int j = temp.second.second;
            //push next 2 candidates if they are not already present
            if(i>0 && combinations.find({i-1,j}) == combinations.end())
              { 
                  maxHeap.push({A[i-1]+B[j],{i-1,j}});
                  combinations.insert({i-1,j});
              }
            
            if(j>0 && combinations.find({i,j-1}) == combinations.end())
            {
                maxHeap.push({A[i]+B[j-1],{i,j-1}});
                combinations.insert({i,j-1});
            }
            
        }
        return ans;
    }
};
