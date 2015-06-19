#include <iostream>
#include <cstdlib>

using namespace std;

class Solution {
public:

    bool checkPowerOf2(int n) {
        if (n==0) return false;
        if (n == INT_MIN) return false;
        return ((n&n-1)==0);
    } 

};

int main() { 

    Solution mySol;

    for(int n=0;n<10;n++)
        cout << n << " : " << mySol.checkPowerOf2(n) << endl;

    return 0; 
}
