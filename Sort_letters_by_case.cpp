#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <string>

using namespace std;

class Solution {
public:
    void sortLetters(string &letters) {
        int p = 0;
        for (int i = 0;i<letters.size();i++)
        {
            if (letters[i]>'Z')
                swap(letters[p++],letters[i]);
        }
    }
};
        

int main() { 

    Solution mySol;
   
    string s = "aAcVD";
    mySol.sortLetters(s);
        cout << s << endl;

    return 0; 
}
