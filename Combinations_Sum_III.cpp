#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        if (k==0) return res;
        vector<int> one;
        dfs(res,one,k,n,0,0,1);
        return res;
    }
    
    void dfs(vector<vector<int>> &res, vector<int> &one,int k, int target, int curk, int sum, int p)
    {
        if(curk == k && sum == target)
        {
            res.push_back(one);
            return;
        }
        else if (curk==k || sum >= target)
            return;
        
        for(int i = p; i<=9;i++)
        {
            one.push_back(i);
            dfs(res,one,k,target,curk+1,sum+i,i+1);
            one.pop_back();
        }
    }
};


int main() {

    Solution mySol;
    vector<vector<int> > ss = mySol.combinationSum3(2, 17);

    vector<vector<int> >::iterator it;
    vector<int>::iterator is;
    for(it = ss.begin(); it != ss.end(); it++) {
        for(is = (*it).begin(); is != (*it).end(); is++) {
            cout << *is << "  " ;
        }
        cout << endl;
    }


    return 0;
}
