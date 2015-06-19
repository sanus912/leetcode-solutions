#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;


class Solution {
public:

    int maxProduct(vector<int>& A) {
        int maxP = A[0], minP = A[0], res = A[0]; 
        for (int i = 1; i < A.size(); i++) {
            int mx = maxP, mn = minP;
            maxP = max(max(A[i], mx * A[i]), mn * A[i]);
            minP = min(min(A[i], mx * A[i]), mn * A[i]);
            res = max(maxP, res);
        }
        return res;
    }
    
    //由0和0 或 0和负数分隔开
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int f = 1;
        int b = 1;
        int res = INT_MIN;
        for (int i = 0;i<n;i++)
        {
            f *= nums[i];
            b *= nums[n-1-i];
            res = max(res,max(f,b));
            if(f==0) f=1;
            if(b==0) b=1;
        }
        return res;
    }

};

int main() {

    Solution mySol;
    const int s = 8;
    int myarr[s] = {-4,2,3,-2,4,1,-8,2};
    
    cout << mySol.maxProduct(myarr,s) << endl;





    return 0;
}
