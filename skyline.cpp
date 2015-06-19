#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
using namespace std;

//同理， 一维可用counter = 0， begin:+1, end:-1
class Solution {
public:
    struct comp{
        bool operator ()(const int &a, const int &b){ return a > b;}
    };

    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int> > ret;
        multimap<int, int> mii;
        for (int i = 0; i < buildings.size(); ++i){
            vector<int> &vi = buildings[i];
            mii.insert(make_pair(vi[0], vi[2]));
            mii.insert(make_pair(vi[1], vi[2] * -1));
        }
        multiset<int, comp> msi;
        msi.insert(0);
        while (mii.size()){
            int last_height = *msi.begin();
            int cur = mii.begin()->first;
            while (mii.begin()->first == cur){
                int height = mii.begin()->second;
                if (height > 0){
                    msi.insert(height);
                }else{
                    msi.erase(height * -1);
                }
                mii.erase(mii.begin());
            }
            if (*msi.begin() != last_height){
                ret.push_back(make_pair(cur, *msi.begin()));
            }
        }
        return ret;
    }
};


int main() {

    vector<vector<int>> buildings = { {2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8} };

    Solution mySol;
    vector<pair<int, int>> res = mySol.getSkyline(buildings);

    for(auto p : res)
        cout << p.first << " " << p.second << endl;
    return 0;
}
