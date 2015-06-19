#include <cmath>
#include <vector>
#include <string>
#include <iostream>

using namespace std;
 
class Solution {
public:

    int numDecodings(string s) {

        if(s.empty()||s[0]==0) return 0;
        const int n = s.size();
        
        vector<int> ways(n+1, 0);
        ways[0] = 1;
        ways[1] = 1;
        
        for(int i = 2; i <= n; i++){
            if(s[i-1] != '0') ways[i] += ways[i-1];
            if(s[i-2] == '1' || (s[i-2] == '2' && s[i-1] - '0' < 7)) ways[i] += ways[i-2];
        }
        
        return ways[n];
    }


};

int main() {
    Solution mySol;
    string s1("1000");
    string s2("12");

    int ways = mySol.numDecodings(s1);
    cout << "We have " << ways <<  " ways to Decode " << s1 << endl;
    return 0;
}
