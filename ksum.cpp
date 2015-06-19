#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int kSum(vector<int> A, int k, int target) {
        int res=0;
        if(A.empty()) 
            return res;

        int n = A.size();
        
        vector<vector<vector<int>>> f(n+1, vector<vector<int>>(k+1, vector<int>(target+1,0)));
        for (int i = 1; i<=target; i++)
            f[0][0][i] = 0;
        for (int i = 0;i<=n;i++)
            f[i][0][0] = 1;
        
        for (int i=1;i<=n;i++)
            for (int j=1;j<=k;j++)
                for (int t=1;t<=target;t++)
                {
                    if (j<=i)
                    {
                        f[i][j][t] = f[i-1][j][t];
                        if (t>=A[i-1])
                            f[i][j][t] += f[i-1][j-1][t-A[i-1]];
                    }
                }

        return f[n][k][target];
    }

};

int main() {

    const int s = 6;
    int myArr[s] = {1, 2, 4, 5, 7, 15};
    int target = 6;
    vector<int> myv;

    myv.assign(myArr, myArr+s);
    cout << "Size of myv: " << int (myv.size()) << endl;

    Solution mySol;
    cout << mySol.kSum(myv, 2, target) << endl;

    return 0;
}
