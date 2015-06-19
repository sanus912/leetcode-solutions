#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = search_first(nums,target);
        int r = search_last(nums,target);
        return {l,r};
    }
    
    int search_first(vector<int> &A, int target) {
        int n = A.size();
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

    int search_last(vector<int> &A, int target) {
        int n = A.size();
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

    vector<int> searchRange_1(int A[], int n, int target) {

        int lo = distance(A, lower_bound(A, A+n, target));
        int up = distance(A, upper_bound(A, A+n, target));
        
        vector<int> res;
        if(A[lo] == target) {
            res.push_back(lo);
            res.push_back(up-1);
            return res;

        } 
        else {
            res.push_back(-1);
            res.push_back(-1);
            return res;
        }
        
    }

    //slow!
    vector<int> searchRange_2(int A[], int n, int target) {
        if (n==0)
            return {-1,-1};
        int start = 0;
        int end = n-1;
        while (start<end)
        {
            int mid = start+(end-start)/2;
            cout << mid << endl;
            if (target == A[mid]){
                vector<int> res1 = searchRange(A+start,mid-start,target);
                vector<int> res2 = searchRange(A+mid+1,end-mid,target);
                return {res1[0]>=0?res1[0]+start:mid, res2[1]>=0?res2[1]+mid+1:mid};
            }
            else if (target > A[mid])
                start = mid+1;
            else if (target < A[mid])
                end = mid-1;
        }
        if (A[start]==target)
        return {start,end};
        
        return {-1,-1};
    }
};

int main() {

    Solution mySol;
    const int s = 13;
    int A[s] = {0, 1, 2, 3, 4, 5, 7, 8, 8, 8, 8, 8, 8};
    int tar = 8;

    vector<int> ran = mySol.searchRange(A, s, tar);
    cout << "tar "<< " is at range (" <<  ran[0] << ", " << ran[1] << ")"<< endl;



    return 0;
}
