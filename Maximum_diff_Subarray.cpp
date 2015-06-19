#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:

    int maxDiffSubArrays(vector<int> nums) {
        int n = nums.size();
        if (n<2) return 0;

        vector<int> maxb(n+1,INT_MIN);
        vector<int> maxa(n+1,INT_MIN);
        vector<int> minb(n+1,INT_MAX);
        vector<int> mina(n+1,INT_MAX);
        
        int f = 0;
        int g = 0;
        for (int i = 1;i<=n;i++)
        {
            f = max(f,0) + nums[i-1];
            maxb[i] = max(maxb[i-1],f);
            g = min(g,0) + nums[i-1];
            minb[i] = min(minb[i-1],g);
        }

        f = 0;
        g = 0;
        for (int i = 1;i<=n;i++)
        {
            f = max(f,0) + nums[n-i];
            maxa[i] = max(maxa[i-1],f);
            g = min(g,0) + nums[n-i];
            mina[i] = min(mina[i-1],g);
        }
        
        int maxdiff = INT_MIN;
        for (int i = 1;i<n;i++)
        {
            int diff = max(abs(maxb[i]-mina[n-i]),abs(minb[i]-maxa[n-i]));
            maxdiff = max(maxdiff,diff);
        }
        return maxdiff;
    }
        
};


int main() {

    vector<int> v = {1,2,-3,1};

    Solution mySol;

    cout << mySol.maxDiffSubArrays(v) << endl;

    return 0;
}
