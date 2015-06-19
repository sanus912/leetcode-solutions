#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
using namespace std;

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int n = s.size();
        int m = t.size();
        if (n>m) return isOneEditDistance(t,s);
        if (m-n>1) return false;
        int p1 = 0;
        int p2 = 0;
        while(p1<n && p2<m && s[p1]==t[p2])
        {
            p1++;p2++;
        }
        if (p1==n)
            return m - n == 1;
        
        p2++;
        if (n==m)
            p1++;
        while(p1<n && p2<m && s[p1]==t[p2])
        {
            p1++;p2++;
        }
        return p2==m;
    }
};

int main() {

    Solution mySol;
    string s1("tea");
    string s2("atea");


    cout << mySol.isOneEditDistance(s1, s2) << endl;

    return 0;
}
