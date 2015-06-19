#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


class Solution {
public:
    //前缀和数组
    vector<int> subarraySumClosest(vector<int> nums){
        if (nums.empty()) return vector<int>();
        if (nums.size()==1) return {0,0};
        vector<int> psum;
        unordered_map<int,int> hs;
        hs[0] = -1;
        int sum = 0;
        for (int i = 0;i<nums.size();i++)
        {
            sum += nums[i];
            if (hs.find(sum)!=hs.end())
            {
                return {hs[sum]+1,i};//diff = 0;
            }
            hs[sum] = i;
            psum.push_back(sum);
        }
        sort(psum.begin(),psum.end());
        int mindiff=INT_MAX;
        int d;
        for (int i=1;i<psum.size();i++){
            int diff = psum[i] - psum[i-1]; 
            if (diff < mindiff){
                mindiff = diff;
                d = i;
            }
        }
        
        int index1 = hs[psum[d]];
        int index2 = hs[psum[d-1]];
        if (index2>index1)
            return {index1+1,index2};
        else
            return {index2+1,index1};
    }
        
};


int main() {

    vector<int> v = {-3, 1, 1, -3, 5}; 

    Solution mySol;

    vector<int> res = mySol.subarraySumClosest(v);
    for (auto i : res)
    cout << i << " ";
    cout << endl;

    return 0;
}
