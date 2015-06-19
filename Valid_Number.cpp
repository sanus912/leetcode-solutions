#include <iostream> 

using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        int n = s.size();
        int i = 0;
        while(i<n && s[i] == ' ')
            i++;
        if (i<n && (s[i]=='+' || s[i] == '-'))
            i++;
        bool isnum = false;
        while(i<n && isdigit(s[i]))
        {
            i++;
            isnum = true;
        }
        if (i<n && s[i]=='.')
        {
            i++;
            while(i<n && isdigit(s[i]))
            {
                i++;
                isnum = true;
            }
        }
        if (i<n && isnum && s[i]=='e')
        {
            i++;
            if (i<n && (s[i]=='+' || s[i] == '-'))
                i++;
            isnum = false;
            while(i<n && isdigit(s[i]))
            {
                i++;
                isnum = true;
            }
        }
        while(i<n && s[i] == ' ')
            i++;
        
        return isnum && i==n;
        
    }

};

int main(int argc, char ** argv) { 

    Solution mySol;

    string s = "18.2"; 

    if( mySol.isNumber(s.c_str()) )
        cout << s << " is a number?  Yes! "<< endl;
    else
        cout << s << " is a number?  No! "<< endl;


    return 0; 
}
