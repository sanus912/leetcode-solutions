#include<iostream>
#include<cmath>
#include<vector>
using namespace std;


class Solution {
public:
    uint32_t reverseBits(uint32_t x) {
        uint32_t y = 0;
        int count = 32;
        while(count--) {
            y = 2*y + (x%2);
            x /= 2;
        }

        return y;
    }
};

uint32_t reverseBits(uint32_t n) {
    uint32_t m = 0;
    uint32_t b;
    int i = 0;
    while(i < 32){
        b = n & 1; // get the last bit of current n
        n = n >> 1;
        m = (m << 1) | b;
        i ++;
    }

    return m;
}


int main(int argc, char ** argv) {

    Solution mySol;

    cout << mySol.reverseBits(1) << endl;

    return 0;
}
