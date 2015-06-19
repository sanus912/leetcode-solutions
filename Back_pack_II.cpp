#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    int backPackII(int m, vector<int> A, vector<int> V) {
        int res=0;
        if(A.empty()) 
            return res;

        int n = A.size();
        
        vector<vector<int>> f(n+1, vector<int>(m+1,0));
        for (int i = 1; i<=m; i++)
            f[0][i]=INT_MIN;
        for (int i = 0;i<=n;i++)
            f[i][0] = 0;
        
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
            {
                f[i][j] = f[i-1][j];
                if (j>=A[i-1])
                    f[i][j] = max(f[i][j],f[i-1][j-A[i-1]]+V[i-1]);
            }
        
        int maxV= 0;
        for (int i = 1; i<=m; i++)
        if (f[n][i]>maxV)
        maxV = f[n][i];

        return maxV;
    }
};

int main() {
    vector<int> A = {2,3,5,7};
    vector<int> V = {1,5,2,4};

    Solution mySol;
    cout << mySol.backPackII(10,A,V) << endl;
    return 0;
}
