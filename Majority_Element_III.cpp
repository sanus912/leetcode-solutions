#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:

    int majorityNumber(vector<int> nums, int k) {
        
        unordered_map<int,int> hs;
        for (int i : nums)
        {
            if (hs.find(i)!=hs.end())
            {
                hs[i]++;
            }
            else if (hs.size()<k-1)
            {
                hs.insert({i,1});    
            }
            else
            {
                unordered_set<int> todelete;
                for (auto &p : hs)
                {
                    p.second--;
                    if (p.second == 0)
                        todelete.insert(p.first);
                }

                for (auto key : todelete)
                    hs.erase(key);
            }
        }
        

        for (auto &p : hs)
            p.second = 0;
        int res = -1;
        int maxcount = 0;
        for (int i : nums)
        {
            if (hs.find(i)!=hs.end())
            {
                hs[i]++;
                if (hs[i] > maxcount)
                {
                    maxcount = hs[i];
                    res = i;
                }
            }
            
        }
        return res;
        
    }
};


int main() {

    Solution mySol;
    vector<int> v = {1, 6, 7, 8, 3, 5, 6, 6, 9, 20, 31, 6};


    for(int i = 0; i < v.size(); i++) {
        cout  << v[i] << "  ";
    }
    cout << endl;

    cout << mySol.majorityNumber(v,4) << endl;





    return 0;
}
