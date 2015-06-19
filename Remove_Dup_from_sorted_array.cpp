#include <iostream>
using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(!A || n<2) return n;
        
        int j =1;
        for(int i =1;i<n;i++)
        {
            if(A[i]!=A[j-1])
                A[j++] = A[i];
        }
        return j;
    }

    int removeDuplicates_2(int A[], int n) {
          return distance(A, unique(A, A + n));
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

    int r = mySol.removeDuplicates_2(myArr, s);

    for(int i = 0; i < r; i++) {
        cout  << myArr[i] << "  ";
    }
    cout << endl;



    return 0;
}
