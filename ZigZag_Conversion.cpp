#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    string convert(string s, int nRows) {

        string res;
        int zig = 2*nRows - 2;

        if( s.size()==0 || nRows <= 1) return s;

        for( int i = 0; i < nRows; i++) {
            int pos = i;
            while(1) {
                if( pos >= s.size()) break;
                res.push_back(s[pos]);
                pos += zig;

                if( i > 0 && i < nRows-1) {
                    int one = pos - 2*i;
                    if(one >= s.size()) break;
                    res.push_back(s[one]);
                }
            }
            
        }

        return res;
    }
};

int main() {


    string s("PAYPALISHIRING");
    Solution mySol;

    string r = mySol.convert(s, 3);

    cout << s << endl;
    cout << r << endl;



    return 0;
}
