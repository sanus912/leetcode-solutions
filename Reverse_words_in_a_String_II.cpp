#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    //STL reverse
    void reverseWords(string &s) {
        reverse(s.begin(),s.end());
        int start = 0;
        for (int i =0;i<s.size();i++)
        {
            if (s[i]==' ')
            {
                reverse(s.begin()+start,s.begin()+i);
                start = i+1;
            }
        }
        reverse(s.begin()+start,s.end());
    }

    //homemade reverse
    void reverseWords(string &A) {
        if (A.empty())
            return;

        int n = A.size();
        reverse(A,0,n-1);
       
        int start = 0;
        for (int i = 0;i<n;i++)
        {
            if (A[i]==' ')
            {
                reverse(A,start,i-1);
                start = i+1;
            }
        }
        reverse(A,start,n-1);
    }
    void reverse(string &A,int start, int end)
    {
        while(start<end)
        {
            char temp = A[start];
            A[start] = A[end];
            A[end] = temp;
            start++;
            end--;
        }
    }
};

int main() {

    Solution mySol;
    string s = "the sky is blue";

    mySol.reverseWords(s);
    cout << s << "!" <<  endl;


    return 0;
}
