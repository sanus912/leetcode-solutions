#include <iostream>
#include <cmath>
#include <bitset>
using namespace std;

class Solution {
public:
     int divide(int dividend, int divisor) {

        long long a = dividend>=0? dividend: -(long long)dividend;
        long long b = divisor>=0? divisor: -(long long)divisor;
        long long res = 0;

         while (a >= b) {

             long long c = b;
             for(int i = 1;  a >= c; i *= 2, c *= 2){ 
                 a -= c;
                 res += i;
             }
         }

         if( (dividend^divisor)>>31)
             res = -res;
         
         if (res > INT_MAX)
             return INT_MAX;
         else
             return res;
    
    }
};

int main() {

    Solution mySol;
    int a = INT_MIN;
    int b = -1;

    cout << INT_MAX << " = " << bitset<32>(INT_MAX) << endl;
    cout << INT_MIN+1 << " = " << bitset<32>(INT_MIN+1) << endl;
    cout << -1 << " = " << bitset<32>(-1) << endl;

    int res = mySol.divide(a, b);
    cout << "result = " << res << endl;

    cout << "a/b = " << a/b << endl;



    return 0;
}
