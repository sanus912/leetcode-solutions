#include<iostream>
#include<cmath>
#include<vector>
#include<cassert>
using namespace std;


class Solution {
public:
       
    bool isPalindrome(int x) {
        
        if (x<0)
            return false;
        
        int base = pow(10,int(log10(x)));

        /* OR
        int base = 1;
        while(x/base>=10)
        { base *= 10;}
        */
        
        while (x>0)
        {
            int b = x/base;
            int e = x%10;
            if (b!=e) 
                return false;

            x = (x % base) / 10;
            base /= 100;
        }

        return true;

    }

};


int main(int argc, char ** argv) {

    Solution rrr;

    for( int i = -2; i < 13; i++ )
        cout  << i << "  -->  " << rrr.isPalindrome(i) << endl;

    int i = 313;
    cout  << i << "  -->  " << rrr.isPalindrome(i) << endl;

    i = INT_MAX;
    cout  << i << "  -->  "  << rrr.isPalindrome(i) << endl;

    i = INT_MIN;
    cout  << i << "  -->  " << rrr.isPalindrome(i) << endl;

    return 0;
}
