#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    //O(log(m+n))
    double findMedianSortedArrays(int A[], int m, int B[], int n) {

        if( (m+n) & 1) 
            return double(Kth(A, m, B, n, (m+n)/2+1));
        else
            return (Kth(A, m, B, n, (m+n)/2) + Kth(A, m, B, n, (m+n)/2+1)) / 2.0;
    }
    
    int Kth(int *A, int m, int *B, int n, int k) {

        if(k > m + n) return -1;
        if ( m > n )
            return Kth_2(B,n,A,m,k);
        if(m == 0) return B[k-1];
        if(k == 1) return min(A[0], B[0]); 
        
        int ia = min(k/2,m), ib = k-ia;
        if (A[ia-1]<B[ib-1])
            return Kth_2(A+ia,m-ia,B,n,k-ia);
        else if (A[ia-1]>B[ib-1])
            return Kth_2(A,m,B+ib,n-ib,k-ib);
        else
            return A[ia-1];
        
    }



    //O((m+n)log(m+n))
    double findMedianSortedArrays_2(int A[], int m, int B[], int n) {

        int s = (m + n) /2;
        double res = 0.;

        vector<int> C(A, A+m);
        C.insert(C.begin(), B, B+n);
        sort(C.begin(), C.end());

        if ( (m+n) & 1) 
            res = C[s];
        else 
            res = (C[s] + C[s-1])/2.0;

        return res;
    }
};



int main() {

    const int s1 = 5;
    const int s2 = 5;
    int arr1[s1] = {0, 2, 4, 6, 9};
    int arr2[s2] = {1, 3, 5, 7, 8};


    Solution mySol;
    double med = mySol.findMedianSortedArrays(arr1, s1, arr2, s2);

    for(int i = 0; i < s1; i++) {
        cout << (arr1[i] ) << "  ";
    }
    cout << endl;

    for(int i = 0; i < s2; i++) {
        cout << (arr2[i] ) << "  ";
    }
    cout << endl;

    cout << "Median of A and B is : " << med  << endl; 

    return 0;
}
