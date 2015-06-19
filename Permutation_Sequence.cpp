#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    string getPermutation(int n, int k) {

        string res;
        if( k <= 0 || n<= 0) return res;
        string s(n,'0');

        for (int i = 0; i < n; i++) {
            s[i] += i + 1;              // build up the original sequence
        }

        int base = factorial(n-1);
        k--;

        int a;
        for(int i = n-1; i>0; i--) {
            a = k/base;
            res.push_back(s[a]);
            s.erase(s.begin() + a);

            k %= base;
            base /= i;
        }

        res.push_back(s[0]);
        return res;
    }

    int factorial(int n)
    {
        int res = 1;
        for (int i=1; i<=n; i++)
            res *= i;
        return res;
    }
};


int main() {

    Solution mySol;
    cout << mySol.getPermutation(5, 71) << endl;

    return 0;
}
