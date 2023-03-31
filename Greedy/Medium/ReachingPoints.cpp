class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        
        // we go from bottom to top
        // 10 18 came from 10 8 it came from 2 8 then 2 6 then 2 4
        while(sx <=tx && sy <=ty)
        {
            //if tx ty reduced to sx sy then possible
            if(sx == tx && sy == ty)
            {
                return true;
            }
            // we can use mod operator to do multiple subtractions in 
            // in 1 time
            // until tx > ty we have to subtract ty from tx

            // tx is more than ty so it came from (tx % ty , ty)
            if(tx > ty)
            {
                // this is the edge case
                3,9 to 3,3
                // (3,9) (3,6) (3,3) (3,0) then it would be not possible
                // so if smaller of tx or ty matching to corresponding sx,sy
                // then take the difference and check if that difference is divisible
                // by smaller tx or ty
                if(ty == sy)
                {
                    int temp = tx - sx;
                    if(temp % ty ==0 )
                        return true;
                    else
                        return false;
                }
                tx = tx % ty;
            }
            else if( ty > tx)
            {
                if(tx == sx)
                {
                    int temp = ty-sy;
                    if(temp % tx == 0)
                        return true;
                    else
                        return false;
                }
                ty = ty % tx;
            }
            else
            {
                if(tx == sx && ty == sy)
                    return true;
                else
                    return false;
            }
        }
        return false;
    }
};
