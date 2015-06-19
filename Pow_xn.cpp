#include <iostream>
#include <cstdlib>

using namespace std;

class Solution {
public:

    double pow(double x, int n) {
        if (n<0) return 1.0/power(x,-n);
        else return power(x,n);
    }
    
    double power(double x, int n)
    {
        if (n==0) return 1.0;
        double v = power(x,n/2);
        if (n%2==0)
         return v*v;
        else
         return v*v*x;
    } 

};

int main() { 

    Solution mySol;

    double x = 2;
    int n ;
   
    for(n=1;n<10;n++)
    printf("pow(%f, %d) = %f\n", x, n, mySol.pow(x,n));

    return 0; 
}
