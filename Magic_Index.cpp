#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int f(int * A, int s, int e)
    {
        while (s<=e)
        {
            int mid = s+(e-s)/2;
            if (A[mid] < mid)
            {
                s = mid+1;
            }
            else if (A[mid] > mid)
            {
                e = mid-1;
            }
            else
                return mid;
        }
        return -1;
    }

    int f_dup(int * A, int s, int e, int n)
    {
        if (e < s || s<0 || e>=n)
            return -1;
        int mid = s+(e-s)/2;
        //cout << "mid = " << mid << endl;
        //getchar();
        if (A[mid] == mid)
            return mid;

        int l = f_dup(A, s, min(mid-1,A[mid]), n);
        //cout << "l = " << l << endl;
        if  (l>=0)
            return l;


        int r = f_dup(A, max(mid+1,A[mid]), e, n);
        //cout << "r = " << r << endl;
        if  (r>=0)
            return r;
            
        return -1;
    }
    
};


int main() {

    Solution mySol;
    const int s = 8;
    int myArr[s] = {-10, -2,1, 2, 3, 5, 7, 8};
    int myArrdup[s] = {2, 2, 2, 2, 3, 6, 7, 8};


    for(int i = 0; i < s; i++) {
        cout  << myArr[i] << "  ";
    }
    cout << endl;

    cout << mySol.f(myArr,0,s-1) << endl;

    cout << mySol.f_dup(myArrdup,0,s-1, s) << endl;





    return 0;
}
