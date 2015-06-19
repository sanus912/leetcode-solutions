#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1.empty()||num2.empty()) return "";
        if(num1=="0"||num2=="0") return  "0";
        
        string res;
        int n1=num1.size();
        int n2=num2.size();
        int t = n1+n2;
        int carry = 0;
        for(int i=0;i<t;i++)
        {
            int sum = carry;
            for(int i1=0;i1<=i;i1++)
            {
                int i2 = i-i1;
                if(i1>=n1 || i2>=n2) continue;
                sum += int(num1[n1-1-i1]-'0') * int(num2[n2-1-i2]-'0');
            }
            res = char(sum%10+'0') + res;
            carry = sum/10;
        }
        while(res[0]=='0')
            res.erase(res.begin());
        return res;
    }
};



int main() {

    Solution mySol;
    string s1("1000");
    string s2("4563");


    string ans = mySol.multiply(s1, s2);

    cout << "Multiply Strings :  " << s1 << " * " << s2 << " = "<< ans << endl;


    return 0;
}
