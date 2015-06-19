#include<iostream>
#include<cmath>
#include<vector>
using namespace std;


class Solution {
public:
    //-43%10=-3
    int reverse(int x) {
        int res = 0;
        while (x)
        {
            if (abs(res) > INT_MAX/10)//不必判断==，因为如果==INT_MAX/10,最后一位肯定是1，不overflow
                return 0;
            res = res * 10 + x%10;
            x /= 10;
        }
        return res;
    }
};


int main(int argc, char ** argv) {

    Solution rrr;

    for( int i =123; i<135; i++ )
        cout << rrr.reverse(i) << endl;

    cout << (-3)%10 << endl;
    return 0;
}
