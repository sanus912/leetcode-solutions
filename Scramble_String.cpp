#include <iostream>
#include <vector>
#include <cstdlib>
#include <map>
using namespace std;



class Solution {
public:
    bool isScramble(string s1, string s2) {     // 水中的鱼 or Mitbbs
        
        const int n = s1.size();
        if(n == 0 || n != s2.size()) return false;
        if(s1 == s2) return true;
        
        int v1, v2;
        v1 = v2 = 0;
        for(int i = 0; i < n; i++) {
            v1 += s1[i];
            v2 += s2[i];
        }
        if(v1 != v2)  return false;
        
        for(int i = 1; i < n; i++) {
            if(isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i)) ) return true;
            if(isScramble(s1.substr(0, i), s2.substr(n-i, i)) && isScramble(s1.substr(i), s2.substr(0, n-i)) ) return true;
        }

        return false;
    }


    bool isScramble_2(string s1, string s2) {  // DP too slow
            
        const int N = s1.size();
        if( N != s2.size() ) return false;
        vector<vector<vector<bool> > > dp(N+1, vector<vector<bool > >(N, vector<bool>(N, false)));

        for (int i =0;i<N;i++)
            for (int j =0;j<N;j++)
                    dp[1][i][j] = s1[i] == s2[j];

        for (int n = 2; n <= N; n++)
            for (int i =0;i+n<=N;i++)
                for (int j =0;j+n<=N;j++)
                    for(int k = 1; k <n; k++) {
                        if( (dp[k][i][j] && dp[n-k][i+k][j+k]) || (dp[k][i][j+n-k] && dp[n-k][i+k][j])) {
                            dp[n][i][j] = true;
                            break;
                        }
                    }


        return dp[N][0][0];
    }
};



int main() {

    Solution mySol;
    string s1("great");
    string s2("rgeat");

    bool ans = mySol.isScramble(s1, s2);
    if(ans)
        cout << s1 << " and " << s2 << " are scrambled strings? Yes! " << endl;
    else
        cout << s1 << " and " << s2 << " are scrambled strings? No! " << endl;
    return 0;
}
