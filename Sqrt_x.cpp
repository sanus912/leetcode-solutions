#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cassert>

using namespace std;

int sum;

class Solution {
public:
    //~binary search
    int mySqrt(int x) {
        if (x == 0)
            return 0;
        int left = 1, right = x;
        while (left<=right) {
            int mid = left + (right - left)/2;
            if (mid > x/mid) {
                right = mid - 1;
            } else {
                if (mid + 1 > x/(mid + 1))
                    return mid;
                left = mid + 1;
            }
        }
        return -1;
    }
    
    int sqrt(int x)
    {
        long lo = 0;
        long hi = x;
        while(lo <= hi)
        {
            long mid = lo+(hi-lo)/2;
            if (x<mid*mid)
                hi = mid-1;
            else
                lo = mid+1;
        }
        return (int)hi;
    }

    int sqrt_2(int x) {
        if (x==0) return 0;
        else if (x>0 && x<4) return 1;
        else
        {
            int left=1;int right = x/2;
            int last_mid;
            while (left<=right)
            {
                int mid = left + ((right-left)>>1);
                if (x/mid>mid)
                {
                    left = mid+1;
                    last_mid = mid;
                }
                else if (x/mid < mid)
                    {right = mid-1;}
                else
                    return mid;
                    
            }
            return last_mid;
        }
    }

    int sqrt_1(int x) {
        
        assert(x >= 0);

        if(x == 0) return 0;
        double xp, xn = x;
        
        do {
            xp = xn;
            xn = xp -  0.5 * (xp * xp -x) / xp; 
        } while(fabs(xp - xn) > 0.001);
        
        return int(xn);
    }


};
        

int main() { 

    Solution mySol;
   
    for(int n=1; n < 6; n++)
        cout << "sqrt( " << n << ") = " << mySol.sqrt(n) << endl;

    for(int n=1; n < 6; n++)
        cout << "sqrt( " << n << ") = " << mySol.sqrt_2(n) << endl;

    return 0; 
}
