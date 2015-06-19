#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(int A[], int n, int target) {
        int start = 0;
        int end = n-1;

        while (start <= end)
        {
            int mid = (start+end)/2;
            if (A[mid] == target)
                return mid;
            else if (A[start]<A[mid])
            {
                if (target<A[mid] && target>=A[start])
                    end = mid-1;
                else
                    start = mid+1;
            }
            else if (A[start] > A[mid])
            {
                if (target<=A[end] && target>A[mid])
                    start = mid+1;
                else
                    end = mid-1;
            }
            else if (A[start]==A[mid])
            {
                start++; 
            }
        }
        return -1;
    }
       
};



int main() {

    Solution mySol;
    const int s = 9;
    int A[s] = {2,3,4,5,6,7,8,9,1};
    int tar = 9;

    for(int i = 0; i < s; i++)
        cout  << A[i] << "  ";
    cout << endl;

    int a = mySol.search(A, s, tar);
    cout << "tar "<< tar << " is at " << a << endl;

    return 0;
}
