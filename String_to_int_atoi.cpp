#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int atoi(string str) //STL的atoi要代入c_str,e.g.(const char *)
    {

        if (str.empty())
            return 0;

        int n = str.size();
        int i = 0;
        while (i<n && str[i]==' ')
            i++;
        
        int sign = 1;
        if (i<n && str[i]=='+')
            i++;
        else if (i<n && str[i]=='-')
        {
            i++;
            sign = -1;
        }

        int res = 0;
        while(i<n && isdigit(str[i]))
        {
            if (res > INT_MAX/10 || (res == INT_MAX/10 && int(char(str[i])-'0') > INT_MAX%10) )
                return (sign>0? INT_MAX : INT_MIN);
            res = res*10 + int(char(str[i])-'0');
            i++;
        }
        return sign*res;
    }

};

int main() {

    Solution mySol;
    string s = "-2147483648";

    cout << mySol.atoi(s) <<  endl;

    cout << mySol.atoi("-2*") <<  endl;
    cout << mySol.atoi("  ") <<  endl;


    return 0;
}
