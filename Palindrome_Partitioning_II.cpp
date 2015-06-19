#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int minCut(string s) {

        const int n = s.size();
        int f[n+1];//前i个数的minCut
        bool p[n][n];
        memset(p,false,sizeof(p));

        for(int i = 0; i <=n; i++) {
            f[i] = i-1;
        }

        for( int i = 0; i < n; i++) {
            for( int j = 0; j <=i; j++) {
                if( s[i] == s[j] && (i-j<2 || p[j+1][i-1])) {
                    p[j][i] = true;
                    f[i+1] = min(f[i+1],f[j]+1);
                }
            }
        }

        return f[n];
    }    
};


int main() {

    string myStr("cdd");
    Solution mySol;

    cout << "The minimum cuts number we need : " << mySol.minCut(myStr) << endl;

    return 0;
}
