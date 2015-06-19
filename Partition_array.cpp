#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:

    int partitionArray(vector<int> &nums, int k) {
        nums.push_back(k);
        int p = 0;
        for (int i = 0;i<nums.size();i++)
        {
            if (nums[i]<k)
                swap(nums[p++],nums[i]);
        }
        return p;
    }
        
};


int main() {

    vector<int> v = {-1,2,4,-3,7};

    Solution mySol;

    cout << mySol.partitionArray(v,0) << endl;

    return 0;
}
