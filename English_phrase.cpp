#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<string> digits = {"One","Two","Three","Four","Five","Six","Seven",
        "Eight","Nine"};
    vector<string> tens = {"Ten","Twenty","Thirty","Fourty","Fifty","Sixty",
        "Seventy","Eighty","Ninety"};
    vector<string> teens = {"Eleven","Twelve","Thirteen","Fourteen","Fifteen",
        "Sixteen","Seventeen","Eighteen","Nineteen"};
    vector<string> bigs = {"","Thousand","Million"};

    string engrep(int num)
    {
        if (num==0)
            return "Zero";
        if (num<0)
            return "Negative " + engrep(-1*num);

        int count = 0;
        string res="";
        while(num>0)
        {
            res = f(num%1000) + bigs[count] + (count>0?", ":"") + res;
            num /= 1000;
            count++;
        }
        return res;
    }

    string f(int num)
    {
        string res = "";
        if (num>100)
        {
            res += digits[num/100-1] + " Hundred "; 
            num %= 100;
        }

        if (num==10 || num>=20)
        {
            res += tens[num/10-1]+" ";
            num %= 10;
        }
        else if (num>=11 && num<=19)
        {
            res += teens[num-11] + " ";
            return res;
        }

        if (num>=1 && num<=9)
        {
            res += digits[num-1] + " ";
        }
        return res;
    }
};


int main() {

    Solution mySol;
    int i = 1143;
    string res = mySol.engrep(i);
    cout << i << "\t" << res << endl;

    return 0;
}
