#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> old;
        old.insert(n);
        do 
        {
            n = getDigitsSum(n);
            if (old.find(n)!=old.end())
            {
                break;
            }
            old.insert(n);
        } while (n>1);                

        return n==1;
    }

    int getDigitsSum(int n)
    {
        int v = 0;
        int sum = 0;
        while (n)
        {
            v = n % 10;
            sum += v*v;
            n /= 10;
        }
        return sum;
    }

};



int main() {

    Solution mySol;

    cout << mySol.isHappy(19) << endl;
   


    return 0;
}
