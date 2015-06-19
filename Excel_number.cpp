#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int titleToNumber(string s) {
    int res = 0;
    int i = 0;
    while (i<s.size() && s[i] >= 'A' && s[i] <= 'Z') 
    { 

        res = 26 * res + static_cast<int>(s[i] - 'A'+1);
        i++;

    }
    return res;
}

int main() {

    cout << titleToNumber("AA") << endl;
    return 0;

}

