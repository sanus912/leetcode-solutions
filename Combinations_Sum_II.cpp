#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:

    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<vector<int> > result;
        vector<int> cur;
        if(num.empty()) 
            return result;
            
        sort(num.begin(),num.end());
        Helper(result,cur,0,0,num,target);
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
            if (i!=pos && S[i] == S[i-1])
                continue;
            cur.push_back(S[i]);
            Helper(result,cur,sum+S[i],i+1,S,target);
            cur.pop_back();
        }
    }   
};


int main() {

    const int s = 6;
    int myArr[s] = {1, 2, 2, 3, 4, 5};
    vector<int> myv;

    myv.assign(myArr, myArr+s);
    cout << "Size of myv: " << int (myv.size()) << endl;
    sort(myv.begin(), myv.end());

    Solution mySol;
    vector<vector<int> > ss = mySol.combinationSum2(myv, 7);

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
