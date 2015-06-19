#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int compareVersion(string version1, string version2) {
        int p1,p2;
        for (p1=0;p1<version1.size();p1++)
            if (version1[p1]=='.')
                break;
        int num1 = atoi(version1.substr(0,p1));
        
        for (p2=0;p2<version2.size();p2++)
            if (version2[p2]=='.')
                break;
        int num2 = atoi(version2.substr(0,p2));
        
        if (num1>num2)
            return 1;
        else if (num1<num2)
            return -1;
        else
        {
            string s1;
            string s2;
            if (p1 < version1.size()-1)
                s1 = version1.substr(p1+1,version1.size()-p1-1);
            else
                s1 = "0";

            if (p2 < version2.size()-1)
                s2 = version2.substr(p2+1,version2.size()-p2-1);
            else
                s2 = "0";

            if (s1=="0" && s2 == "0")
                return 0;
            else
                return compareVersion(s1,s2);
        }
    }
    
    int atoi(string str) 
    {
        if (str.empty())
            return 0;

        int res = 0;
        int i =0;
        while(i<str.size() && str[i]>='0' && str[i]<='9')
        {
            if (res > INT_MAX/10 || (res == INT_MAX/10 
                    && int(str[i]-'0') > INT_MAX%10))
                return INT_MAX;
            res = res*10 + int(str[i]-'0');
            i++;
        }
        return res ;
    }

};

int main() {

    Solution mySol;
    string s1 = "01";
    string s2 = "1";

    cout << mySol.compareVersion(s1,s2) <<  endl;


    return 0;
}
