#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:

    int uniquePaths(int m, int n) {
        vector<vector<int>> f(m,vector<int>(n,0));
        f[0][0]=1;
        for(int i=1;i<m;i++)
            f[i][0] += f[i-1][0];
        for(int i=1;i<n;i++)
            f[0][i] += f[0][i-1];
        for (int i=1;i<m;i++)
            for (int j=1;j<n;j++)
            {
                f[i][j] = f[i-1][j] + f[i][j-1];
            }
        return f[m-1][n-1];
        
    }
    
    int uniquePaths(int m, int n) {
        vector<int> f(n+1,1);
        
        for (int i=1;i<m;i++)
            for (int j=1;j<n;j++)
            {
                f[j] += f[j-1];
            }
        return f[n-1];
    }

};    

int main() {

    Solution mySol;

    cout << mySol.uniquePaths(10, 10) << endl;


    return 0;
}
