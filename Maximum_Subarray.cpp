#include <iostream>
using namespace std;


class Solution {
public:

    int maxSubArray(int A[], int n) {
        int f = 0;//前0个数最大和为0
        int res = INT_MIN;
        for (int i = 0;i<n;i++)
        {
            f = max(f,0)+A[i];
            res = max(res,f);
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

    max = mySol.maxSubArray(Arr, s);
    cout << " The maximum of subarray is " << max <<endl;
    cout << endl;

    max = mySol.maxSubArray(Arr1, t);
    cout << " The maximum of subarray1 is " << max <<endl;

    return 0;
}
