#include<iostream>
#include<cmath>
#include<vector>
#include<string>
using namespace std;


class Solution {
public:
    //DP O(n^2)time and space
    string longestPalindrome_DP(string s) {

        int n = s.size();
        if (n<=1)
            return s;
        int maxbegin = 0;
        int maxlen = 1;
        bool f[n][n];
        memset(f, false, n*n);
        for(int i=0;i<n;i++)
        {
            f[i][i]=true;
            for (int j=0;j<i;j++)
            {
                if (s[i]==s[j] && (j+1==i || f[j+1][i-1])){
                    f[j][i] = true;
                    if (i-j+1 > maxlen)
                    {
                        maxlen = i-j+1;
                        maxbegin = j;
                    }
                }
            }
        }
        return s.substr(maxbegin,maxlen);
    }

    //O(n^2)time, constant space
    string longestPalindrome_ON2(string s) {

        int n = s.size();
        int maxbegin = 0;
        int maxlen = 1;

        for(int p = 0; p < n-1; p++) {

            int len1 = expand(s,p,p);
            int len2 = expand(s,p,p+1);
            int len = max(len1,len2);
            if (len > maxlen)
            {
                maxlen = len;
                maxbegin = p-(len-1)/2;
            }
        }


        return s.substr(maxbegin, maxlen);
    }
    
    int expand(string s, int l, int r)
    {
        while(l>=0 && r<s.size() && s[l] == s[r]) {

                l--;
                r++;
        }
        return r-l-1;//!
    }


};


int main(int argc, char ** argv) {

    string now("this is an apple cabbacggs");
    string tst("a");
    Solution ss;

    cout << string(now.begin(), now.end() ) << endl;
    cout << string(now.rbegin(), now.rend() ) << endl;

    cout << "The longest Palindromic sub-string is '"<< ss.longestPalindrome_ON2(now);
    cout << "'" << endl;

    cout << "The longest Palindromic sub-string is '"<< ss.longestPalindrome_ON2(tst);
    cout << "'" << endl;

    return 0;
}
