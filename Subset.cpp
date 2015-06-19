#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


class Solution {
public:

    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int> > result;
        vector<int> cur;
        if(S.empty()) 
            return result;
            
        sort(S.begin(),S.end());
        subsetsHelper(result,cur,0,S);
        return result;
    }
    
    void subsetsHelper(vector<vector<int> > &result, vector<int> &cur, int pos, vector<int> &S)
    {
        result.push_back(cur);
        for (int i = pos; i<S.size(); i++)
        {
            cur.push_back(S[i]);
            subsetsHelper(result,cur,i+1,S);
            cur.pop_back();
        }
    }

};


int main() {

    const int s = 3;
    int myArr[s] = {1, 2, 3};
    vector<int> myv;

    myv.assign(myArr, myArr+s);
    cout << "Size of myv: " << int (myv.size()) << endl;
    sort(myv.begin(), myv.end());

    Solution mySol;
    vector<vector<int> > ss = mySol.subsets(myv);

    vector<vector<int> >::iterator it;
    vector<int>::iterator is;
    for(it = ss.begin(); it != ss.end(); it++) {
        for(is = (*it).begin(); is != (*it).end(); is++) {
            cout << *is << "  ";
        }
        cout << endl;
    }


    return 0;
}
