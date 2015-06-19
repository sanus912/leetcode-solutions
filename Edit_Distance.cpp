#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> f(n+1,vector<int>(m+1,INT_MAX));
        for (int i = 0;i<=n;i++)
        f[i][0] = i;
        for (int i=1;i<=m;i++)
        f[0][i] = i;
        for (int i=1;i<=n;i++)
            for (int j =1;j<=m;j++)
            {
                if (word1[i-1] == word2[j-1]){
                    f[i][j] = f[i-1][j-1];
                }
                else
                {
                    f[i][j] = min(f[i-1][j-1]+1,f[i-1][j]+1);
                    f[i][j] = min(f[i][j],f[i][j-1]+1);
                }
            }
        
        return f[n][m];
    }
};

int main() {

    Solution mySol;
    string s1("tea");
    string s2("eat");


    int ans = mySol.minDistance(s1, s2);

    cout << "The edit distance between  " << s1 << " and " << s2 << " = "<< ans << endl;


    return 0;
}
