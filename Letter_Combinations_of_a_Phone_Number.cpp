#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        
        if (digits.empty())
        return vector<string>();
        
        vector<string> ss = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res;
        string one;

        combine(digits, 0, ss, res, one );

        return res;
       
    }

    void combine(string digits, int p, vector<string> ss, vector<string> &res, string one) {

        if( p == digits.size() ) {
            res.push_back(one);
            return;
        }

        int d = digits[p]-'0';
        for(auto c : ss[d]) {
            combine(digits, p+1, ss, res, one+c);
        }


    }
};


int main() {

    Solution mySol;

    vector<string> res = mySol.letterCombinations("23");

    for(auto& a: res)
        cout << a << endl;



    return 0;
}
