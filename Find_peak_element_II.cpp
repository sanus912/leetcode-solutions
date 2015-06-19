#include <iostream>
#include <vector>
using namespace std;
/**
     * @param A: An integer matrix
     * @return: The index of the peak
     */

class Solution {
    public:
        //O(mlogn)
        vector<int> findPeakII(vector<vector<int> > A) {
            if(A.empty() || A[0].empty()) return vector<int>();

            int n = A.size();
            int m = A[0].size();
            int beg = 1;
            int end = n-2;
            while(beg<end)
            {
                int mid = beg + (end-beg)/2;
                int mc = gMax(A[mid]);
                if (A[mid][mc]> A[mid+1][mc] && A[mid][mc]> A[mid-1][mc])
                    return {mid,mc};
                else if(A[mid][mc]<A[mid+1][mc])
                    beg = mid+1;
                else if (A[mid][mc]<A[mid-1][mc])
                    end = mid;
            }
            return {beg,gMax(A[beg])};
        }

        int gMax(vector<int> &A)
        {
            int res = 1;
            int max = A[1];
            for (int i = 2;i<A.size()-1;i++)
                if(A[i] > max)
                {
                    max = A[i];
                    res = i;
                }
            return res;
        }
};


int main() {

    Solution mySol;
    vector<int> A = {0, 1, 2, 3, 5, 4, 5, 4, 6, 5, 11, 13, 12};

    cout << "peak "<< " is at " << mySol.findPeakElement(A) << endl;



    return 0;
}
