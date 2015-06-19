#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search_first(int A[], int n, int target) {
        if (n<=0)
            return -1;
        int start = 0;
        int end = n-1;
        while (start<end)
        {
            int mid = start+(end-start)/2;
            if (target > A[mid])//!
                start = mid+1;
            else 
                end = mid;
        }
        if(A[start]==target)
            return start;
        return -1;
    }

    int search_last(int A[], int n, int target) {
        if (n<=0)
            return -1;
        int start = 0;
        int end = n;
        while (start<end)
        {
            int mid = start+(end-start)/2;
            if (target >= A[mid])//!
                start = mid+1;
            else 
                end = mid;
        }
        if(A[start-1]==target)
            return start-1;
        return -1;
    }

    int search(int A[], int n, int target) {
        int start = 0;
        int end = n-1;
        while (start<=end)
        {
            int mid = start+(end-start)/2;
            if (target == A[mid])
                return mid;
            else if (target > A[mid])
                start = mid+1;
            else if (target < A[mid])
                end = mid-1;
        }
                
        return -1;
    }
       
};



int main() {

    Solution mySol;
    const int s = 2;
    int A[s] = {2,2};
    int tar = 1;

    for(int i = 0; i < s; i++)
        cout  << A[i] << "  ";
    cout << endl;

    int a = mySol.search_first(A, s, tar);
    cout << "first tar "<< tar << " is at " << a << endl;

    a = mySol.search_last(A, s, tar);
    cout << "last tar "<< tar << " is at " << a << endl;

    a = mySol.search(A, s, tar);
    cout << "any tar "<< tar << " is at " << a << endl;

    return 0;
}
