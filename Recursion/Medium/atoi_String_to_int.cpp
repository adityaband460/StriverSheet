// n is size of string
    int atoiH(string str,int n)
    {   //base case
        if(n==0) return 0;
        int val = str[n-1]-'0';
        if(val < 0 || val > 9)// non int
        {
            return -1;
        }
        //rec case
        int ans = atoiH(str,n-1);
        if(ans == -1)
            return -1;
        ans = ans*10 + str[n-1]-'0';
            return ans;
    }
    int atoi(string str) {
        bool isNegative = false;
        if(str[0]=='-')
        {
            string newStr = str.substr(1,str.size()-1);
            // cout<<newStr<<" new\n";
            int ans = atoiH(newStr,newStr.size());
            
            if(ans ==-1)return -1;
            else return -ans;
        }
        else
        {   int ans = atoiH(str,str.size());
            return ans;
        }
    }
