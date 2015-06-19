#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

class Solution {
public:
    int strStr(char *haystack, char *needle) {

        if (!haystack || !needle)
		return -1;

        int N = strlen(haystack);//return unsigned int!!!
        int n = strlen(needle);
        
        for (int i = 0; i< (N - n + 1) ;i++)
        {
            int j;
            for(j=0; j<n; j++)
                if (haystack[i+j] != needle[j])
                    break;
            if (j == n)
                return i;//if n=0,return 0!

        }
        return -1;

    }

    int strStr(string haystack, string needle) {
        int j;
        for (int i =0; i+needle.size()<=haystack.size();i++)
        {
            for (j =0;j<needle.size();j++)
            {
                if (haystack[i+j] != needle[j])
                    break;
            }
            if (j==needle.size())
                return i;
        }
        return -1;
    }

};

int main() {

    char haystack[] = "abbabaaa";
    char needle[] = "abaaa";

    Solution mySol;

    cout << mySol.strStr(haystack,needle) << endl;


    return 0;
}
