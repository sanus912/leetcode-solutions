#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    //O(logn)
    int findPeakElement(const vector<int> &num) {
        int n = nums.size();
        if(n==1) return 0;
        int b = 1;
        int e= n-2;
        while(b<=e)
        {
            int m = b+(e-b)/2;
            if(nums[m]>nums[m-1] && nums[m]>nums[m+1])
                return m;
            else if (nums[m]<nums[m-1])
                e = m-1;
            else if (nums[m]<nums[m+1])
                b = m+1;
        }
        if(nums[0]>nums[1])
            return 0;
        if(nums[n-1]>nums[n-2])
            return n-1;
        return -1;
    }

    //O(logn) lintcode
    int findPeakElement(const vector<int> &num) {
        int n = nums.size();
        if(n==1) return 0;
        int b = 1;
        int e= n-2;
        while(b<=e)
        {
            int m = b+(e-b)/2;
            if(nums[m]>nums[m-1] && nums[m]>nums[m+1])
                return m;
            else if (nums[m]<nums[m-1])
                e = m-1;
            else if (nums[m]<nums[m+1])
                b = m+1;
        }
        return -1;
    }

    //O(n) lintcode
    int findPeak(vector<int> A) {
        for(int i =1;i<A.size()-2;i++)
        {
            if(A[i]>A[i+1])
                return i;
        }
        return A.size()-2;
    }

};



int main() {

    Solution mySol;
    vector<int> A = {0, 1, 2, 3, 5, 4, 5, 4, 6, 5, 11, 13, 12};

    cout << "peak "<< " is at " << mySol.findPeakElement(A) << endl;



    return 0;
}
