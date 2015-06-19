#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    //additional place
    void reversewordsString_2(string &A)
    {
        int n = A.size();
        string res;
        int end = n;
        for (int i = n-1; i>=0;i--)
        {
            if (A[i]==' ')
                end = i;
            else if (i==0 || A[i-1]==' ')
            {
                if(!res.empty())
                    res.append(" ");
                res.append(A.substr(i,end-i));
            }
        }
        A = res;

    }

    //in place
    void reversewordsString(string &A) 
    {
        if (A.empty())
            return;

        while (A[0]==' ')
            A.erase(A.begin());

        if (A.empty())
            return;

        while (A[A.size()-1]==' ')
            A.erase(A.end()-1);

        int n = A.size();
        for (int i = n-1; i>=0;i--)
        {
            if (A[i]==' ' &&  A[i+1]==' '){
                A.erase(A.begin()+i);
                //cout << A << "!" << endl;
            }
        }
        
        n=A.size();
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
    string s = "  a  b  ";

    mySol.reversewordsString_2(s);
    cout << s << "!" <<  endl;


    return 0;
}
