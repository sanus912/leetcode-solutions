#include <iostream>
#include <cmath>
#include <bitset>
using namespace std;

class Solution {
public:
     int fastPower(int a, int b, int n) {
        if (n==0) return 1%b;
        long v = fastPower(a,b,n/2);
        v *= v;
        v %= b;
        if (n%2==1)
            v *= a%b;
        v%=b;
        return v;
    }
};

int main() {

    Solution mySol;
    int a = 2;
    int b = 3;
    int n = 11;

    cout << mySol.fastPower(a,b,n) << endl;



    return 0;
}
