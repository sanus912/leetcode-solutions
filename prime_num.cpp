#include<iostream>
#include<math.h>
#include <vector>
using namespace std;

class Solution {
public:

    //The Sieve of Eratosthenes
    int countPrimes(int n) {
        if (n<=2) return 0;
        vector<bool> passed(n, false);
        int sum = 0;
        int upper = sqrt(n);
        for (int i=2; i<n; i+=1) {
            if (!passed[i]) {
                sum++;
                //avoid overflow
                if (i>upper) continue;//i*i may overflow
                for (int j=i*i; j<n; j+=i) {
                    passed[j] = true;
                }
            }
        }
        return sum;
    }

    //LTE
    int countPrimes_s(int n) {
        if (n<=2) return 0;
        int count = 0;
        for (int i = 2;i<n;i++)
        {
            if (isPrime(i))
                count++;
        }
        return count;
    }
    
    bool isPrime(int n)
    {
        if (n < 2) return false;
        for (int i = 2;i<=sqrt(n);i++)
            if(n%i==0)
                return false;
        
        return true;
    }
};

int main() {
    Solution mySol;
    cout << mySol.countPrimes(499979) << endl;
    for (int i = 1; i < 14; i++) {
        cout << i << " : " << mySol.countPrimes(i) << endl;
    }
}

