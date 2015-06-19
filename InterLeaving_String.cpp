#include <iostream>
#include <vector>
#include <string>
using namespace std;


 
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.length() + s2.length() != s3.length()) {
            return false;
        }
        
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> f(n+1, vector<int>(m+1,0));
        f[0][0] = true;
        
        for (int i = 1; i <= n; i++) {
            if(s3[i - 1] == s1[i - 1] && f[i - 1][0])
                f[i][0] = true;
        }
        
        for (int j = 1; j <= m; j++) {
            if(s3[j - 1] == s2[j - 1] && f[0][j - 1])
                f[0][j] = true;
        }
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if((s3[i + j - 1] == s1[i - 1] && f[i - 1][j])
                    || (s3[i + j - 1] == s2[j - 1] && f[i][j - 1]))
                f[i][j] = true;
            }
        }
        
        return f[n][m];
    }
};

int main() {

    Solution mySol;
    string s1("aa");
    string s2("ab");
    string s3("abaa");
 

    bool is = mySol.isInterleave(s1, s2, s3);
    if(is)
        cout << s1 << " and " << s2 << " Yes!" << endl;
    else
        cout << s1 << " and " << s2 << " No!" << endl;

    return 0;
}
