#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        //transform(s.begin(),s.end(),s.begin(),::toupper);
        for (char &c : s)
        {
            if (isalnum(c))
                c = tolower(c);
        }
        auto left = s.begin();
        auto right = s.end()-1;
        while(left<right)//comparison of iterator only good for vector and string
        {
            if (!isalnum(*left)) //do not use while loop! in case no alnum in string
                left++;
            else if (!isalnum(*right)) 
                right--;
            else if (*left != *right) 
                return false;
            else {left++;right--;}
        }
        return true;//empty string return true!
    }

    //while loop也可
    bool isPalindrome(string s) {
        int n = s.size();
        if (n==0) return true;
        int b = 0;
        int e = n-1;
        while(b<e)
        {
            while(!isalnum(s[b]))
            {b++;}
            while(!isalnum(s[e]))
            {e--;}
            if (b>=e) 
                return true;
            else if(tolower(s[b]) == tolower(s[e]))
            {
                b++;e--;
            }
            else
                return false;
        }
        return true;
    }
};

int main() {

    char a = 'A';
    cout << (char)tolower(a) << endl;

    Solution mySol;
    string s = "Nella's simple hymn: \"I attain my help, Miss Allen.\"";

    cout << mySol.isPalindrome(s) << endl;


    return 0;
}
