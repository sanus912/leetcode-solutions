#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    int backPack(int m, vector<int> A) {
        int res=0;
        if(A.empty()) 
            return res;

        int n = A.size();
        
        vector<vector<bool>> f(n+1, vector<bool>(m+1,false));
        for (int i =1;i<=m;i++)
        f[0][i] = false;
        for (int i = 0;i<=n;i++)
        f[i][0] = true;
        
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
            {
                f[i][j] = f[i-1][j];
                if (j>=A[i-1] && f[i-1][j-A[i-1]])
                    f[i][j] = true;
            }
        
        for (int i = m; i>=0; i--)
        if (f[n][i])
            return i;
        
        return 0;
	}
};

int main() {
    vector<int> A = {2,3,5,7};

    Solution mySol;
    cout << mySol.backPack(11,A) << endl;
    return 0;
}
