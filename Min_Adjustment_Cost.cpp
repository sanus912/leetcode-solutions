#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    int MinAdjustmentCost(vector<int> A, int target) {
        int res=0;
        if(A.empty()) 
            return res;

        int n = A.size();
        
        int v = 100;
        vector<vector<int>> f(n+1, vector<int>(v+1,INT_MAX));
        
        f[1][A[0]]=0;
        for (int i = 1;i<=v;i++)
            f[1][i] = abs(A[0]-i);
        
        for (int i=2;i<=n;i++)
            for (int j=1;j<=v;j++)
            {
                for (int k=max(j-target,1);k<=min(j+target,v);k++)
                    f[i][j] = min(f[i][j], f[i-1][k]);
                
                f[i][j] += abs(A[i-1]-j);
            }
        
        int minC=INT_MAX;
        for (int i = 1;i<=v;i++)
            minC = min(minC, f[n][i]);
        return minC;
    }
};

int main() {
    vector<int> A = {1,4,2,3};

    Solution mySol;
    cout << mySol.MinAdjustmentCost(A,1) << endl;
    return 0;
}
