#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n==0) return 0;
        if (n==1) return nums[0];
        vector<int> a = nums;
        a.erase(a.begin());
        vector<int> b = nums;
        b.erase(b.end()-1);
        
        return max(robber(a),robber(b));
        
    }
    
    int robber(vector<int>& nums) {
        int n = nums.size();
        if (n==0) return 0;
        vector<int> f(n+1,0);
        f[1] = nums[0];
        for(int i =2;i<=n;i++)
        {
            f[i] = max(f[i-1],f[i-2]+nums[i-1]);   
        }
        return f[n];
    }
};

int main() {

    vector<int> v = {2,1,1,2};
    Solution mySol;
    cout << mySol.rob(v) << endl;
    return 0;

}

