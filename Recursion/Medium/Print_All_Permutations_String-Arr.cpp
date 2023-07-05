	// just use set to store unique permutations
	// ex : ABB
	// op should be : ABB BAB BBA
	void f(string s,set<string>&ans,int ind)
	{
	    //base case
	    if(ind >= s.size())
	    {
	        ans.insert(s);
	        return;
	    }
	    //rec case
	    for(int i=ind;i<s.length();i++)
	    {
	        swap(s[i],s[ind]);
	        f(s,ans,ind+1);
	        swap(s[i],s[ind]);
	    }
	}
		vector<string>find_permutation(string S)
		{
		    sort(S.begin(),S.end());
		    set<string>ans;
		    f(S,ans,0);
		    vector<string>result;
		    for(auto it : ans)
		    {
		        result.push_back(it);
		    }
		    return result;
		}
