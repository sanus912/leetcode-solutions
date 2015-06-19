#include <iostream>
using namespace std;
 
class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        if( m == 0) 
            for(int it = 0; it < n; it++)
                A[it] = B[it];
        if(B == NULL || n == 0) return;  
        int l = m+n-1;  
        --m;  
        --n;  
        while(n >= 0 && m >= 0)  
        {  
            if(A[m] > B[n])A[l--] = A[m--];  
            else A[l--] = B[n--];  
        }  
        while(n>=0)  
            A[l--] = B[n--];  

    }
};


int main() {

    const int s1 = 6;
    const int s2 = 6;
    int arr1[s1+s2] = {1, 2, 5, 7, 9, 9};
    int arr2[s2] = {3, 4, 5, 6, 7, 8};

    Solution mySol;

    if(-1) cout << "everything excep 0 is true" << endl;

    for(int i = 0; i < s1; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;

    for(int i = 0; i < s2; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;


    mySol.merge(arr1, s1, arr2, s2);

    for(int i = 0; i < s1+s2; i++)
        cout << arr1[i] << " ";
    cout << endl;


    return 0;
}
