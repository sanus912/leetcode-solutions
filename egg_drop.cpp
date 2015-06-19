#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:

    int drop2(int n)
    {
        vector<int> f(n+1,INT_MAX);
        f[0] = 0;
        for(int i = 1; i<=n; i++)
            for(int r = 1; r<=i; r++)
                    f[i] = min(f[i], max(f[i-r], r-1)+1);
        
        return f[n];
        
    }

    int drop(int n, int k)
    {
        vector<vector<int>> f(n+1,vector<int>(k+1,INT_MAX));
        for(int i = 0; i<=n; i++)
        {    
            f[i][1] = i;
        }
        for(int i = 0; i<=k; i++)
            f[0][i] = 0;

        for(int i = 1; i<=n; i++)
            for(int j = 2; j<=k; j++)
            {
                for(int r = 1; r<=i; r++)
                    f[i][j] = min(f[i][j], max(f[i-r][j], f[r-1][j-1])+1);
            }
        
        return f[n][k];
        
    }
};

int main() { 

    Solution mySol;

    cout << mySol.drop2(100) << endl;
    cout << mySol.drop(100,3) << endl;

    return 0; 
}
