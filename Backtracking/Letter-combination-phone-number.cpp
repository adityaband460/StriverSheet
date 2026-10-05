// TC O(n*4^n)

class Solution {
public:

    void solve(string &digits,int currInd, string &curr ,vector<string>&ans,vector<string>&map)
    {
        int n = digits.size();
        //base case
        if(currInd == n)
        {
            ans.push_back(curr);
            return;
        }
        //rec case

        int mapInd = digits[currInd] - '0';
        string letters = map[mapInd];
        for(char letter : letters)
        {
            curr.push_back(letter);
            solve(digits,currInd+1,curr,ans,map);
            curr.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0)
        {
            return {};
        }
        vector<string> map = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string curr = "";
        vector<string> ans;
        solve(digits,0,curr,ans,map);
        return ans;
    }
};
