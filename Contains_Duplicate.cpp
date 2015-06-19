#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    //if exist dup
    bool containsDuplicate1(vector<int>& nums) {
        int n = nums.size();
        if(n<=1) return false;
        unordered_set<int> hs;
        for(int i=0;i<n;i++)
        {
            if(hs.find(nums[i])!=hs.end())
                return true;
            hs.insert(nums[i]);
        }
        return false;
    }

    //if exist dup and diff(i,j)<=k
    bool containsNearbyDuplicate2(vector<int>& nums, int k) {
        if(k<=0) return false;
        int n = nums.size();
        if(n<=1) return false;
        
        unordered_map<int,int> hs;
        for(int i=0;i<n;i++)
        {
            if(hs.find(nums[i])!=hs.end() && hs[nums[i]]>=i-k)
                return true;
            hs[nums[i]] = i;
        }
        return false;
    }

    //if abs(nums[i]-nums[j])<=t and diff(i,j)<=k
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        map<long long,int> M;
        int l=0;
        for (int r=0;r<nums.size();r++) {
            if (r-l>k && M[nums[l]]==l)
                M.erase(nums[l++]);
            auto it=M.lower_bound(nums[r]-t);
            if (it!=M.end() && abs(it->first-nums[r])<=t)
                return true;
            M[nums[r]]=r;
        }
        return false;
    }

};

int main() {

    const int s = 6;
    int myArr[s] = {2, 1, 4, 5, 7, 15};
    int target = 6;
    vector<int> myv;

    myv.assign(myArr, myArr+s);
    cout << "Size of myv: " << int (myv.size()) << endl;

    Solution mySol;
    vector<int> ss = mySol.twoSum(myv, target);

    for(auto is = myv.begin(); is != myv.end(); is++) {
        cout << *is << "  ";
    }
    cout << endl;
    for(auto is = ss.begin(); is != ss.end(); is++) {
        cout << *is << "  ";
    }
    cout << endl;


    int i = 1;
    if(i)
        cout << i << endl;
    i = 0;
    if(i)
        cout << i << endl;
    i = -1;
    if(i)
        cout << i << endl;
    return 0;
}
