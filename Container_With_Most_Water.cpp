#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
        
        const int n = height.size();
        if(n == 0) return 0;
        
        int res = 0;
        int l = 0;
        int r = n-1;
        
        while(l < r) {
            int cur = (r-l) * min(height[l], height[r]);
            res = max(res, cur);
            if(height[l] < height[r]) 
                l++;
            else 
                r--;
        }
        
        return res;
    }

};



int main() {

    Solution mySol;
    const int s = 4;
    int A[s] = {2, 4, 1, 3};

    vector<int> myVec(A, A+s);

    int ans = mySol.maxArea(myVec);

    cout << "Container With Most Water : "<< ans << endl;



    return 0;
}
