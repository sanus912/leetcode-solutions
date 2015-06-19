#include <iostream> 
#include <map>
#include <string>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        const int values[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        const string symbols[] = {"M","CM","D","CD",
                            "C","XC","L","XL","X","IX","V","IV","I"};
        string res;
        int i = 0;
        while(num>0)
        {
            int k = num/values[i];
            for (int j=0;j<k;j++)
            {
                res += symbols[i];
                num -= values[i];
            }
            i++;
        }
        return res;  
    }

    int romanToInt(string s) {

        if(s.size() == 0) return 0;

        map<char, int> rtoi;
        int res = 0;

        rtoi['I'] = 1;
        rtoi['V'] = 5;
        rtoi['X'] = 10;
        rtoi['L'] = 50;
        rtoi['C'] = 100;
        rtoi['D'] = 500;
        rtoi['M'] = 1000;

        for(int i = 0; i < s.size(); i++) {
            if(i>0 && rtoi[s[i]] > rtoi[s[i-1]] ) 
                res += rtoi[s[i]] - 2* rtoi[s[i-1]];
            else 
                res += rtoi[s[i]];
        }

        return res;
        
    }
};

int main(int argc, char ** argv) { 

    Solution mySol;
    string s("MCMXLII");
    int i =1942;

    cout << "Romman to Integer "<< s << " is "<< mySol.romanToInt(s) << endl;
    cout << "Integer to Roman "<< i << " is "<< mySol.intToRoman(i) << endl;

    if( argc >1) cout << argv[0] << " " << argv[1] << " is "<< mySol.romanToInt(argv[1]) << endl;


    return 0; 
}
