#include <iostream>
using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if( !A || n<=2) return n;
        
        int index=2;
        for(int i = 2; i < n; i++) {
            if (A[i]!=A[index-2])
                A[index++] = A[i]; 
        }
        return index;
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

    int r = mySol.removeDuplicates(myArr, s);

    for(int i = 0; i < r; i++) {
        cout  << myArr[i] << "  ";
    }
    cout << endl;



    return 0;
}
