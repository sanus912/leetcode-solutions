#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    string countAndSay(int n) // == string compression
    {

        if(n<=0) return "";
        string s = "1";
        n--;
        
        while(n--)
        {
            string p;
            int j = 0, i;
            char c = s[0]; 
            for(i = 1;i<s.size();i++)
            {
                if(s[i]!=c)
                {
                    p += to_string(i-j) + c;
                    j = i;
                    c = s[i];
                }
            }
            p += to_string(i-j) + c;
            s = p;
        }
        return s;
    }

};


int main() {

    Solution mySol;
    const int s = 6;

    cout << mySol.countAndSay(s) << endl;

    return 0;
}
