#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if (n <= 1) return n;
        unordered_map<char, int> hs;
        int res = 1;
        int start = 0;
        for (int i = 0;i<n;i++)
        {
            if (hs.find(s[i])!=hs.end())
            {
                res = max(res,i-start);
                start = max(hs[s[i]] + 1,start);
            }
            hs[s[i]] = i;
        }
        res = max(res,n-start);
        return res;
    }
    
};


int main() {

    string myStr("abba");
    Solution mySol;

    cout << mySol.lengthOfLongestSubstring(myStr) << endl;
    return 0;
}
