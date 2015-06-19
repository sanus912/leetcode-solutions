#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:

    int maxTwoSubArrays(vector<int> nums) {
        const int n = nums.size();
        int m = 2;
        if (n<m) return 0;
        
        vector<int> f(m+1,0);
        vector<int> g(m+1,0);
        
        for(int i = 1; i <= n; i ++) {
            
            for(int j = min(i, m); j > 0; j--) {
                if (i>j){
                    f[j] = max(f[j], g[j-1]) + nums[i-1];
                    g[j] = max(f[j], g[j]);
                }
                else if (i==j)
                {
                    f[j] = g[j-1] + nums[i-1];
                    g[j] = f[j];
                }
            }
        }
       
        return g[m];
    }
        
    int maxTwoSubArrays_2(vector<int> nums) {
        const int n = nums.size();
        int m = 2;
        if (n<m) return 0;
        vector<vector<int>> f(n+1, vector<int>(m+1,0));
        vector<vector<int>> g(n+1, vector<int>(m+1,0));

        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=min(m,i);j++)//j<=i
            {
                if(i>j)
                {
                    f[i][j] = max(g[i-1][j-1], f[i-1][j]) + nums[i-1];
                    g[i][j] = max(g[i-1][j],f[i][j]);
                }
                else if (i==j)
                {
                    f[i][j] = g[i-1][j-1] + nums[i-1];
                    g[i][j] = f[i][j];
                }
            }
        }

        return g[n][m];
    }
};


int main() {

   
    vector<int> v = {-1,-1};

    Solution mySol;

    int max = mySol.maxTwoSubArrays(v);
    cout << " The maximum of subarray is " << max <<endl;
    cout << endl;

    max = mySol.maxTwoSubArrays_2(v);
    cout << " The maximum of subarray_2 is " << max <<endl;

    return 0;
}
