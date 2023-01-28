#include <bits/stdc++.h>
using namespace std;

bool SortSecond(pair<int,int> a,pair<int,int>b)
{
    if(a.second != b.second)
    {
        return (a.second > b.second);//descending order of second
    }
    else
    {// if both equal then ascending order of first
        return (a.first < b.first);
    }
}
int main()
 {
	//code
	int T ;
	cin>>T;
	while(T--)
	{
	    int N;
	    cin>>N;
        
        int temp;
        int map[61] = {0};
        int arr[N];
        for(int i=0;i<N;i++)
        {
            cin>>temp;
            arr[i] = temp;
            map[temp]++;
        }
        vector<pair<int,int>>freqPair;
        for(int i=0;i<61;i++)
        {
            if(map[i] != 0)
            {
                freqPair.push_back({i,map[i]});
            }
        }
        sort(freqPair.begin(),freqPair.end(),SortSecond);
        
        for(int i=0;i<freqPair.size();i++)
        {
            for(int j=0;j<freqPair[i].second;j++)
            cout<<freqPair[i].first<< " ";
        }
        cout<<endl;
	    
	}
	
	
	return 0;
}
