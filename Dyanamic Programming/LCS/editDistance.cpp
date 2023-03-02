class Solution {
public:
    int min(int a,int b)
    {
        if(a < b)
            return a;
        else 
            return b;
    }
    int min3(int a,int b ,int c)
    {
       return min(a,min(b,c));             
    }
    int solve(string s1,string s2, int n , int m,vector<vector<int>>&table)
    {
        // when any of string gets empty
        if(n==0)
           { return m;}
        if(m ==0)
            {return n;}
        
        if(table[n][m] != -1)
            return table[n][m];
        //rec case
        if(s1[n-1] == s2[m-1])
        {
            return table[n][m] = solve(s1,s2,n-1,m-1,table);
        }
        else
        {
        int insertions = 1 + solve(s1,s2,n,m-1,table);
        int deletions = 1 + solve(s1,s2,n-1,m,table);
        int replaces = 1 + solve(s1,s2,n-1,m-1,table);

        return table[n][m] = min3(insertions,deletions,replaces);
        }
        
    }
    int tabularization(string s1,string s2, int n , int m,vector<vector<int>>&table)
    {
        for(int i=0;i<n+1;i++)
        {
            table[i][0] = i;
        }
        for(int j=0;j<m+1;j++)
        {
            table[0][j] = j;
        }
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<m+1;j++)
            {
                if(s1[i-1] == s2[j-1])
                {
                     table[i][j] = table[i-1][j-1];
                }
                else
                {
                    table[i][j] = min3(1+table[i-1][j-1],1+table[i-1][j],1+table[i][j-1]);
                }
               
            }
        }
        return table[n][m];
    }
    int spaceopti(string s1,string s2, int n , int m)
    {
        vector<int>prev(m+1,-1),curr(m+1,-1);
        for(int j=0;j<m+1;j++)
        {
            prev[j] = j;
            curr[j] = j;
        }
        for(int i=1;i<n+1;i++)
        {
            for(int j=0;j<m+1;j++)
            {
                if(j == 0)
                {
                    curr[j] = i;
                    continue;
                }
                if(s1[i-1] == s2[j-1])
                {
                    curr[j] = prev[j-1];
                }
                else
                {
                    curr[j] = min3(1+prev[j-1],1+prev[j],1+curr[j-1]);
                }
               
            }
            prev = curr;
        }
        return curr[m];
    }
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        vector<vector<int>>table(n+1,vector<int>(m+1,-1));
        return spaceopti(word1,word2,n,m);
    }
};
