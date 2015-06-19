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

    int numOfRepN(int n, int coin) {
        int nextCoin = 0;
        switch (coin) {
            case 25:
                nextCoin = 10;
                break;
            case 10:
                nextCoin = 5;
                break;
            case 5:
                nextCoin = 1;
                break;
            case 1:
                return 1;
        }
        int num = 0;
        for (int i = 0; i * coin <= n; i++) {
            num += numOfRepN(n - i * coin, nextCoin);
        }
        return num;
    }

};


int main() {

    const int s = 4;
    int myArr[s] = {1, 5, 10, 25};
    vector<int> myv;

    myv.assign(myArr, myArr+s);
    cout << "Size of myv: " << int (myv.size()) << endl;
    sort(myv.begin(), myv.end());

    Solution mySol;

    cout << mySol.numOfRepN(100,25) << " ways." << endl;

    vector<vector<int> > ss = mySol.combinationSum(myv, 100);
    cout << ss.size() << " ways : " << endl;

    /*
    vector<vector<int> >::iterator it;
    vector<int>::iterator is;
    for(it = ss.begin(); it != ss.end(); it++) {
        for(is = (*it).begin(); is != (*it).end(); is++) {
            cout << *is << "  " ;
        }
        cout << endl;
    }
    */


    return 0;
}
