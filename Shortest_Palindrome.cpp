#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    string shortestPalindrome(string s) {
        if(s.empty()) return s;
        string s2=s;
        reverse(s2.begin(),s2.end());
        int n=s.size(),l;
        for(l=n;l>0;l--)
        {
            if(s.substr(0,l)==s2.substr(n-l))
                break;
        }
        return s2.substr(0,n-l)+s;
    }
};


int main() {

    string myStr("aaacaa");
    Solution mySol;

    cout << mySol.shortestPalindrome(myStr) << endl;

    return 0;
}
