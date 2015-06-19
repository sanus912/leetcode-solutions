#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:

    //上三角形 DP
    void Palindrome_DP(string s) {

        int n = s.size();
        if (n==0)
            return;
        bool stat[n][n];
        memset(stat, false, n*n);

        for( int i = 0; i < n; i++) {
            for( int j = 0; j <= i; j++) {
                if( s[i] == s[j] && (i-j<2 || stat[j+1][i-1])) {
                    stat[j][i] = true;
                }
            }
        }

    }

    //dfs
    vector<vector<string> > partition(string s) {

        vector<vector<string> > res;
        vector<string> one;

        if( s.empty() ) return res;
        part(s, 0, one, res);

        return res;

    }

    void part(string &s, int p, vector<string> &one, vector<vector<string> > &res) {

        if( p == s.size()) 
        {
            res.push_back(one);
            return;
        }

        for(int i = p; i < s.size(); i++) {

            string tmp = s.substr(p, i-p+1);
            if( palindrome(tmp))
            {
                one.push_back(tmp);
                part(s, i+1, one, res);
                one.pop_back();
            }
        }
    }

    bool palindrome(string s) {

        int i = 0; 
        int j = s.size()-1;
        // if size = 1, j =0, will return true;
        while( i < j) {
            if(s[i++] != s[j--]) return false;
        }

        return true;
    }

};


int main() {

    string myStr("aab");
    Solution mySol;

    vector<vector<string> > vvs = mySol.partition(myStr);
    vector<vector<string> >::iterator sit;
    vector<string>::iterator sis;
    for(sit = vvs.begin(); sit != vvs.end(); sit++) {
        for(sis = (*sit).begin(); sis != (*sit).end(); sis++) {
            cout << *sis << "  " ;
        }
        cout << endl;
    }

    return 0;
}
