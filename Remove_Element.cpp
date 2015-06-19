#include <iostream>
using namespace std;

class Solution {
public:

    int removeElement(int A[], int n, int elem) {
        
        if( !A || n==0) return 0;
        int p1, p2;
        
        p1 = 0;
        for(p2 = 0; p2 < n; p2++) {
            if(A[p2] != elem) 
                A[p1++] = A[p2];
        }
        
        return p1;
    }

    int removeElement_2(int A[], int n, int elem) {
        
        return distance(A, remove(A, A+n, elem));
        
    }
};


int main() {

    Solution mySol;
    const int s = 8;
    int myArr[s] = {1, 2, 2, 2, 4, 5, 6, 6};


    for(int i = 0; i < s; i++) {
        cout  << myArr[i] << "  ";
    }
    cout << endl;

    int r = mySol.removeElement_2(myArr, s, 2);

    cout << "rest = " << r << endl ;
    for(int i = 0; i < r; i++) {
        cout  << myArr[i] << "  ";
    }
    cout << endl;



    return 0;
}
