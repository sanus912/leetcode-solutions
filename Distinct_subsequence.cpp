#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
using namespace std;

class Solution {
public:
    int numDistinct(string &S, string &T) {
        int n = S.size();
        int m = T.size();
        vector<vector<int>> f(n+1, vector<int>(m+1,0)); 
        for (int i = 0; i<=n;i++)
            f[i][0] = 1;
            
        for (int i = 1; i<=m;i++)
            f[0][i] = 0;
            
        for (int i = 1; i<=n;i++)
            for (int j = 1; j <= m ; j++)
            {
                if (S[i-1]==T[j-1]){
                    f[i][j] = f[i-1][j]+f[i-1][j-1];
                   
                }else{
                    f[i][j] = f[i-1][j];
                    
                }
            }
        return f[n][m];
    }
};

int main() {

    Solution mySol;
    string s1("ABCDE");
    string s2("ACE");


    cout << mySol.numDistinct(s1, s2) << endl;

    return 0;
}
