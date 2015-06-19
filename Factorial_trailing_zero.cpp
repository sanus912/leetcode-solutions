#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cassert>

using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        if ( n<0 ) return -1;
        int count = 0;
        for (long i=5; n/i>=1; i*=5) {
            count += n / i;
        }        
        return count;
    }
};
        

int main() { 

    Solution mySol;
   
    for(int n=1; n <= 25; n++)
        cout << n << "! has " << mySol.trailingZeroes(n) <<" zeros"<< endl;

    return 0; 
}
