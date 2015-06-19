#include <iostream>
using namespace std;


class Solution {
public:

    int minSubArray(int A[], int n) {
        int f = 0;//前0个数最小和为0
        int res = INT_MAX;
        for (int i = 0;i<n;i++)
        {
            f = min(f,0)+A[i];
            res = min(res,f);
        }
        return res;
    }
        
};


int main() {

    const int s = 9;
    int Arr[s] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    const int t = 5;
    int Arr1[t] = {-7, -1, -4, -6, -3};
    int max;

    Solution mySol;

    max = mySol.minSubArray(Arr, s);
    cout << " The maximum of subarray is " << max <<endl;
    cout << endl;

    max = mySol.minSubArray(Arr1, t);
    cout << " The maximum of subarray1 is " << max <<endl;

    return 0;
}
