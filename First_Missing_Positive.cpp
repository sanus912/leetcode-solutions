#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        bucketsort(nums);
        for(int i=0;i<nums.size();i++)
            if(nums[i] != i+1)
            return i+1;
        return nums.size()+1;
    }
    
    void bucketsort(vector<int>& A)
    {
        for(int i=0;i<A.size();i++)
        {
            while(A[i]!=i+1 && A[i]>0 && A[i]<=A.size())
            {
                if(A[A[i]-1] == A[i])
                    break;
                swap(A[A[i]-1],A[i]);
            }
        }
    }
};


int main() {

    const int s = 13;
    int myArr[s] = {1, 2, 3, 4, 5, -8, 7 ,8, 9, 2,  22, -4, 14 };
    Solution mySol;

    cout << mySol.firstMissingPositive(myArr, s) << endl;

    return 0;
}
