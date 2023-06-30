 long long power(int N,int R)
    {
      //base case
      if(R == 1)
        return N;
        
        //rec case
        long long tmp = power(N,R/2);
        tmp = (tmp*tmp) % mod;
        if(R&1 == 1)//odd number
        {
           tmp = ( tmp * N) % mod; 
        }
        return tmp;
        
    }
