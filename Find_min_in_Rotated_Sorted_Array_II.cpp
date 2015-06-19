#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int> &A) {
        if (A.size()==1)
        return A[0];
        
        int start = 0;
        int end = A.size()-1;

        while (start < end)
        {
            int mid = (start+end)/2;
            if (A[mid]>A[end])
            {
                start = mid+1;       
            }
            else if (A[mid]<A[end])
            {
                end = mid;
            }
            else
                end--;
        }
        return A[start];
    }
       
};



int main() {

    Solution mySol;
    vector<int> A = {2,3,4,5,6,7,8,1,2};

    for(int i = 0; i < A.size(); i++)
        cout  << A[i] << "  ";
    cout << endl;

    int a = mySol.findMin(A);
    cout << "min is " << a << endl;

    return 0;
}
