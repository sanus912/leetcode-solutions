#include <iostream> 
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    //也可用two pointer, sliding window, 
    //如minimum_window_substring.cpp, 
    //substring with concatenation of all words
    
    //presum array
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

int main(int argc, char ** argv) { 

    Solution mySol;

    vector<int> myvec = {2,3,1,2,4,3};

    cout << mySol.minSubArrayLen(7,myvec) << endl;

    return 0; 
}
