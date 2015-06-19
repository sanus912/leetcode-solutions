#include<iostream>
using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int c=0;
        while(m!=n){
            m>>=1;
            n>>=1;
            ++c;
        }
        return n<<c;
    }
};

int main() {

    Solution mySol;
    int a = 5, b = 7;
    
    cout<<"Output:"<<mySol.rangeBitwiseAnd(a,b);

    return 0;
}


