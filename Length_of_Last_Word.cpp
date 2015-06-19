#include <iostream> 

using namespace std;

class Solution {
public:
    int lengthOfLastWord(const char *s) {

        int n = strlen(s);
        int i = n-1;
        while(s[i]==' ' && i>=0)
            i--;
        if (i==-1)
            return 0;
        int count = 0;
        while(s[i]!=' ' && i>=0)
        {
            i--;
            count++;
        }
        return count;
    }
};

int main(int argc, char ** argv) { 

    Solution mySol;

    char str[] = "Hello World";

    int len = mySol.lengthOfLastWord(str);

    cout << " Length of last world = " << len << endl;



    return 0; 
}
