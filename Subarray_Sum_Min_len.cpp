#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


class Solution {
public:
    //前缀和数组
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        vector<int> psum(n+1,0);
        psum[0]=0;
        int minlen = INT_MAX;
        
        int sum=0;
        for(int i =0;i<n;i++)
        {
            sum += nums[i];
            psum[i+1] = sum;
            for(int j =i-1;j>=-1;j--)
            {
                if(psum[i+1]-psum[j+1]>=s)
                {
                    if(i-j<minlen)
                        minlen = i-j;
                    break;
                }
            }
        }
        if (minlen==INT_MAX) 
            return 0;
        else
            return minlen;
    }
        
};


int main() {

    vector<int> v = {1,1}; 

    Solution mySol;

    cout << mySol.minSubArrayLen(3,v);
    
    return 0;
}
