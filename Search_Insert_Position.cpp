#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    //search any position
    int searchInsert(int A[], int n, int target) {
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
                
        return start;//!
    }

};



int main() {

    Solution mySol;
    const int s = 13;
    //int A[s] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 11, 12};
    int A[s] = {0, 1, 2, 3, 5, 5, 5, 5, 5, 5, 11, 11, 12};
    int tar = 4;

    cout << "tar "<< " is at " << mySol.searchInsert(A, s, tar) << endl;
    cout << "tar "<< " is at " << mySol.searchInsert_2(A, s, tar) << endl;
    cout << "tar "<< " is at " << mySol.searchInsert_3(A, s, tar) << endl;



    return 0;
}
