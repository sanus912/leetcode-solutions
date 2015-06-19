#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;


class Solution {
public:
    int singleNumber(int A[], int n) {

        if ( n<=0 ) return -1;

        int res = 0;
        for(int i = 0; i < n; i++)
            res ^= A[i];

        return res;
    }
};


int main(int argc, char ** argv) {

    const int s = 6;
    int myArr[s] = {2, 3, 4, 3, 2};
    Solution mySol;

    int single = mySol.singleNumber(myArr, s);
    cout << "The single one is :" << single <<endl;


    return 0;
}
