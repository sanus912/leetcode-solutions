#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string convertToTitle(int n) {
    string res = "";

    while(n>0)
    {
        n--;
        res = char(n%26 + 'A')+res;
        n /= 26;
    }

    return res;
}
int main() {

    for (int i = 1;i<40;i++)
    cout << i << " -> " << convertToTitle(i) << endl;
    return 0;

}

