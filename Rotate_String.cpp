#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string rotateString(string A, int k) 
    {
        if (A.size()<2)
            return A;
        int n = A.length();
        k = k%n;
        reverse(A,0,n-1);
        reverse(A,0,k-1);
        reverse(A,k,n-1);
        return A;
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
    string s = "abcde";

    cout << mySol.rotateString(s,2) << endl;


    return 0;
}
