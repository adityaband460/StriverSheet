class Solution {
  public:
  
  
  // assuming e1 e2 are sorted
    // bool overlap(vector<int>e1,vector<int>e2)
    // {
    //     if(e2[0] < e1[1])
    //         return true;
        
    //     return false;
    // }
  //for extra optimization
  // I commmented compare code
    // bool static compare(vector<int>e1,vector<int>e2)
    // {
    //     return e1[0]<e2[0];
    // }
    int minRemoval(int N, vector<vector<int>> &intervals) {
        
        if(N <= 1)
            return 0;
        // code here
        // sort the intervals
        sort(intervals.begin(),intervals.end());
        
        // if 2 intervals intersect then remove the interval who ends last
        // keep interval who ends first so it is less likely to intersect next intervals
        // as array is sorted
       
        
        int count = 0;
        
        int end = intervals[0][1];
        for(int i=1;i<N;i++)
        {
            // check if overlap is there
            if(intervals[i][0] < end)
            {
                count++;
                end = min(end,intervals[i][1]);
            }
            else
            {
                end = intervals[i][1];
            }
        }
        return count;
        
        
    }
};
