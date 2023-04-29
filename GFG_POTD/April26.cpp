//User function Template for C++
// https://practice.geeksforgeeks.org/problems/6bb49b563cc171335c6564b00307a6d867e0268d/1
class Solution{
    public:
    bool is_possible_to_get_seats(int n, int m, vector<int>& seats){
        
        int validpos = 0;
        //check both ends first
        if(seats[0] == 0 && seats[1] == 0)
        {
            validpos++;
            seats[0] = 1;
        }
        if(seats[m-1]==0 && seats[m-2 ]==0)
        {
            validpos++;
            seats[m-1] = 1;
        }
        for(int i=1;i<m;i++)
        {
            if(seats[i-1]==0 && seats[i]==0 && seats[i+1]==0)
            {
                validpos++;
                seats[i] = 1;
                i++;//skip next position also extra optimization
            }
        }
        if(validpos >= n) return true;
        else return false;
    }
};
