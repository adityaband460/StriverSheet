class Solution {
public:

    bool isPalindrome(const string &s, int l, int r)
    {
        while(l < r)
        {
            if(s[l] != s[r])
                return false;

            l++;
            r--;
        }

        return true;
    }

    void solve(const string &s,
               int start,
               vector<string>& curr,
               vector<vector<string>>& ans)
    {
        int n = s.size();

        // Base case
        if(start == n)
        {
            ans.push_back(curr);
            return;
        }

        // Try every possible substring starting at start
        for(int end = start; end < n; end++)
        {
            if(isPalindrome(s, start, end))
            {
                curr.push_back(s.substr(start, end - start + 1));

                solve(s, end + 1, curr, ans);

                curr.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> ans;
        vector<string> curr;

        solve(s, 0, curr, ans);

        return ans;
    }
};
