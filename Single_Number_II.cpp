#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>
using namespace std;


class Solution {
public:
    int singleNumber(int A[], int n) {
        
        int res = 0;
        
        for(int b = 0; b < 32; b++) {
            int count = 0;
            for(int i = 0; i < n; i++) 
                count += (A[i]>>b) & 1;
            count %= 3;
            res += (count<<b);
        }
        
        return res;        
    }

};


int main(int argc, char ** argv) {

    const int s = 11;
    int myArr[s] = {1, 2, 3, 4, 3, 1, 2, 1, 2, 3, 4};
    Solution mySol;

    int single = mySol.singleNumber(myArr, s);
    cout << "The single one is : " << single <<endl;


    return 0;
}
