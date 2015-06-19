#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:

    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int> > result;
        vector<int> cur;
        if(candidates.empty()) 
            return result;
            
        sort(candidates.begin(),candidates.end());
        Helper(result,cur,0,0,candidates,target);
        return result;
    }
    
    void Helper(vector<vector<int> > &result, vector<int> &cur, int sum, int pos, vector<int> &S, int target)
    {
        if (sum == target)
        {
            result.push_back(cur);
            return;
        }
        else if (sum>target)
            return;
        for (int i = pos; i<S.size(); i++)
        {
            cur.push_back(S[i]);
            Helper(result,cur,sum+S[i],i,S,target);//区别在i不加1，unlimited times
            cur.pop_back();
        }
    }
};


int main() {

    const int s = 5;
    int myArr[s] = {1, 2, 3, 4, 5};
    vector<int> myv;

    myv.assign(myArr, myArr+s);
    cout << "Size of myv: " << int (myv.size()) << endl;
    sort(myv.begin(), myv.end());

    Solution mySol;
    vector<vector<int> > ss = mySol.combinationSum(myv, 7);

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
