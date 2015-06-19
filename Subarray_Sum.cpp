#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


class Solution {
public:
    //前缀和数组
    vector<int> subarraySum(vector<int> nums){
        unordered_map<int,int> hs;
        hs[0] = -1;
        int sum = 0;
        for (int i = 0;i<nums.size();i++)
        {
            sum += nums[i];
            if (hs.find(sum)!=hs.end())
            {
                return {hs[sum]+1,i};
            }
            hs[sum] = i;
        }
        return vector<int>();
    }
        
};


int main() {

    vector<int> v = {-1,1}; 

    Solution mySol;

    vector<int> res = mySol.subarraySum(v);
    for (auto i : res)
    cout << i << " ";
    cout << endl;

    return 0;
}
