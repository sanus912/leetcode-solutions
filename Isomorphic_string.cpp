#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int m1[256] = {0}, m2[256] = {0}, n = s.size();
        for (int i = 0; i < n; ++i) {
            if (m1[(int)s[i]] != m2[(int)t[i]]) return false;
            m1[(int)s[i]] = i + 1;
            m2[(int)t[i]] = i + 1;
        }
        return true;
    }
};

int main() {

    Solution mySol;
    string s1 = "egg";
    string s2 = "cdd";

    cout << mySol.isIsomorphic(s1,s2) <<  endl;


    return 0;
}
